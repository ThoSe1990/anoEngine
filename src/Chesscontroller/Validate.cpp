
#include "Chesscontroller/Validate.hpp"
#include "Chesscontroller/PlayersTurn.hpp"

#include "Movements/Movements.hpp"

Validate::Validate (std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor)
{

}

void Validate::UpdateGame(Chesscontroller* chesscontroller)
{
    auto [piece, color] = chesscontroller->GetSelectedPieceAndColor();

    MovementFactory::Create(piece);

    PlayersTurn* next = new PlayersTurn(chesscontroller, playerColor, opponentColor);
    chesscontroller->SetState(next);
    delete this;
}

