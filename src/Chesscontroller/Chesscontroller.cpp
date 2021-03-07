
#include "Chesscontroller/Chesscontroller.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/ChesspieceComponent.hpp"
#include "Components/ValidationComponent.hpp"


#include "ChessBoard.hpp"

Chesscontroller::Chesscontroller(State* state, std::vector<Entity*> ChessPieces, std::vector<Entity*> ValidationEntities) 
: currentState(state),
 chessPieces(ChessPieces),
 validationEntities(ValidationEntities)
{

}  

Chesscontroller::~Chesscontroller()
{
    delete currentState;
}

void Chesscontroller::SetState(State* state) 
{
    this->currentState = state;
}

void Chesscontroller::SetMouseClick()
{
    mouseClick = true;
}
bool Chesscontroller::GetMouseClick()
{
    return mouseClick;
}

void Chesscontroller::Update()
{
    this->currentState->UpdateGame(this);
    this->mouseClick = false;
}

void Chesscontroller::SetSelectedPiece(Entity* entity)
{
    Logger::Log(logging::trivial::debug, log_location, "Selected: " , entity->name);
    this->selectedPiece = entity;
}

void Chesscontroller::SetClickedSquare(int x, int y)
{
    clickedSquare = ChessBoard::GetSquareTitleByCoordinates( glm::vec2(x,y) );
}


std::tuple<Entity*, std::string, std::string> Chesscontroller::GetClickedPieceColorSquare() const
{
    std::string color = "";
    auto piece = this->getClickedEntity();
    if (piece)
        color = this->getColorOfPiece(piece);

    return std::make_tuple(piece, color, clickedSquare);
}

std::tuple<Entity*, std::string> Chesscontroller::GetPieceAndColor(std::string square) const
{
    std::string color = "";
    auto piece = this->GetEntityFromSqaure(square);
    if (piece)
    {
        color = this->getColorOfPiece(piece);
    }
    return std::make_tuple(piece, color);
}


std::tuple<Entity*, std::string> Chesscontroller::GetSelectedPieceAndColor() const
{
    std::string color = "";
    if (selectedPiece)
    {
        color = this->getColorOfPiece(selectedPiece);
    }
        
    return std::make_tuple(selectedPiece, color);
}


Entity* Chesscontroller::getClickedEntity() const
{
    return GetEntityFromSqaure(clickedSquare);
}

Entity* Chesscontroller::GetEntityFromSqaure(std::string square) const
{
    for (const auto& piece : chessPieces)
    {
        if (piece->HasComponent<TransformComponent>())
        {
            TransformComponent* transform = piece->GetComponent<TransformComponent>();
            if (transform->square.compare(square) == 0 && piece->IsActive())
                return piece;
        }
    } 
    return nullptr;
}

bool Chesscontroller::IsValidMove(std::string square)
{
    for (const auto& v : validationEntities)
    {
        if ( v->HasComponent<ValidationComponent>() )
        {
            ValidationComponent* vc = v->GetComponent<ValidationComponent>();
            if (square.compare( vc->GetTitle() ) == 0) 
                return v->IsActive();
        }
    }
    return false;
}

bool Chesscontroller::HasValidMoves()
{
    for (const auto& v : validationEntities)
        if (v->IsActive()) 
            return true;
    return false;
}

bool Chesscontroller::MoveSelectedPiece()
{
    TransformComponent* tc = this->selectedPiece->GetComponent<TransformComponent>();
    return tc->SetPosition(clickedSquare);
}

std::string Chesscontroller::getColorOfPiece(Entity* piece) const
{
    ChesspieceComponent* c = piece->GetComponent<ChesspieceComponent>();
    return c->color_;
}

void Chesscontroller::ResetValidation()
{
    for (auto& entity : validationEntities)
        entity->Deactivate();
} 

void Chesscontroller::SetValidation(std::string square, std::string assetId)
{
    for (auto& entity : validationEntities)
    {
        auto v = entity->GetComponent<ValidationComponent>();
        if (v->GetTitle().compare(square) == 0)
        {
            v->SetTextureId(assetId);
            entity->Activate();
        }
    }
}

std::string Chesscontroller::GetSquareFromEntity(Entity* entity) const
{
    if (entity->HasComponent<TransformComponent>())
    {
        TransformComponent* tc = entity->GetComponent<TransformComponent>();
        return tc->square;
    }
    return std::string("");
}

std::tuple<std::string, std::string> Chesscontroller::GetColorAndPosition(Entity* entity) const
{
    std::string color = "";
    if (entity->HasComponent<ChesspieceComponent>())
    {
        ChesspieceComponent* cp = entity->GetComponent<ChesspieceComponent>();
        color = cp->color_;
    }   
    std::string square = "";
    if (entity->HasComponent<TransformComponent>())
    {
        TransformComponent* tp = entity->GetComponent<TransformComponent>();
        square = tp->square;
    }
    return std::make_tuple(color, square);
}