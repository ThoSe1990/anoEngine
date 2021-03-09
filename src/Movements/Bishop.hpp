#ifndef _MOVEMENTS_BISHOP_HPP_
#define _MOVEMENTS_BISHOP_HPP_

#include "Movements/Movements.hpp" 

class Bishop : public Movement
{
public:
    Bishop(Chesscontroller* Chesscontroller, Entity* CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {
        createMovesAndCaptures(playersPosition, Movements::up, Movements::right);
        createMovesAndCaptures(playersPosition, Movements::down, Movements::right);
        createMovesAndCaptures(playersPosition, Movements::down, Movements::left);
        createMovesAndCaptures(playersPosition, Movements::up, Movements::left);
    }
};

#endif