
#ifndef _COMPONENTS_TRANSFORMCOMPONENT_HPP_
#define _COMPONENTS_TRANSFORMCOMPONENT_HPP_

#include "anoEngine.hpp"

struct TransformComponent
{
    TransformComponent () {}
    TransformComponent (Entity Owner, const anoEngine::Rectangle& rectangle, const anoEngine::Vector2d& velocity, int scale) :
    owner(Owner), rectangle(rectangle), velocity(velocity), scale(scale)
    { }
    
    Entity owner;

    anoEngine::Rectangle rectangle;
    anoEngine::Vector2d velocity;

    int scale;  
};


#endif