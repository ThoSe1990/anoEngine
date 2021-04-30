#ifndef _COOMPONENTS_COLLIDERCOMPONENT_HPP_
#define _COOMPONENTS_COLLIDERCOMPONENT_HPP_


#include <string>

struct ColliderComponent
{
    ColliderComponent(Entity Owner, const std::string& Type, bool Active) : owner(Owner), type(Type), active(Active), collision(false), collisionWithType(std::string{""}) {}

    Entity owner;
    
    std::string type;
    bool active;
    bool collision;
    std::string collisionWithType;

};


#endif