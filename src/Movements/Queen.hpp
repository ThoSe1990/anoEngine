#ifndef _MOVEMENTS_QUEEN_HPP_
#define _MOVEMENTS_QUEEN_HPP_

#include "Movements/Movements.hpp" 

class Queen : public Movement
{
private:
    std::string playerColor;
    std::string opponentColor;
public:
    Queen(Entity* currentPiece)
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
        createMovementInDirection(chesscontroller, playerPosition, Movements::up, Movements::none, opponentColor);
        createMovementInDirection(chesscontroller, playerPosition, Movements::none, Movements::right, opponentColor);
        createMovementInDirection(chesscontroller, playerPosition, Movements::down, Movements::none, opponentColor);
        createMovementInDirection(chesscontroller, playerPosition, Movements::none, Movements::left, opponentColor);
        createMovementInDirection(chesscontroller, playerPosition, Movements::up, Movements::right, opponentColor);
        createMovementInDirection(chesscontroller, playerPosition, Movements::down, Movements::right, opponentColor);
        createMovementInDirection(chesscontroller, playerPosition, Movements::down, Movements::left, opponentColor);
        createMovementInDirection(chesscontroller, playerPosition, Movements::up, Movements::left, opponentColor);
    
    }

};

#endif