#ifndef _MOVEMENTS_ROOK_HPP_
#define _MOVEMENTS_ROOK_HPP_

#include "Movements/Movements.hpp" 

class Rook : public Movement
{
public:
    Rook(std::shared_ptr<Chesscontroller>& Chesscontroller, Entity* CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {
        createMovesAndCaptures(Movements::up, Movements::none);
        createMovesAndCaptures(Movements::none, Movements::right);
        createMovesAndCaptures(Movements::down, Movements::none);
        createMovesAndCaptures(Movements::none, Movements::left);
    }

};

#endif