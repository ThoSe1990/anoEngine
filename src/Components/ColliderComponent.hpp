#ifndef _COOMPONENTS_COLLIDERCOMPONENT_HPP_
#define _COOMPONENTS_COLLIDERCOMPONENT_HPP_


#include <string>

struct ColliderComponent
{
    ColliderComponent() {}
    ColliderComponent(Entity Owner, const float offset, const std::string& Type, bool Active) : owner(Owner), offset(offset),type(Type), active(Active), collision(false), collisionWithType(std::string{""}), collisionWithEntity(0) {}

    Entity owner;
    float offset;
    std::string type;
    bool active;
    bool collision;
    std::string collisionWithType;
    Entity collisionWithEntity;

};


#endif