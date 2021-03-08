#ifndef _MOVEMENTS_MOVEMENT_HPP_
#define _MOVEMENTS_MOVEMENT_HPP_

#include "Constants.hpp"

#include "Entity/Entity.hpp"

#include "Components/ChesspieceComponent.hpp"
#include "Components/TransformComponent.hpp"

class Movement
{
protected:
    void createMovementInDirection(Chesscontroller* chesscontroller, std::string position, int directionX, int directionY, std::string opponentColor)
    {
        while (true)
        {
            position[Movements::x] += directionX;        
            position[Movements::y] += directionY; 
            if ( chesscontroller->IsValidPosition(position) == false )
                break;

            Entity* otherPiece = chesscontroller->GetEntityFromSqaure(position);
            if (otherPiece)
            {
                ChesspieceComponent* cp = otherPiece->GetComponent<ChesspieceComponent>();
                if (cp->color_.compare(opponentColor) == 0)
                    chesscontroller->SetValidation(position, "valid_capture");
                break;
            }
            else
            {
                chesscontroller->SetValidation(position, "valid_move");
            }
        } 
    }

public:
    virtual ~Movement() {}
    virtual void CreateValidMovements(Chesscontroller* chesscontroller, Entity* piece) { }
};






#endif