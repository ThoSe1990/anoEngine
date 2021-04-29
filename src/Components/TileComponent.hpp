#ifndef _COMPONENTS_TILECOMPONENT_HPP_
#define _COMPONENTS_TILECOMPONENT_HPP_


#include <SDL2/SDL.h>
#include "glm/glm.hpp"
#include "Game.hpp"
#include "ezEngine.hpp"

/**
 * TODO: will be implemented after completing flappy bird with python api
 */


struct TileComponent
{
    TileComponent(){}
    TileComponent(Entity owner, const glm::vec2 position) : owner(owner), position(position)
    {  }
    
    Entity owner;
    glm::vec2 position;
};



#endif