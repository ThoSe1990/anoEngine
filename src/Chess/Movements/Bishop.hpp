#ifndef _MOVEMENTS_BISHOP_HPP_
#define _MOVEMENTS_BISHOP_HPP_

#include "Movements/Movements.hpp" 

class Bishop : public Movement
{
public:
    Bishop(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {
        createMovesAndCaptures(Movements::right, Movements::up);
        createMovesAndCaptures(Movements::right, Movements::down);
        createMovesAndCaptures(Movements::left, Movements::down);
        createMovesAndCaptures(Movements::left, Movements::up);
    }
};

#endif