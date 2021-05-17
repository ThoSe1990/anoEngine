
#ifndef _TILEMAP_LUAMAP_HPP_
#define _TILEMAP_LUAMAP_HPP_


#include "TileMap/Map.hpp"


#include <fstream>


class LuaMap : public Map
{

    sol::state lua;

public:

    LuaMap(const std::weak_ptr<TileMapComponent>& Tilemap) : Map(Tilemap) 
    {
        lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);
    }

    void CreateMap() override
    {
        auto tm = tilemap.lock();
        if (!tm) return;

        lua.script_file(tm->filePath);

        int tileSize = lua["map"]["tile_size"];
        sol::table tiles = lua["map"]["tiles"];

        unsigned int index = 0;
        while (true)
        {
            sol::optional<sol::table> exists = tiles[index];
            if (exists == sol::nullopt)
                break;
            
            sol::table tile = tiles[index];

            int source_x = tile["source_x"];
            int source_y = tile["source_y"];        
            int destination_x = tile["destination_x"];
            int destination_y = tile["destination_y"];
            int scale = tile["scale"];
            
            ezEngine::Rectangle source {
                source_x * tileSize,
                source_y * tileSize,
                tileSize,
                tileSize
            };
            
            ezEngine::Rectangle destination {
                destination_x * tileSize * scale,
                destination_y * tileSize * scale,
                tileSize * scale,
                tileSize * scale
            };
            
            auto newTile =  ezEngine::CreateEntity();
            ezEngine::Sprite::Create(newTile, tm->textureId, source, destination, ezEngine::Sprite::Flip::none, ezEngine::Sprite::Layer::layer_0);

            index++;
        }

};



#endif