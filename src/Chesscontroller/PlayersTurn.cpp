
#include "Chesscontroller/PlayersTurn.hpp"

PlayersTurn::PlayersTurn(std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor)//, pieceSelected(false)
{
    Logger::Log(logging::trivial::debug, log_location, "players turn: " , PlayerColor);
}

PlayersTurn::PlayersTurn(std::shared_ptr<Chesscontroller>& chesscontroller, std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor)
{
    Logger::Log(logging::trivial::debug, log_location, "players turn: " , PlayerColor);
}


void PlayersTurn::UpdateGame(std::shared_ptr<Chesscontroller> chesscontroller)
{
    if (chesscontroller->GetMouseClick())
    {
        auto [piece, color, square] = chesscontroller->GetClickedPieceColorSquare();

        this->selectPiece(chesscontroller, piece, color);
        this->movePiece(chesscontroller, square);
    }
}

void PlayersTurn::selectPiece(std::shared_ptr<Chesscontroller>& chesscontroller, Entity* piece, std::string color)
{
    if (color.compare(playerColor) == 0)
    {
        chesscontroller->SetSelectedPiece(piece);
        chesscontroller->ResetValidation();

        Validate* next = new Validate(playerColor, opponentColor);
        chesscontroller->SetState(next);
        delete this;
    }
}

void PlayersTurn::movePiece(std::shared_ptr<Chesscontroller>& chesscontroller, std::string square)
{
    if (chesscontroller->IsValidMove(square))
    {
        chesscontroller->CaptureOpponent(square);

        if (chesscontroller->MoveSelectedPiece())
        {
            chesscontroller->ResetValidation();
            PlayersTurn* next = new PlayersTurn(chesscontroller, opponentColor, playerColor);
            chesscontroller->SetState(next);
            delete this;
        }
    }
}