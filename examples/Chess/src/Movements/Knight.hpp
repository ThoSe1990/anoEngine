#ifndef _CHESS_MOVEMENTS_KNIGHT_HPP_
#define _CHESS_MOVEMENTS_KNIGHT_HPP_

#include "Movements/Movement.hpp" 

class Knight : public Movement
{

    void createMovement(const int x1, const int x2, const int y1, const int y2)
    {
        std::string next = chesspiece->square;
        next[Movements::x] += x1; 
        next[Movements::x] += x2;
        next[Movements::y] += y1; 
        next[Movements::y] += y2; 

        if (Chessboard::IsValidSquare(next))
        {
            createValidation(next);
        }

    }

public:
    Knight(const std::shared_ptr<Chesspiece>& Chesspiece) : Movement(Chesspiece) { }

    void CreateValidMovements() override
    {        
        createMovement(Movements::left, Movements::none, Movements::up, Movements::up);
        createMovement(Movements::right, Movements::none, Movements::up, Movements::up);

        createMovement(Movements::right, Movements::right, Movements::up, Movements::none);
        createMovement(Movements::right, Movements::right, Movements::down, Movements::none);

        createMovement(Movements::left, Movements::none, Movements::down, Movements::down);
        createMovement(Movements::right, Movements::none, Movements::down, Movements::down);

        createMovement(Movements::left, Movements::left, Movements::up, Movements::none);
        createMovement(Movements::left, Movements::left, Movements::down, Movements::none);
    }
};

#endif