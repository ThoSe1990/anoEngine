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

    void forwardMovement(std::shared_ptr<Chesscontroller>& chesscontroller, std::string position)
    {
        position[Movements::y] += movingDirection;

        std::shared_ptr<Entity> isEntity = chesscontroller->GetEntityFromSqaure(position);
        if (!isEntity)
        {
            chesscontroller->SetValidation(position, "valid_move");
        }

        if (this->initialPosition)
        {
            this->initialPosition = false;
            forwardMovement(chesscontroller, position);  
        }
    }

    bool isOpponentPiece(const std::string& square)
    {
        auto piece = chesscontroller->GetEntityFromSqaure(square);
        if (piece)
        {
            ChesspieceComponent* cp = piece->GetComponent<ChesspieceComponent>();
            return cp->color_.compare(playerColor) == 0 ? false : true;
        }
        return false;
    }

    void addCapturingMovement(std::shared_ptr<Chesscontroller>& chesscontroller, std::string position, std::string playerColor, int side)
    {
        position[Movements::y] += movingDirection;
        position[Movements::x] += side;

        if (isOpponentPiece(position))
        {
            chesscontroller->SetValidation(position, "valid_capture");
        }

    }

public:
    Pawn(std::shared_ptr<Chesscontroller>& Chesscontroller, std::shared_ptr<Entity> CurrentPiece) : Movement(Chesscontroller, CurrentPiece) 
    {
        ChesspieceComponent* cp = currentPiece->GetComponent<ChesspieceComponent>();
        movingDirection = (cp->color_.compare(Constants::color_black) == 0) ? Movements::down : Movements::up;
        TransformComponent* tc = currentPiece->GetComponent<TransformComponent>();
        initialPosition = (cp->color_.compare(Constants::color_black) == 0) 
            ? tc->square[Movements::y] == initialRowBlack 
            : tc->square[Movements::y] == initialRowWhite;     
    }

    void CreateValidMovements() override 
    {
        auto [playerColor, playerPosition] = chesscontroller->GetColorAndPosition(currentPiece);
        forwardMovement(chesscontroller, playerPosition);  
        addCapturingMovement(chesscontroller, playerPosition, playerColor, Movements::right);
        addCapturingMovement(chesscontroller, playerPosition, playerColor, Movements::left);
    }
};


#endif