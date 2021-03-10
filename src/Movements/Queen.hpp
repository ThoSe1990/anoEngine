#ifndef _MOVEMENTS_QUEEN_HPP_
#define _MOVEMENTS_QUEEN_HPP_

#include "Movements/Movements.hpp" 

class Queen : public Movement
{

public:
    Queen(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {
        createMovesAndCaptures(Movements::up, Movements::none);
        createMovesAndCaptures(Movements::none, Movements::right);
        createMovesAndCaptures(Movements::down, Movements::none);
        createMovesAndCaptures(Movements::none, Movements::left);
        createMovesAndCaptures(Movements::up, Movements::right);
        createMovesAndCaptures(Movements::down, Movements::right);
        createMovesAndCaptures(Movements::down, Movements::left);
        createMovesAndCaptures(Movements::up, Movements::left);
    }

};

#endif