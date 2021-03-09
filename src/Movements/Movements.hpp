#ifndef _MOVEMENTS_MOVEMENT_HPP_
#define _MOVEMENTS_MOVEMENT_HPP_

#include "Constants.hpp"

#include "Entity/Entity.hpp"

#include "Components/ChesspieceComponent.hpp"
#include "Components/TransformComponent.hpp"

class Movement
{

private:
    std::string playersPosition;
    std::string playersColor;
    std::string opponentsColor;
    
    void capturePieceIfOpponent(Entity* piece, std::string position)
    {
        if (!piece->HasComponent<ChesspieceComponent>())
            return;

        ChesspieceComponent* cp = piece->GetComponent<ChesspieceComponent>();
        if (cp->color_.compare(opponentsColor) == 0)
            chesscontroller->SetValidation(position, "valid_capture");               
    }

    void move(std::string position)
    {
        chesscontroller->SetValidation(position, "valid_move");
    }

    std::string getNextSquare(std::string currentSquare, int directionX, int directionY)
    {
        currentSquare[Movements::x] += directionX;        
        currentSquare[Movements::y] += directionY; 
        return currentSquare;
    }


protected:
//TODO: private when single steps posssible, protected due to pwan movement
    Chesscontroller* chesscontroller;
    Entity* currentPiece;

    void createMovesAndCaptures(int directionX, int directionY)
    {
        std::string nextSquare = playersPosition;
        while (true)
        {
            nextSquare = this->getNextSquare(nextSquare, directionX, directionY);

            if (chesscontroller->IsValidPosition(nextSquare))
            {
                Entity* otherPiece = chesscontroller->GetEntityFromSqaure(nextSquare);
                if (!otherPiece)
                {
                   this->move(nextSquare);
                   continue;
                }

                this->capturePieceIfOpponent(otherPiece, nextSquare);
                break;
            }
            else
                break;
        } 
    }

public:
    Movement(Chesscontroller* Chesscontroller, Entity* CurrentPiece) : chesscontroller(Chesscontroller), currentPiece(CurrentPiece)
    {
        std::tie(playersColor, playersPosition) = chesscontroller->GetColorAndPosition(currentPiece);
        opponentsColor = (playersColor.compare(Constants::color_white) == 0) ? Constants::color_black : Constants::color_white;
    }

    virtual ~Movement() {}
    virtual void CreateValidMovements() { }
};



#endif