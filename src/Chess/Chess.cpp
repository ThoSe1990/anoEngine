
#include <SDL2/SDL.h>


#include "Chess/Chess.hpp"
#include "Chess/Chessboard.hpp"
#include "Chess/PlayersTurn.hpp"
#include "Systems/SpriteSystem.hpp"

#include "Chess/Movements/MovementsFactory.hpp"


std::shared_ptr<ChesspieceComponent> Chess::selectedPiece;

void Chess::Initialize()
{

    lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);

    chessboard = std::make_shared<Chessboard>();
    chessboard->Init();

    loadPieces();
    setInitialGameState();

    // auto& components = Components::GetInstance();
    // auto sortLayerAscending = [](const auto& lhs, const auto& rhs)
    // {
    //     return static_cast<int>(lhs->layer) < static_cast<int>(rhs->layer);
    // };
    // components.SpriteManager->SortComponents(sortLayerAscending);
}

void Chess::Update(float deltaTime)
{
    if (Game::userInputs->GetClick())
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

void Chess::SetSelectedPiece(std::shared_ptr<ChesspieceComponent> cp)
{
    selectedPiece = cp;
}

std::shared_ptr<ChesspieceComponent> Chess::GetSelectedPiece()
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

        auto newEntity = System::AddEntity(); 
        auto& components = Components::GetInstance();
    
        auto transform = components.TransformManager->Create(newEntity, 
            Chessboard::GetCoordinatesFromSquare(position),
            Constants::chesspiece_sidelength,
            Constants::chesspiece_sidelength,
            Constants::scale
        );

        components.SpriteManager->Create(newEntity,
            Game::assetManager->GetTexture(asset_id.str().c_str()),
            SDL_Rect{0, 0, Constants::chesspiece_sidelength, Constants::chesspiece_sidelength},
            SDL_Rect{static_cast<int>(transform->setPosition.x), static_cast<int>(transform->setPosition.y), transform->width, transform->height},
            Layer::layer_1
        );
        
        components.ChesspieceManager->Create(newEntity,
            color,
            type,
            position,
            captured,
            0
        );
        
        index++;
    }
}




void Chess::updatePieces()
{
    auto& components = Components::GetInstance();

    for (size_t i = 0 ; i<components.ChesspieceManager->GetCount() ; i++)
    {
        auto current = components.ChesspieceManager->at(i);

        if (components.TransformManager->Has(current->owner))
        {
            auto transform = components.TransformManager->GetComponent(current->owner);
            transform->setPosition = Chessboard::GetCoordinatesFromSquare(current->square);;
        }

        auto chesspiece = current;
        if (chesspiece)
        {   
            auto t1 = components.TransformManager->GetComponent(chesspiece->owner);
            auto t2 = components.SpriteManager->GetComponent(chesspiece->owner);
            auto t3 = components.ChesspieceManager->GetComponent(chesspiece->owner);   

            std::cout << "updating: "  << current->owner << ' '<< t1->owner << ' ' << t2->owner << ' ' << t3->owner << ' '<< std::endl;
        }
    }     
     
}

void Chess::updateValidation()
{

    auto& components = Components::GetInstance();
    auto lambda = [](const auto current)
    {
        return (current->layer == Layer::layer_2);
    };

    while (auto c = components.SpriteManager->GetComponent(lambda))
    {
        components.SpriteManager->Remove(c->owner);
    }

    if (!selectedPiece)
        return;

    auto movements = MovementFactory::Create(selectedPiece->owner);   
    movements->CreateValidMovements();
}

bool Chess::MovePiece(const std::string& toSquare)
{

    if (isValidMove(toSquare))
    {
        captureOpponent(toSquare);
        Logger::Log(logging::trivial::debug, log_location, "moving: " ,  selectedPiece->color, '-', selectedPiece->type , " from " , selectedPiece->square , "->" , toSquare);
        selectedPiece->square = toSquare;
        selectedPiece->movesCount++;
        selectedPiece = nullptr;
        return true;
    }
    return false;
}

bool Chess::isValidMove(const std::string& toSquare)
{
    auto isValidSquare = [&toSquare](const auto& current)
    {
        std::string currentSquare = Chessboard::GetSquareTitleByCoordinates(glm::vec2(current->destination.x, current->destination.y));
        return (current->layer == Layer::layer_2 && currentSquare.compare(toSquare) == 0) ? true : false;
    };

    auto& components = Components::GetInstance();
    auto result = components.SpriteManager->GetComponent(isValidSquare);

    return (result) ? true : false;
}

void Chess::captureOpponent(const std::string& square)
{
    auto findOpponent = [&square](const auto& current)
    {
        return (current->square.compare(square) == 0) ? true : false;
    };

    auto& components = Components::GetInstance();
    auto chesspiece = components.ChesspieceManager->GetComponent(findOpponent);
    if (chesspiece)
    {    
        components.TransformManager->Remove(chesspiece->owner);
        components.SpriteManager->Remove(chesspiece->owner);
        components.ChesspieceManager->Remove(chesspiece->owner);
    }
}