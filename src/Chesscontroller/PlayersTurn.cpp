
#include "Chesscontroller/PlayersTurn.hpp"

PlayersTurn::PlayersTurn(const std::string& PlayerColor, const std::string& OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor)
{
    Logger::Log(logging::trivial::debug, log_location, "players turn: " , PlayerColor);
}

PlayersTurn::PlayersTurn(std::shared_ptr<Chesscontroller>& chesscontroller, const std::string& PlayerColor, const std::string& OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor)
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

void PlayersTurn::selectPiece(std::shared_ptr<Chesscontroller>& chesscontroller, std::shared_ptr<Entity> piece, std::string color)
{
    if (color.compare(playerColor) == 0)
    {
        chesscontroller->SetSelectedPiece(piece);
        chesscontroller->ResetValidation();

        auto next = std::make_unique<Validate>(playerColor, opponentColor);
        chesscontroller->SetState(std::move(next));
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
            auto next = std::make_unique<PlayersTurn>(chesscontroller, opponentColor, playerColor);
            chesscontroller->SetState(std::move(next));
        }
    }
}