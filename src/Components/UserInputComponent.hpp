#ifndef _COMPONENTS_USERINPUTCOMPONENT_HPP_
#define _COMPONENTS_USERINPUTCOMPONENT_HPP_


#include "ezEngine.hpp"

struct UserInputComponent {

    UserInputComponent(Entity owner, bool active) : owner(owner) , active(active) {}

    Entity owner;

    bool active;

};


#endif