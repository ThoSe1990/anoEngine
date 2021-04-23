
#include "ezEngine.hpp"

#include "Chess.hpp"
#include "Chessboard.hpp"
#include "PlayersTurn.hpp"

#include "Movements/MovementsFactory.hpp"

std::vector<std::shared_ptr<Chesspiece>> Chess::AllPieces;
std::unordered_map<std::string, Entity> Chess::validMoves;
std::shared_ptr<Chesspiece> Chess::selectedPiece;

void Chess::Initialize()
{
    ezEngine::Initialize_sdl();
    initializeLua();
    loadAssets();
    ezEngine::Initialize(); // init systems

    chessboard = std::make_shared<Chessboard>();
    chessboard->Init();

    loadPieces();
    setInitialGameState();
}


void Chess::initializeLua()
{
    lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);
    lua.script_file("./assets/scripts/config.lua");

    sol::optional<int> chespieces_velocity_exists = lua["config"]["chespieces_velocity"];
    Constants::chespieces_velocity = (chespieces_velocity_exists == sol::nullopt) ? Constants::chespieces_velocity : lua["config"]["chespieces_velocity"];

    sol::optional<int> chessboard_offset_exists = lua["config"]["chessboard_offset"];
    Constants::chessboard_offset = (chessboard_offset_exists == sol::nullopt) ? Constants::chessboard_offset : lua["config"]["chessboard_offset"];
}

void Chess::loadAssets()
{
    lua.script_file("./assets/scripts/assets.lua");
    sol::table chessboardAssets = lua["chessboard_assets"];

    unsigned int index = 0;
    while (true)
    {
        sol::optional<sol::table> exists = chessboardAssets[index];
        if (exists == sol::nullopt)
            break;
        sol::table asset = chessboardAssets[index];
        std::string type = asset["type"];
        if (type.compare("texture") == 0)
        {
            std::string id = asset["id"];
            std::string file = asset["file"];  
            ezEngine::AddTexture(id, file.c_str());
        }
        index++;
    }
}
void Chess::Update()
{
    ezEngine::Update();
    if (ezEngine::MouseClicked())
    {               
        auto next = this->currentState->UpdateGame();
        SetState(std::move(next));
        updateValidation();
        updatePieces();
    }
}

void Chess::Render()
{
    
}

void Chess::SetSelectedPiece(std::shared_ptr<Chesspiece> cp)
{
    std::cout << "setting: " << cp->type << " owner: " << cp->owner << std::endl;
    selectedPiece = cp;
}

std::shared_ptr<Chesspiece> Chess::GetSelectedPiece()
{
    return selectedPiece;
}

void Chess::SetState(std::unique_ptr<State> state)
{
    if (state)
        this->currentState = std::move(state);
}

void Chess::setInitialGameState()
{
    sol::optional<std::string> chespieces_velocity_exists = lua["next_turn"];
    std::string startingColor = lua["next_turn"];    
    std::string opponentsColor = (startingColor.compare(Constants::color_black) == 0) ? Constants::color_white : Constants::color_black;

    auto initialState = std::make_unique<PlayersTurn>(startingColor, opponentsColor);
    this->SetState(std::move(initialState));
}

void Chess::loadPieces()
{
    lua.script_file("./assets/scripts/default_setup.lua");
    sol::table chessboardSetup = lua["chessboard_setup"];

    unsigned int index = 0;
    while (true)
    {
        sol::optional<sol::table> exists = chessboardSetup[index];
        if (exists == sol::nullopt)
            break;
        sol::table chesspiece = chessboardSetup[index];
        std::string name = chesspiece["name"];
        std::string type = chesspiece["type"];
        std::string color = chesspiece["color"];
        bool captured = chesspiece["captured"];
        std::stringstream asset_id;
        asset_id << color << '_' << type;
        std::string position = chesspiece["position"];


        auto coordinates = Chessboard::GetCoordinatesFromSquare(position);
        auto newEntity = ezEngine::CreateEntity();
        ezEngine::Create_TransformComponent(newEntity, 
            coordinates.x,
            coordinates.y,
            Constants::chesspiece_sidelength,
            Constants::chesspiece_sidelength,
            Constants::chespieces_velocity,
            Constants::scale
        );

        ezEngine::Create_SpriteComponent(newEntity,
            asset_id.str(),
            ezEngine::Rectangle{0, 0, Constants::chesspiece_sidelength, Constants::chesspiece_sidelength},
            ezEngine::Rectangle{static_cast<int>(coordinates.x), static_cast<int>(coordinates.y), Constants::chesspiece_sidelength, Constants::chesspiece_sidelength},
            Layer::layer_1 
        );
        
        
        AllPieces.push_back(std::make_shared<Chesspiece>(newEntity, color, type, position, captured, 0));

        index++;
    }
}


void Chess::updatePieces()
{

    for (const auto& piece : AllPieces)
    {
        auto position = Chessboard::GetCoordinatesFromSquare(piece->square);
        ezEngine::SetPosition_TransformComponent(piece->owner, position.x, position.y);
    }     
}

void Chess::updateValidation()
{
    for (const auto& e : validMoves)
        ezEngine::Remove_SpriteComponent(e.second);

    validMoves.clear();

    if (!selectedPiece) return;

    auto movements = MovementFactory::Create(selectedPiece->owner);   
    movements->CreateValidMovements();
}

bool Chess::MovePiece(const std::string& toSquare)
{
    if (isValidMove(toSquare))
    {
        captureOpponent(toSquare);
        selectedPiece->square = toSquare;
        selectedPiece->movesCount++;
        selectedPiece = nullptr;
        return true;
    }
    return false;
}

void Chess::MovePiece(const std::string& fromSquare, const std::string& toSquare)
{   
    auto cp = GetChesspieceFromSquare(fromSquare);
    if (cp)
    {
        cp->square = toSquare;
        cp->movesCount++;
    }
}

std::shared_ptr<Chesspiece> Chess::GetChesspieceFromSquare(const std::string& square)
{   
    auto lambda = [&square](const auto current)
    {
        return (current->square.compare(square) == 0);
    };

    auto it = std::find_if(Chess::AllPieces.begin(), Chess::AllPieces.end(), lambda);
    return (it != Chess::AllPieces.end()) ? (*it) : nullptr;
}

void Chess::doCastle()
{
    
}

bool Chess::isValidMove(const std::string& toSquare)
{
    auto desiredSquare = validMoves.find(toSquare);
    return desiredSquare != validMoves.end() ;
}

void Chess::captureOpponent(const std::string& square)
{

    auto opponent = GetChesspieceFromSquare(square);

    if (!opponent) return;

    ezEngine::Remove_SpriteComponent(opponent->owner);
    ezEngine::Remove_TransformComponent(opponent->owner);

    auto it = std::find_if(AllPieces.begin(), AllPieces.end(), [&opponent](const auto& current){
        return opponent->owner == current->owner;
    });
    
    if (it != AllPieces.end())
        AllPieces.erase(it);

}