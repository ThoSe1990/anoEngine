
#ifndef _COMPONENTS_TRANSFORMCOMPONENT_HPP_
#define _COMPONENTS_TRANSFORMCOMPONENT_HPP_

#include "glm/glm.hpp"
#include "ezEngine.hpp"

struct TransformComponent
{

    TransformComponent () {}
    TransformComponent (Entity Owner, glm::vec2 position, int width, int height, glm::vec2 velocity, int scale) :
    owner(Owner), position(position), width(width), height(height), velocity(velocity), scale(scale)
    { }
    Entity owner;

    glm::vec2 velocity;
    glm::vec2 position;


    int width;
    int height;
    int scale;  
};


#endif