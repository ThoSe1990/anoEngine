#ifndef _CHESS_MOVEMENTS_KING_HPP_
#define _CHESS_MOVEMENTS_KING_HPP_

#include "Chess/Movements/Movement.hpp" 
#include "Components/ChesspieceComponent.hpp"

class King : public Movement
{
private:

    void castle(const int side)
    {
        if (chesspiece->movesCount > 0)
            return;

        std::string nextSquare = chesspiece->square;
        while (Chessboard::IsValidSquare(nextSquare))
        {
            nextSquare = getNextSquare(nextSquare, side, Movements::none);
            if (!Chessboard::IsValidSquare(nextSquare))
                break;
            
            auto pieceOnSquare = Chess::GetChesspieceFromSquare(nextSquare);

            if (!pieceOnSquare)
                continue;
            else if (pieceOnSquare->color.compare(opponentColor) == 0)
                return;
            else if (pieceOnSquare->color.compare(chesspiece->color) == 0)
            {               
                if (pieceOnSquare->type.compare("rook") == 0 && pieceOnSquare->movesCount == 0)
                {                    
                    std::string position = chesspiece->square;
                    position[Movements::x] += 2*side;
                    createValidation(position, "valid_move");
                    return;
                } 
                return;
            }
        } 
    }

public:


    King(const std::shared_ptr<ChesspieceComponent>& Chesspiece) : Movement(Chesspiece) { }

    void CreateValidMovements() override
    {
        createValidation(Movements::none, Movements::up);
        createValidation(Movements::left, Movements::none);
        createValidation(Movements::right, Movements::none);
        createValidation(Movements::none, Movements::down);
        createValidation(Movements::left, Movements::up);
        createValidation(Movements::left, Movements::down);
        createValidation(Movements::right, Movements::up);
        createValidation(Movements::right, Movements::down);
        castle(Movements::right);
        castle(Movements::left);
    }

};

#endif