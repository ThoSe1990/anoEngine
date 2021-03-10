#ifndef _MOVEMENTS_MOVEMENT_HPP_
#define _MOVEMENTS_MOVEMENT_HPP_

#include "Constants.hpp"

#include "Entity/Entity.hpp"

#include "Components/ChesspieceComponent.hpp"
#include "Components/TransformComponent.hpp"

class Movement
{


protected: // TODO: refactor, all members protected later on??
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

    void capturePieceIfOpponent(std::shared_ptr<Entity> piece, std::string position)
    {
        if (!piece->HasComponent<ChesspieceComponent>())
            return;

        ChesspieceComponent* cp = piece->GetComponent<ChesspieceComponent>();
        if (cp->color_.compare(opponentColor) == 0)
            chesscontroller->SetValidation(position, "valid_capture");               
    }



// TODO: refactore ... DRY
    void createMovesAndCaptures(const int directionX, const int directionY)
    {
        std::string nextSquare = playerPosition;
        while (true)
        {
            nextSquare = this->getNextSquare(nextSquare, directionX, directionY);

            if (!chesscontroller->IsValidPosition(nextSquare))
            {
                break;
            }
            else
            {
                std::shared_ptr<Entity> otherPiece = chesscontroller->GetEntityFromSqaure(nextSquare);
                if (!otherPiece)
                {
                   chesscontroller->SetValidation(nextSquare, "valid_move");
                   continue;
                }

                this->capturePieceIfOpponent(otherPiece, nextSquare);
                break;
            }
        } 
    }

public:
    Movement(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : chesscontroller(Chesscontroller), currentPiece(CurrentPiece)
    {
        std::tie(playerColor, playerPosition) = chesscontroller->GetColorAndPosition(currentPiece);
        opponentColor = (playerColor.compare(Constants::color_white) == 0) ? Constants::color_black : Constants::color_white;
    
        ChesspieceComponent* cp = currentPiece->GetComponent<ChesspieceComponent>();
        playerPiece = cp->type_;

    }

    virtual ~Movement() {}
    virtual void CreateValidMovements() { }
};



#endif