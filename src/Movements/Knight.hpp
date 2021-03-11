#ifndef _MOVEMENTS_KNIGHT_HPP_
#define _MOVEMENTS_KNIGHT_HPP_

#include "Movements/Movements.hpp" 

class Knight : public Movement
{

    void evaluateSquare(const std::string& square)
    {
        auto squarestate = chesscontroller->GetSquareState(square, playerColor);

        if (squarestate == SquareState::free)
        {
            chesscontroller->SetValidation(square, "valid_move");
        }
        else if (squarestate == SquareState::occupied_by_opponent)
        {
            chesscontroller->SetValidation(square, "valid_capture");    
        }
    }

// TODO refactor
    void createMovement(const int x1, const int x2, const int y1, const int y2)
    {
        std::string next = playerPosition;
        next[Movements::x] += x1; 
        next[Movements::x] += x2;
        next[Movements::y] += y1; 
        next[Movements::y] += y2; 
        evaluateSquare(next);
    }

public:
    Knight(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

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