#ifndef _COMPONENTS_CHESSPIECECOMPONENT_HPP_
#define _COMPONENTS_CHESSPIECECOMPONENT_HPP_

#include <string>
#include "Components/Component.hpp"
#include "Components/TransformComponent.hpp"
#include  "Components/SpriteComponent.hpp"


#include "Constants.hpp"

class ChesspieceComponent : public Component
{

    char endOfBoard;
    std::string color_;
    std::string type_;
    bool captured_;
    bool isSelected;  
  

    TransformComponent* transform;
    SpriteComponent* sprite;


public:

    ChesspieceComponent(const std::string& type, const std::string& color, bool captured) 
     : type_(type),
     color_(color),
     captured_(captured),
     isSelected(false)
     {}


    void Initialize() override 
    {
        sprite = Owner->GetComponent<SpriteComponent>();
        transform = Owner->GetComponent<TransformComponent>();
        endOfBoard = (color_.compare(Constants::color_white) == 0) ? '8' : '1';
    }

    bool PawnCanPromote()
    {
        if (type_.compare("pawn") != 0)
            return false;

        return (transform->square[Movements::y] == endOfBoard) ? true : false;
    }

    std::string GetColor() const
    {
        return color_;
    }
    
    std::string GetType() const 
    {
        return type_;
    }

    void SetNewPieceType(const std::string& type)
    {
        Logger::Log(logging::trivial::debug, log_location, "converting ", this->GetType(), " to " , type);
        
        this->type_ = type;      
        
        std::string assetId = color_ + '_' + type_;
        sprite->SetTexture(assetId);
    }


};

#endif
