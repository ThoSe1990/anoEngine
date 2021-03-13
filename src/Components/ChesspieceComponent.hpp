#ifndef _COMPONENTS_CHESSPIECECOMPONENT_HPP_
#define _COMPONENTS_CHESSPIECECOMPONENT_HPP_

#include <string>
#include "Components/Component.hpp"
#include "Components/TransformComponent.hpp"

#include "Log.hpp"
#include "Constants.hpp"
#include "Entity/EntityManager.hpp"
#include "ChessBoard.hpp"

extern std::shared_ptr<ChessBoard> chessBoard;

extern std::shared_ptr<EntityManager> manager;

class ChesspieceComponent : public Component
{
public:
    char endOfBoard;
    
    std::string color_;
    std::string type_;
    bool captured_;
    bool isSelected;    

    TransformComponent* transform;


    ChesspieceComponent(const std::string& type, const std::string& color, bool captured) 
     : type_(type),
     color_(color),
     captured_(captured),
     isSelected(false)
     {}


    void Initialize() override 
    {
        transform = Owner->GetComponent<TransformComponent>();
        endOfBoard = (color_.compare(Constants::color_white) == 0) ? '8' : '1';
    }

    bool PawnCanPromote()
    {
        if (type_.compare("pawn") != 0)
            return false;

        return (transform->square[Movements::y] == endOfBoard) ? true : false;
    }

};

#endif
