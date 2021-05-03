
#ifndef _COMPONENTS_TRANSFORMCOMPONENT_HPP_
#define _COMPONENTS_TRANSFORMCOMPONENT_HPP_

#include "glm/glm.hpp"
#include "ezEngine.hpp"

struct TransformComponent
{

    TransformComponent () {}
    TransformComponent (Entity Owner, ezEngine::Vector2d position, int width, int height, ezEngine::Vector2d velocity, int scale) :
    owner(Owner), position(position), width(width), height(height), velocity(velocity), scale(scale)
    { }
    Entity owner;

    ezEngine::Vector2d position;
    ezEngine::Vector2d velocity;

    int width;
    int height;
    int scale;  
};


#endif