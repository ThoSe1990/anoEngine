
#include "Chesscontroller/PlayersTurn.hpp"

PlayersTurn::PlayersTurn(std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor), pieceSelected(false)
{
    Logger::Log(logging::trivial::debug, log_location, "players turn: " , PlayerColor);
}

PlayersTurn::PlayersTurn(Chesscontroller* chesscontroller, std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor)
{
    Logger::Log(logging::trivial::debug, log_location, "players turn: " , PlayerColor);

    auto [selected, color] = chesscontroller->GetSelectedPieceAndColor();

    this->pieceSelected = (color.compare(playerColor) == 0 && selected) ? true : false; 
}



void PlayersTurn::UpdateGame(Chesscontroller* chesscontroller)
{
    if (chesscontroller->GetMouseClick())
    {
        auto [piece, color] = chesscontroller->GetClickedPieceAndColor();

        if (color.compare(playerColor) == 0)
        {
            chesscontroller->SetSelectedPiece(piece);
            chesscontroller->ResetValidation();
            pieceSelected = true;

            Validate* next = new Validate(playerColor, opponentColor);
            chesscontroller->SetState(next);
            delete this;
        }
        else if (color.compare(opponentColor) == 0)
        {
            // TODO: validate if possible
            // move and cick
        }
        else if (pieceSelected)
        {
            // TODO: validate if possible
            // move
            if (chesscontroller->MoveSelectedPiece())
            {
                chesscontroller->ResetValidation();
                PlayersTurn* next = new PlayersTurn(chesscontroller, opponentColor, playerColor);
                chesscontroller->SetState(next);
                delete this;
            }
        }
    }
}
