
#include "Chesscontroller/PlayersTurn.hpp"



void PlayersTurn::UpdateGame(Chesscontroller* chesscontroller)
{
    if (chesscontroller->GetMouseClick())
    {
        auto [piece, color] = chesscontroller->GetClickedPieceAndColor();

        //TODO: Refactor in deciated states (??)
        if (color.compare(playerColor) == 0)
        {
            std::cout << "click on player color " << std::endl;
            chesscontroller->SetSelectedPiece(piece);
            pieceSelected = true;

            Validate* next = new Validate();
            chesscontroller->SetState(next);
            delete this;

            // chesscontroller->SetValidation("H5", "validation_circle");
            // chesscontroller->SetValidation("G5", "validation_splash");
        }
        else if (color.compare(opponentColor) == 0)
        {
            std::cout << "click on opponentColor color " << std::endl;
            // TODO: validate if possible
            // move and cick
        }
        else if (pieceSelected)
        {
            // TODO: validate if possible
            // move
            if (chesscontroller->MoveSelectedPiece())
            {
                std::cout << "piece moved " << std::endl;

                PlayersTurn* next = new PlayersTurn(opponentColor, playerColor);
                chesscontroller->SetState(next);
                delete this;
            }
        }
    }
}
