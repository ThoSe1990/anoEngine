#ifndef _MOVEMENTS_QUEEN_HPP_
#define _MOVEMENTS_QUEEN_HPP_

#include "Movements/Movements.hpp" 

class Queen : public Movement
{

public:
    Queen(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {
        createMovesAndCaptures(Movements::none, Movements::up);
        createMovesAndCaptures(Movements::right, Movements::none);
        createMovesAndCaptures(Movements::none, Movements::down);
        createMovesAndCaptures(Movements::left, Movements::none);
        createMovesAndCaptures(Movements::right, Movements::up);
        createMovesAndCaptures(Movements::right, Movements::down);
        createMovesAndCaptures(Movements::left, Movements::down);
        createMovesAndCaptures(Movements::left, Movements::up);
    }

};

#endif