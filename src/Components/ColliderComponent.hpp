#ifndef _COOMPONENTS_COLLIDERCOMPONENT_HPP_
#define _COOMPONENTS_COLLIDERCOMPONENT_HPP_


#include <string>

struct ColliderComponent
{
    ColliderComponent(const std::string& Type, bool Active) : type(Type), active(Active) {}

    std::string type;
    bool active;

};


#endif