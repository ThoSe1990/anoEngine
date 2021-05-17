
#ifndef _TILEMAP_JSONMAP_HPP_
#define _TILEMAP_JSONMAP_HPP_


#include "TileMap/Map.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

#include <fstream>


class JsonMap : public Map
{
public:

    JsonMap(const std::weak_ptr<TileMapComponent>& Tilemap) : Map(Tilemap) {}

    void CreateMap() override
    {
        auto tm = tilemap.lock();
        if (!tm) return;

        try
        {
            boost::property_tree::ptree pt;
            boost::property_tree::read_json(tm->filePath, pt);

            auto tileSize = pt.get_child("map.tile_size");

            BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("map.tiles"))
            {
                assert(v.first.empty());
                AddTile(v.second, tileSize.get_value<int>(), tm->textureId);
            }
        }
        catch (std::exception const& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }


private:

    void AddTile(boost::property_tree::ptree const& pt, const int tileSize, const std::string& textureId)
    {
        using boost::property_tree::ptree;

        auto source_x = pt.get_child("source_x");
        auto source_y = pt.get_child("source_y");        
        auto destination_x = pt.get_child("destination_x");
        auto destination_y = pt.get_child("destination_y");
        auto scale = pt.get_child("scale");

        ezEngine::Rectangle source {
            source_x.get_value<int>() * tileSize,
            source_y.get_value<int>() * tileSize,
            tileSize,
            tileSize
        };
        
        ezEngine::Rectangle destination {
            destination_x.get_value<int>() * tileSize * scale.get_value<int>(),
            destination_y.get_value<int>() * tileSize * scale.get_value<int>(),
            tileSize * scale.get_value<int>(),
            tileSize * scale.get_value<int>()
        };
        
        auto newTile =  ezEngine::CreateEntity();
        ezEngine::Sprite::Create(newTile, textureId, source, destination, ezEngine::Sprite::Flip::none, ezEngine::Sprite::Layer::layer_0);
    }

};



#endif