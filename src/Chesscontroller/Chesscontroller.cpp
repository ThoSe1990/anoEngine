
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


std::tuple<Entity*, std::string> Chesscontroller::GetClickedPieceAndColor() const
{
    std::string color = "";
    auto piece = this->getClickedEntity();
    if (piece)
        color = this->getColorOfPiece(piece);

    return std::make_tuple(piece, color);
}
std::tuple<Entity*, std::string> Chesscontroller::GetSelectedPieceAndColor() const
{
    std::string color = "";

    if (selectedPiece)
        color = this->getColorOfPiece(selectedPiece);

    return std::make_tuple(selectedPiece, color);
}


Entity* Chesscontroller::getClickedEntity() const
{
    for (const auto& piece : chessPieces)
    {
        TransformComponent* transform = piece->GetComponent<TransformComponent>();
        if (transform->square.compare(clickedSquare) == 0 && piece->IsActive())
            return piece;
    } 
    return nullptr;
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