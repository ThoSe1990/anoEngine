#ifndef _TILEMAP_MAP_HPP_
#define _TILEMAP_MAP_HPP_

#include "Components/Components.hpp"


class Map
{
public:

    virtual void CreateMap() = 0;
    
    Map (const std::weak_ptr<TileMapComponent>& Tilemap) : tilemap(Tilemap) {}
    virtual ~Map(){}



protected: 
    std::weak_ptr<TileMapComponent> tilemap;
};

#endif 