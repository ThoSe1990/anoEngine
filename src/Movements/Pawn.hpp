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

    void forwardMovement(Chesscontroller* chesscontroller, std::string playerPosition)
    {
        playerPosition[Movements::y] += movingDirection;

        Entity* isEntity = chesscontroller->GetEntityFromSqaure(playerPosition);
        if (!isEntity)
        {
            chesscontroller->SetValidation(playerPosition, "valid_move");
        }

        if (this->initialPosition)
        {
            this->initialPosition = false;
            forwardMovement(chesscontroller, playerPosition);  
        }
    }

    void addCapturingMovement(Chesscontroller* chesscontroller, std::string playerPosition, std::string playerColor, int side)
    {
        playerPosition[Movements::y] += movingDirection;
        playerPosition[Movements::x] += side;

        auto [isOpponentEntity, OpponentColor] = chesscontroller->GetPieceAndColor(playerPosition);
        if (isOpponentEntity && OpponentColor.compare(playerColor) != 0)
        {
            chesscontroller->SetValidation(playerPosition, "valid_capture");
        }
    }

public:
    Pawn(Entity* currentPiece)
    {
        ChesspieceComponent* cp = currentPiece->GetComponent<ChesspieceComponent>();
        movingDirection = (cp->color_.compare(Constants::color_black) == 0) ? Movements::down : Movements::up;

        TransformComponent* tc = currentPiece->GetComponent<TransformComponent>();
        initialPosition = (cp->color_.compare(Constants::color_black) == 0) 
            ? tc->square[Movements::y] == initialRowBlack 
            : tc->square[Movements::y] == initialRowWhite;        
    }

    void CreateValidMovements(Chesscontroller* chesscontroller, Entity* piece) override 
    {
        auto [playerColor, playerPosition] = chesscontroller->GetColorAndPosition(piece);
        forwardMovement(chesscontroller, playerPosition);  
        addCapturingMovement(chesscontroller, playerPosition, playerColor, Movements::right);
        addCapturingMovement(chesscontroller, playerPosition, playerColor, Movements::left);
    }
};


#endif
