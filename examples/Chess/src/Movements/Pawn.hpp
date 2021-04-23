#ifndef _CHESS_MOVEMENTS_PAWN_HPP_
#define _CHESS_MOVEMENTS_PAWN_HPP_

#include "Movement.hpp"


class Pawn : public Movement
{

    void forwardSteps(const int movingDirection)
    {
        std::string next = getNextSquare(chesspiece->square, Movements::none, movingDirection);
        auto opponent = Chess::GetChesspieceFromSquare(next);
        if (!opponent)
            createValidation(next, "valid_move");  

        if (chesspiece->movesCount == 0)
        {
            next = getNextSquare(next, Movements::none, movingDirection);
            opponent = Chess::GetChesspieceFromSquare(next);
            if (!opponent)
                createValidation(next, "valid_move");  
        }
    }

    void capture(const std::string& square)
    {
        auto opponent = Chess::GetChesspieceFromSquare(square);
        if (opponent && opponent->color.compare(opponentColor) == 0)
            createValidation(square, "valid_capture");
    }


public:

    Pawn (const std::shared_ptr<Chesspiece>& Chesspiece) : Movement(Chesspiece) { }

    void CreateValidMovements() override 
    {
        int movingDirection = (chesspiece->color.compare(Constants::color_black) == 0) ? Movements::down : Movements::up;

        forwardSteps(movingDirection);

        std::string right = getNextSquare(chesspiece->square, Movements::right, movingDirection);
        capture(right);
        
        std::string left = getNextSquare(chesspiece->square, Movements::left, movingDirection);
        capture(left);
    }
};


#endif