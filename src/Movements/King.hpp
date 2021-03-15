#ifndef _MOVEMENTS_KING_HPP_
#define _MOVEMENTS_KING_HPP_

#include "Movements/Movements.hpp" 
#include "Components/ChesspieceComponent.hpp"

class King : public Movement
{
private:
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


    void castle(const int side)
    {
        auto* cp = currentPiece->GetComponent<ChesspieceComponent>();
        if (cp->GetMoves() > 0)
            return;

        std::string nextSquare = playerPosition;
        while (chesscontroller->IsValidPosition(nextSquare))
        {
            nextSquare = getNextSquare(nextSquare, side, Movements::none);
            auto squarestate = chesscontroller->GetSquareState(nextSquare, playerColor);

            if (squarestate == SquareState::free)
                continue;
            else if (squarestate == SquareState::occupied_by_opponent)
                return;
            else if (squarestate == SquareState::occupied_by_friend)
            {
                auto friendPiece = chesscontroller->GetEntityFromSqaure(nextSquare);
                auto* cp = friendPiece->GetComponent<ChesspieceComponent>();
                if (cp->GetType().compare("rook") == 0 && cp->GetMoves() == 0)
                {
                    Logger::Log(logging::trivial::debug, log_location, "castling is valid for ", cp->GetType(), " in direction ", side);
                    // castling is valid here 
                    // set valid move or valid castling
                    return;
                } 
                return;
            }
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
        castle(Movements::right);
        castle(Movements::left);
    }

};

#endif