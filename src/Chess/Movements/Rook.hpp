#ifndef _MOVEMENTS_ROOK_HPP_
#define _MOVEMENTS_ROOK_HPP_

#include "Movements/Movements.hpp" 

class Rook : public Movement
{
public:
    Rook(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {
        createMovesAndCaptures(Movements::none, Movements::up);
        createMovesAndCaptures(Movements::right, Movements::none);
        createMovesAndCaptures(Movements::none, Movements::down);
        createMovesAndCaptures(Movements::left, Movements::none);
    }

};

#endif