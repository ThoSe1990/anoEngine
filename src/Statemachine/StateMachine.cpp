
#include "Statemachine/Statemachine.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/ChesspieceComponent.hpp"
#include "Components/ValidationComponent.hpp"


#include "ChessBoard.hpp"

Statemachine::Statemachine(State* state, std::vector<Entity*> ChessPieces, std::vector<Entity*> ValidationEntities) 
: currentState(state),
 chessPieces(ChessPieces),
 validationEntities(ValidationEntities)
{

}  

Statemachine::~Statemachine()
{
    delete currentState;
}

void Statemachine::SetState(State* state) 
{
    this->currentState = state;
}

void Statemachine::NextGamestep()
{
    runGameStep = true;
}

void Statemachine::Update()
{
    if (runGameStep)
    {
        this->currentState->UpdateGame(this);
        runGameStep = false;
    }
    
}

void Statemachine::SetSelectedPiece(Entity* entity)
{
    Logger::Log(logging::trivial::debug, log_location, "Selected: " , entity->name);
    this->selectedPiece = entity;
}



void Statemachine::SetClickedSquare(int x, int y)
{
    clickedSquare = ChessBoard::GetSquareTitleByCoordinates( glm::vec2(x,y) );
}


std::tuple<Entity*, std::string> Statemachine::GetClickedntityAndColor() const
{
    std::string color = "";
    auto piece = this->getClickedEntity();
    if (piece)
        color = this->getColorOfPiece(piece);

    return std::make_tuple(piece, color);
}


Entity* Statemachine::getClickedEntity() const
{
    for (const auto& piece : chessPieces)
    {
        TransformComponent* transform = piece->GetComponent<TransformComponent>();
        if (transform->square.compare(clickedSquare) == 0 && piece->IsActive())
            return piece;
    } 
    return nullptr;
}
bool Statemachine::MoveSelectedPiece()
{
    TransformComponent* tc = this->selectedPiece->GetComponent<TransformComponent>();
    return tc->SetPosition(clickedSquare);
}

std::string Statemachine::getColorOfPiece(Entity* piece) const
{
    ChesspieceComponent* c = piece->GetComponent<ChesspieceComponent>();
    return c->color_;
}

void Statemachine::ResetValidation()
{
    for (auto& entity : validationEntities)
        entity->Deactivate();
} 

void Statemachine::SetValidation(std::string square, std::string assetId)
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