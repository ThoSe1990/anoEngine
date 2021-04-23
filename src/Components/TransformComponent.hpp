
#ifndef _COMPONENTS_TRANSFORMCOMPONENT_HPP_
#define _COMPONENTS_TRANSFORMCOMPONENT_HPP_

#include "glm/glm.hpp"


struct TransformComponent
{
    friend class TransformSystem;

    TransformComponent () {}
    TransformComponent (Entity Owner, glm::vec2 position, int width, int height, unsigned int movingSpeed, int scale) :
    owner(Owner), setPosition(position), actPosition(position), width(width), height(height), movingSpeed(movingSpeed), scale(scale) 
    { }
    Entity owner;

    unsigned int movingSpeed;
    glm::vec2 velocity;
    glm::vec2 setPosition;
    glm::vec2 actPosition;


    int width;
    int height;
    int scale;  
};


#endif