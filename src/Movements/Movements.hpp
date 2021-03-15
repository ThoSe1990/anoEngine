#ifndef _MOVEMENTS_MOVEMENT_HPP_
#define _MOVEMENTS_MOVEMENT_HPP_

#include "Constants.hpp"

#include "Entity/Entity.hpp"

#include "Components/ChesspieceComponent.hpp"
#include "Components/TransformComponent.hpp"

class Movement
{

protected: 
    std::shared_ptr<Chesscontroller>& chesscontroller;
    std::shared_ptr<Entity> currentPiece;
    std::string playerPosition;
    std::string playerColor;
    std::string opponentColor;
    std::string playerPiece;

    
    std::string getNextSquare(std::string currentSquare, int directionX, int directionY)
    {
        currentSquare[Movements::x] += directionX;        
        currentSquare[Movements::y] += directionY; 
        return currentSquare;
    }

    void createMovesAndCaptures(const int directionX, const int directionY)
    {
        std::string nextSquare = playerPosition;
        while (true)
        {
            nextSquare = this->getNextSquare(nextSquare, directionX, directionY);

            auto squarestate = chesscontroller->GetSquareState(nextSquare, playerColor);

            if (squarestate == SquareState::free)
            {
                chesscontroller->SetValidation(nextSquare, "valid_move");
            }
            else if (squarestate == SquareState::occupied_by_opponent)
            {
                chesscontroller->SetValidation(nextSquare, "valid_capture");    
                break;  
            }
            else 
                break;
        }
    }


public:
    Movement(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : chesscontroller(Chesscontroller), currentPiece(CurrentPiece)
    {
        std::tie(playerColor, playerPosition) = chesscontroller->GetColorAndPosition(currentPiece);
        opponentColor = (playerColor.compare(Constants::color_white) == 0) ? Constants::color_black : Constants::color_white;
    
        auto* cp = currentPiece->GetComponent<ChesspieceComponent>();
        playerPiece = cp->GetType();

    }

    virtual ~Movement() {}
    virtual void CreateValidMovements() { }
};



#endif