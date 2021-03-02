
#include "ChessController.hpp"


ChessController::ChessController(std::vector<Entity*> ChessPieces) : chessPieces(ChessPieces)
{ 

}

void ChessController::SetMousebutton(bool mousebutton)
{
    mouseButtonPressed = mousebutton;
}

void ChessController::SetMousePosition(int x, int y)
{
    mousePosition.x = x;
    mousePosition.y = y;
}

void ChessController::UpdateGame ()  
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
            if (!SquareOccupied(square))
            {
                tc->SetPosition(square);
            }
        }  

    }
} 

bool ChessController::SquareOccupied(std::string square)
{
    for (const auto& piece : chessPieces)
    {
        if (piece->GetComponent<TransformComponent>()->square.compare(square) == 0)
            return true;
    }
    return false;
}


