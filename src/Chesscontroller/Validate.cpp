
#include "Chesscontroller/Validate.hpp"
#include "Chesscontroller/PlayersTurn.hpp"

#include "Movements/Movements.hpp"

Validate::Validate (std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor)
{

}

void Validate::UpdateGame(Chesscontroller* chesscontroller)
{
    auto [piece, color] = chesscontroller->GetSelectedPieceAndColor();

    auto movements = MovementFactory::Create(piece);
    std::map<std::string, std::string> possibleMoves = movements->GetMovements(piece);

    for (const auto& m : possibleMoves)
        chesscontroller->SetValidation(m.first, m.second);
    

    PlayersTurn* next = new PlayersTurn(chesscontroller, playerColor, opponentColor);
    chesscontroller->SetState(next);
    delete this;
}

