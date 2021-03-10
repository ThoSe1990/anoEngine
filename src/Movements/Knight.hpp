#ifndef _MOVEMENTS_KNIGHT_HPP_
#define _MOVEMENTS_KNIGHT_HPP_

#include "Movements/Movements.hpp" 

class Knight : public Movement
{

public:
    Knight(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {

    }
};

#endif