#ifndef _MOVEMENTS_KING_HPP_
#define _MOVEMENTS_KING_HPP_

#include "Movements/Movements.hpp" 

class King : public Movement
{
private:

public:
    King(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {

    }

};

#endif