#ifndef _CHESS_MOVEMENTS_PAWN_HPP_
#define _CHESS_MOVEMENTS_PAWN_HPP_

#include "Chess/Movements/Movements.hpp"


class Pawn : public Movement
{
    Entity entity;
public:

    Pawn (Entity entity) : entity(entity) { }

    void CreateValidMovements() override 
    {
        auto& components = Components::GetInstance();
        auto cp = components.ChesspieceManager->GetComponent(entity);  
        int movingDirection = (cp->color.compare(Constants::color_black) == 0) ? Movements::down : Movements::up;
        std::string oppColor = (cp->color.compare(Constants::color_black) == 0) ? Constants::color_white : Constants::color_black;
        std::string next = getNextSquare(cp->square, Movements::none, movingDirection);
        createValidation(next, oppColor);   
        next = getNextSquare(next, Movements::none, movingDirection);
        createValidation(next, oppColor);   
    }
};


#endif