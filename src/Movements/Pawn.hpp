#ifndef _MOVEMENTS_PAWN_HPP_
#define _MOVEMENTS_PAWN_HPP_

#include "Movements/Movements.hpp"

class Pawn : public Movement
{
private:

    const char initialRowBlack = '7';
    const char initialRowWhite = '2';

    int getMovingDirection(std::string color)
    {
        return (color.compare(Constants::color_black) == 0) ? Movements::down : Movements::up;
    }

    bool isInitialPosition(const char positionX, std::string color)
    {
        return (color.compare(Constants::color_black) == 0) 
        ? positionX == initialRowBlack 
        : positionX == initialRowWhite;
    }


    // TODO: DRY!!!
    void addRegularMovement(Chesscontroller* chesscontroller,std::string position, std::string color)
    {
        int direction = getMovingDirection(color);
        position[Movements::y] += direction;

        auto [otherPiece, otherColor] = chesscontroller->GetPieceAndColor(position);
        if (!otherPiece)
            movements.emplace(position, "valid_move");
    }
    void addInitialMovement(Chesscontroller* chesscontroller,std::string position, std::string color)
    {
        if (isInitialPosition(position[Movements::y], color))
        {
            int direction = getMovingDirection(color);
            position[Movements::y] += direction;
            position[Movements::y] += direction;

            auto [otherPiece, otherColor] = chesscontroller->GetPieceAndColor(position);
            if (!otherPiece)
                movements.emplace(position, "valid_move");
        }
    }
    void addCapturingMovement(Chesscontroller* chesscontroller,std::string position, std::string color)
    {
        int direction = getMovingDirection(color);
        position[Movements::y] += direction;
        position[Movements::x] += Movements::right;

        auto [otherPiece, otherColor] = chesscontroller->GetPieceAndColor(position);
        if (otherPiece && otherColor.compare(color) != 0)
        {
            movements.emplace(position, "valid_capture");

        }
        
        position[Movements::x] += Movements::left;
        position[Movements::x] += Movements::left;

        auto [anotherPiece, anotherColor] = chesscontroller->GetPieceAndColor(position);
        if (anotherPiece && anotherColor.compare(color) != 0)
        {
            movements.emplace(position, "valid_capture");
        } 
    }

    std::map<std::string, std::string> movements;

public:
   
    std::map<std::string, std::string> GetMovements(Chesscontroller* chesscontroller, Entity* piece) override 
    {
        auto [color, position] = getColorAndPosition(piece);
        addRegularMovement(chesscontroller, position, color);  
        addInitialMovement(chesscontroller, position, color);
        addCapturingMovement(chesscontroller, position, color);
        return movements;
    }
};


#endif
