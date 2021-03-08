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

    void forwardMovement(Chesscontroller* chesscontroller, std::string position)
    {
        position[Movements::y] += movingDirection;

        Entity* isEntity = chesscontroller->GetEntityFromSqaure(position);
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

    void addCapturingMovement(Chesscontroller* chesscontroller, std::string position, std::string color, int side)
    {
        position[Movements::y] += movingDirection;
        position[Movements::x] += side;

        auto [isOpponentEntity, OpponentColor] = chesscontroller->GetPieceAndColor(position);
        if (isOpponentEntity && OpponentColor.compare(color) != 0)
        {
            chesscontroller->SetValidation(position, "valid_capture");
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
        auto [color, position] = chesscontroller->GetColorAndPosition(piece);
        forwardMovement(chesscontroller, position);  
        addCapturingMovement(chesscontroller, position, color, Movements::right);
        addCapturingMovement(chesscontroller, position, color, Movements::left);
    }
};


#endif
