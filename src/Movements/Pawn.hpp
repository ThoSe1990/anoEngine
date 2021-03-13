#ifndef _MOVEMENTS_PAWN_HPP_
#define _MOVEMENTS_PAWN_HPP_

#include "Movements/Movements.hpp"

class Pawn : public Movement
{
private:

    const char initialRowBlack = '7';
    const char initialRowWhite = '2';

    bool initialPosition;
    int movingDirection;

    void addInitialStep(const std::string& position, const int directionX, const int directionY)
    {
        if (initialPosition)
        {
            std::string next = getNextSquare(position, directionX, directionY);
            auto squarestate = chesscontroller->GetSquareState(next, playerColor);
            if (squarestate == SquareState::free)
                chesscontroller->SetValidation(next, "valid_move");
        }
    }

    void createSingleStep(const int directionX, const int directionY)
    {
        std::string nextSquare = getNextSquare(playerPosition, directionX, directionY);
        auto squarestate = chesscontroller->GetSquareState(nextSquare, playerColor);

        if (squarestate == SquareState::free)
            chesscontroller->SetValidation(nextSquare, "valid_move");
        
        addInitialStep(nextSquare, directionX, directionY);
    }

    void addCapturingMovement(int side)
    {
        std::string nextSquare = playerPosition;
        nextSquare[Movements::y] += movingDirection;
        nextSquare[Movements::x] += side;

        auto squarestate = chesscontroller->GetSquareState(nextSquare, playerColor);
        if (squarestate == SquareState::occupied_by_opponent)
            chesscontroller->SetValidation(nextSquare, "valid_capture");
    }

public:
    Pawn(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : Movement(Chesscontroller, CurrentPiece) 
    {
        auto* cp = currentPiece->GetComponent<ChesspieceComponent>();
        movingDirection = (cp->color_.compare(Constants::color_black) == 0) ? Movements::down : Movements::up;
        auto* tc = currentPiece->GetComponent<TransformComponent>();
        initialPosition = (cp->color_.compare(Constants::color_black) == 0) 
            ? tc->square[Movements::y] == initialRowBlack 
            : tc->square[Movements::y] == initialRowWhite;     
    }

    void CreateValidMovements() override 
    {
        createSingleStep(Movements::none, movingDirection);
        addCapturingMovement(Movements::right);
        addCapturingMovement(Movements::left);
    }
};


#endif