
#include "Statemachine/Statemachine.hpp"


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

void Statemachine::SelectPiece()
{
    currentState->Select(this);
}

void Statemachine::MovePiece()
{
    currentState->Move(this);
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


void Statemachine::UpdateGame ()  
{
    //TODO: refactor
    if (mouseButtonPressed) 
    {
        std::string square = chessBoard->GetSquareTitleByCoordinates(glm::vec2( static_cast<int>(mousePosition.x),static_cast<int>(mousePosition.y) ));

        for (const auto& piece : chessPieces)
        {
            TransformComponent* transform = piece->GetComponent<TransformComponent>();
            ChesspieceComponent* chesspiece = piece->GetComponent<ChesspieceComponent>();
            if (transform->square.compare(square) == 0 && chesspiece->color_.compare("white") == 0)
            {
                selectedPiece = piece;
                return;
            }
        } 
        
        // moving selected piece --> click on square
        if (selectedPiece)
        {
            TransformComponent* tc = selectedPiece->GetComponent<TransformComponent>();
            tc->SetPosition(square);
            
        }  

    }
} 
