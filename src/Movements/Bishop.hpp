#ifndef _MOVEMENTS_BISHOP_HPP_
#define _MOVEMENTS_BISHOP_HPP_

#include "Movements/Movements.hpp" 

class Bishop : public Movement
{
private:

    std::string playerColor;
    std::string opponentColor;

public:
    Bishop(Entity* currentPiece)
    {
        ChesspieceComponent* cp = currentPiece->GetComponent<ChesspieceComponent>();
        if (cp->color_.compare(Constants::color_black) == 0) 
        {
            playerColor = Constants::color_black;
            opponentColor = Constants::color_white;
        }
        else
        {
            playerColor = Constants::color_white;
            opponentColor = Constants::color_black;
        }

    }

    void CreateValidMovements(Chesscontroller* chesscontroller, Entity* piece)
    {
        auto [playerColor, playerPosition] = chesscontroller->GetColorAndPosition(piece);
        createMovementInDirection(chesscontroller, playerPosition, Movements::up, Movements::right, opponentColor);
        createMovementInDirection(chesscontroller, playerPosition, Movements::down, Movements::right, opponentColor);
        createMovementInDirection(chesscontroller, playerPosition, Movements::down, Movements::left, opponentColor);
        createMovementInDirection(chesscontroller, playerPosition, Movements::up, Movements::left, opponentColor);
    }

};

#endif