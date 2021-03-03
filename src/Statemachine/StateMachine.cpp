
#include "Statemachine/Statemachine.hpp"
#include "Components/TransformComponent.hpp"
#include "ChessBoard.hpp"

Statemachine::Statemachine(State* state, std::vector<Entity*> ChessPieces) : currentState(state), chessPieces(ChessPieces)
{

}  

Statemachine::~Statemachine()
{
    delete currentState;
}

void Statemachine::SetCurrentState(State* state) 
{
    this->rdyToMove = false;
    this->currentState = state;
}


void Statemachine::SetMousebutton(bool mousebutton)
{
    mouseButtonPressed = mousebutton;
}

void Statemachine::SetMousePosition(int x, int y)
{
    mousePosition.x = x;
    mousePosition.y = y;
}


tuple<Entity*, bool> Statemachine::GetEntityFromSquare(std::string square)
{
    Entity* entity;
    bool valid = false;
    for (const auto& piece : chessPieces)
    {
        TransformComponent* transform = piece->GetComponent<TransformComponent>();
        if (transform->square.compare(square) == 0)
        {
            valid = true;
            entity = piece;
            break;
        }
    } 
    return std::make_tuple(entity, valid);
}

void Statemachine::UpdateStatemachine ()  
{

    //TODO: Refactor (e.g. introduce steps for player turn ... ) or validMove (in State) then ... 
    std::string square = ChessBoard::GetSquareTitleByCoordinates(glm::vec2( static_cast<int>(mousePosition.x),static_cast<int>(mousePosition.y) ));

    auto [entity, ChessPieceOnSquare] = this->GetEntityFromSquare(square);
    if (ChessPieceOnSquare)
    {
        currentState->SetSelectedPiece(this, entity);
        return;
    }
    
    if (this->rdyToMove) 
    {
        TransformComponent* tc = currentState->selected->GetComponent<TransformComponent>();
        tc->SetPosition(square);
        currentState->NextTurn(this);
    }
} 
