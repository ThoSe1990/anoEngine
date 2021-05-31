
#ifndef _COMPONENTS_POSITIONCOMPONENT_HPP_
#define _COMPONENTS_POSITIONCOMPONENT_HPP_

#include "ezEngine.hpp"

struct PositionComponent
{

    PositionComponent () {}
    PositionComponent (Entity Owner, const ezEngine::Vector2d& setPosition, const ezEngine::Vector2d& maxVelocity, const ezEngine::Vector2d& kp, const ezEngine::Vector2d& ki, const ezEngine::Vector2d& kd) :
    owner(Owner), setPosition(setPosition), maxVelocity(maxVelocity), kp(kp), ki(ki), kd(kd), lastError(ezEngine::Vector2d{0,0}), inPosition(false) { }
    
    Entity owner;
    ezEngine::Vector2d setPosition;
    ezEngine::Vector2d maxVelocity;
    ezEngine::Vector2d kp;
    ezEngine::Vector2d ki;
    ezEngine::Vector2d kd;

    ezEngine::Vector2d lastError;


    bool inPosition;

};


#endif