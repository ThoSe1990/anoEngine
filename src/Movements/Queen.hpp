#ifndef _MOVEMENTS_QUEEN_HPP_
#define _MOVEMENTS_QUEEN_HPP_

#include "Movements/Movements.hpp" 

class Queen : public Movement
{

public:
    Queen(Chesscontroller* Chesscontroller, Entity* CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {
        createMovesAndCaptures(playersPosition, Movements::up, Movements::none);
        createMovesAndCaptures(playersPosition, Movements::none, Movements::right);
        createMovesAndCaptures(playersPosition, Movements::down, Movements::none);
        createMovesAndCaptures(playersPosition, Movements::none, Movements::left);
        createMovesAndCaptures(playersPosition, Movements::up, Movements::right);
        createMovesAndCaptures(playersPosition, Movements::down, Movements::right);
        createMovesAndCaptures(playersPosition, Movements::down, Movements::left);
        createMovesAndCaptures(playersPosition, Movements::up, Movements::left);
    }

};

#endif