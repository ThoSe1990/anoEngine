
#ifndef _COMPONENTS_POSITIONCOMPONENT_HPP_
#define _COMPONENTS_POSITIONCOMPONENT_HPP_

#include "glm/glm.hpp"
#include "ezEngine.hpp"

struct PositionComponent
{

    PositionComponent () {}
    PositionComponent (Entity Owner, glm::vec2 setPosition, glm::vec2 velocity) :
    owner(Owner), setPosition(setPosition), velocity(velocity) { }
    
    Entity owner;
    glm::vec2 setPosition;
    glm::vec2 velocity;

};


#endif