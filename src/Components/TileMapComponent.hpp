#ifndef _COMPONENTS_TILECOMPONENT_HPP_
#define _COMPONENTS_TILECOMPONENT_HPP_


#include <SDL2/SDL.h>
#include "Game.hpp"
#include "ezEngine.hpp"


struct TileMapComponent
{
    TileMapComponent(){}
    TileMapComponent(Entity owner, const std::string& filePath, const std::string& textureId, const ezEngine::Vector2d& mapSize, const ezEngine::Vector2d& tileSize, const float scale) : owner(owner), filePath(filePath), textureId(textureId), mapSize(mapSize), tileSize(tileSize), scale(scale)
    {  }
    
    Entity owner;
    std::string filePath;
    std::string textureId;
    ezEngine::Vector2d tileSize;
    ezEngine::Vector2d mapSize;
    float scale;
};



#endif