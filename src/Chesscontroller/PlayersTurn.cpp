
#include "Chesscontroller/PlayersTurn.hpp"

PlayersTurn::PlayersTurn(std::shared_ptr<Chesscontroller>& Chesscontroller, const std::string& PlayerColor, const std::string& OpponentColor) : State(Chesscontroller, PlayerColor, OpponentColor)
{
    Logger::Log(logging::trivial::debug, log_location, "players turn: " , PlayerColor);
}

void PlayersTurn::UpdateGame()
{
    if (chesscontroller->GetMouseClick())
    {
        auto [clickedPiece, clickedColor, clickedSquare] = chesscontroller->GetClickedPieceColorSquare();

        if (clickedPiece && clickedColor.compare(playerColor) == 0)
        {
            this->selectPiece(clickedPiece);
        }
        else if (chesscontroller->IsValidMove(clickedSquare))
        {
            chesscontroller->MoveSelectedPiece();
            chesscontroller->ResetValidation();

            auto next = std::make_unique<PlayersTurn>(chesscontroller, opponentColor, playerColor);
            chesscontroller->SetState(std::move(next));
        } 
    }
}

void PlayersTurn::selectPiece(std::shared_ptr<Entity> piece)
{
    chesscontroller->SetSelectedPiece(piece);
    chesscontroller->ResetValidation();

    auto next = std::make_unique<Validate>(chesscontroller, playerColor, opponentColor);
    chesscontroller->SetState(std::move(next));

}

void PlayersTurn::pawnPromotion()
{

}
// void PlayersTurn::castling() 
// {

// }
// void PlayersTurn::enPassante()
// {

// }