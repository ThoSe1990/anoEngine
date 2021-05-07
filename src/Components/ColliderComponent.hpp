#ifndef _COOMPONENTS_COLLIDERCOMPONENT_HPP_
#define _COOMPONENTS_COLLIDERCOMPONENT_HPP_


#include <string>

struct ColliderComponent
{
    ColliderComponent() {}
    ColliderComponent(Entity Owner, const std::string& Type, bool Active) : owner(Owner), type(Type), active(Active), collision(false), collisionWithType(std::string{""}), collisionWithEntity(0) {}

    Entity owner;
    
    std::string type;
    bool active;
    bool collision;
    std::string collisionWithType;
    Entity collisionWithEntity;

};


#endif