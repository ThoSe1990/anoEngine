#ifndef _MOVEMENTS_BISHOP_HPP_
#define _MOVEMENTS_BISHOP_HPP_

#include "Movements/Movements.hpp" 

class Bishop : public Movement
{
public:
    Bishop(std::shared_ptr<Chesscontroller>& Chesscontroller, Entity* CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {
        createMovesAndCaptures(Movements::up, Movements::right);
        createMovesAndCaptures(Movements::down, Movements::right);
        createMovesAndCaptures(Movements::down, Movements::left);
        createMovesAndCaptures(Movements::up, Movements::left);
    }
};

#endif