
#ifndef _COMPONENTS_TRANSFORMCOMPONENT_HPP_
#define _COMPONENTS_TRANSFORMCOMPONENT_HPP_

#include "ezEngine.hpp"

struct TransformComponent
{
    TransformComponent () {}
    TransformComponent (Entity Owner, const ezEngine::Rectangle& rectangle, const ezEngine::Vector2d& velocity, int scale) :
    owner(Owner), rectangle(rectangle), velocity(velocity), scale(scale)
    { }
    
    Entity owner;

    ezEngine::Rectangle rectangle;
    ezEngine::Vector2d velocity;

    int scale;  
};


#endif