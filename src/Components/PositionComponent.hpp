
#ifndef _COMPONENTS_POSITIONCOMPONENT_HPP_
#define _COMPONENTS_POSITIONCOMPONENT_HPP_

#include "ezEngine.hpp"

struct PositionComponent
{

    PositionComponent () {}
    PositionComponent (Entity Owner, ezEngine::Vector2d setPosition, ezEngine::Vector2d velocity) :
    owner(Owner), setPosition(setPosition), velocity(velocity) { }
    
    Entity owner;
    ezEngine::Vector2d setPosition;
    ezEngine::Vector2d velocity;

};


#endif