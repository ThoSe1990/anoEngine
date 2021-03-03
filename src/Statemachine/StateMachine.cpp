
#include "Statemachine/Statemachine.hpp"
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
    currentState = state;
}

void Statemachine::CallSelect()
{
    currentState->Select(this);
}

void Statemachine::CallMove()
{
    currentState->Move(this);
}

void Statemachine::ProcessMouseclick()
{

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

void Statemachine::SetSelectedPiece()
{

}

Entity* Statemachine::GetEntityFromSquare(std::string square)
{
    for (const auto& piece : chessPieces)
    {
        TransformComponent* transform = piece->GetComponent<TransformComponent>();
        if (transform->square.compare(square) == 0)
        {
            return piece;
        }
    } 
    return nullptr;
}

void Statemachine::UpdateStatemachine ()  
{
    std::string square = ChessBoard::GetSquareTitleByCoordinates(glm::vec2( static_cast<int>(mousePosition.x),static_cast<int>(mousePosition.y) ));
    currentState->SetSelectedPiece(this, square);
} 
