
#include "Chesscontroller/Validate.hpp"
#include "Chesscontroller/PlayersTurn.hpp"

#include "Movements/Movements.hpp"


void Validate::UpdateGame(Chesscontroller* chesscontroller)
{
    auto [piece, color] = chesscontroller->GetSelectedPieceAndColor();

    MovementFactory::Create(piece);
    
    //TODO get back to the player turn who just turn it was
    PlayersTurn* next = new PlayersTurn("white", "black");
    chesscontroller->SetState(next);
    delete this;
}

