#ifndef _MOVEMENTS_ROOK_HPP_
#define _MOVEMENTS_ROOK_HPP_

#include "Movements/Movements.hpp" 

class Rook : public Movement
{
public:
    Rook(Chesscontroller* Chesscontroller, Entity* CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {
        createMovesAndCaptures(playersPosition, Movements::up, Movements::none);
        createMovesAndCaptures(playersPosition, Movements::none, Movements::right);
        createMovesAndCaptures(playersPosition, Movements::down, Movements::none);
        createMovesAndCaptures(playersPosition, Movements::none, Movements::left);
    }

};

#endif