#ifndef _TILEMAP_MAPFACTORY_HPP_
#define _TILEMAP_MAPFACTORY_HPP_

#include <boost/filesystem.hpp>

#include "Components/Components.hpp"
#include "TileMap/JsonMap.hpp"
#include "TileMap/LuaMap.hpp"

class MapFactory
{
public:

    static std::unique_ptr<Map> CreateMap(const std::shared_ptr<TileMapComponent>& tilemap)
    {
        std::string fileExtenstion = boost::filesystem::extension(tilemap->filePath);

        if (fileExtenstion.compare(".json") == 0)
            return std::make_unique<JsonMap>(tilemap);
        else if (fileExtenstion.compare(".lua") == 0)
            return std::make_unique<LuaMap>(tilemap);

    }

};

#endif 