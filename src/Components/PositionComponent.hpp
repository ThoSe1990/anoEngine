
#ifndef _COMPONENTS_POSITIONCOMPONENT_HPP_
#define _COMPONENTS_POSITIONCOMPONENT_HPP_

#include "anoEngine.hpp"

struct PositionComponent
{

    PositionComponent () {}
    PositionComponent (Entity Owner, const anoEngine::Vector2d& setPosition, const anoEngine::Vector2d& maxVelocity, const anoEngine::Vector2d& kp, const anoEngine::Vector2d& ki, const anoEngine::Vector2d& kd) :
    owner(Owner), setPosition(setPosition), maxVelocity(maxVelocity), kp(kp), ki(ki), kd(kd), lastError(anoEngine::Vector2d{0,0}), inPosition(false) { }
    
    Entity owner;
    anoEngine::Vector2d setPosition;
    anoEngine::Vector2d maxVelocity;
    anoEngine::Vector2d kp;
    anoEngine::Vector2d ki;
    anoEngine::Vector2d kd;

    anoEngine::Vector2d lastError;


    bool inPosition;

};


#endif