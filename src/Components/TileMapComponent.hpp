#ifndef _COMPONENTS_TILECOMPONENT_HPP_
#define _COMPONENTS_TILECOMPONENT_HPP_


#include <SDL2/SDL.h>
#include "Game.hpp"
#include "anoEngine.hpp"


struct TileMapComponent
{
    TileMapComponent(){}
    TileMapComponent(Entity owner, const std::string& filePath, const std::string& textureId) : owner(owner), filePath(filePath), textureId(textureId)
    {  }
    
    Entity owner;
    std::string filePath;
    std::string textureId;
};



#endif