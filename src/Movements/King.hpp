#ifndef _MOVEMENTS_KING_HPP_
#define _MOVEMENTS_KING_HPP_

#include "Movements/Movements.hpp" 

class King : public Movement
{
private:
// TODO: refactore ... DRY (see base class)
    void createSingleStep(const int directionX, const int directionY)
    {
        std::string nextSquare = getNextSquare(playerPosition, directionX, directionY);

        auto squarestate = chesscontroller->GetSquareState(nextSquare, playerColor);

        if (squarestate == SquareState::free)
        {
            chesscontroller->SetValidation(nextSquare, "valid_move");
        }
        else if (squarestate == SquareState::occupied_by_opponent)
        {
            chesscontroller->SetValidation(nextSquare, "valid_capture");    
        }
    }

public:
    King(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : Movement(Chesscontroller, CurrentPiece) { }

    void CreateValidMovements() override
    {
        createSingleStep(Movements::none, Movements::up);
        createSingleStep(Movements::left, Movements::none);
        createSingleStep(Movements::right, Movements::none);
        createSingleStep(Movements::none, Movements::down);
        createSingleStep(Movements::left, Movements::up);
        createSingleStep(Movements::left, Movements::down);
        createSingleStep(Movements::right, Movements::up);
        createSingleStep(Movements::right, Movements::down);
    }

};

#endif