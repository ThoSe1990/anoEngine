#ifndef _MOVEMENTS_KNIGHT_HPP_
#define _MOVEMENTS_KNIGHT_HPP_

#include "Movements/Movements.hpp" 

class Knight : public Movement
{
private:

public:
    Knight(Chesscontroller* Chesscontroller, Entity* CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {

    }

};

#endif