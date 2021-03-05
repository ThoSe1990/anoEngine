
#include "Statemachine/Statemachine.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/ChesspieceComponent.hpp"

#include "ChessBoard.hpp"

Statemachine::Statemachine(State* state, std::vector<Entity*> ChessPieces) : currentState(state), chessPieces(ChessPieces)
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

