
#include "Chesscontroller/Validate.hpp"
#include "Chesscontroller/PlayersTurn.hpp"

#include "Movements/MovementsFactory.hpp"

Validate::Validate (std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor)
{

}

void Validate::UpdateGame(std::shared_ptr<Chesscontroller> chesscontroller)
{
    Entity* piece = chesscontroller->GetSelectedPiece();
    auto movements = MovementFactory::Create(chesscontroller, piece);
    movements->CreateValidMovements();

    PlayersTurn* next = new PlayersTurn(chesscontroller, playerColor, opponentColor);
    chesscontroller->SetState(next);
    delete this;
}

