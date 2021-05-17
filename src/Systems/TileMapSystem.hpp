

#ifndef _SYSTEMS_TILEMAPSYSTEM_HPP_
#define _SYSTEMS_TILEMAPSYSTEM_HPP_

#include "Constants.hpp"
#include "Systems/System.hpp"
#include "Components/Components.hpp"

#include "TileMap/MapFactory.hpp"

// #include <boost/property_tree/ptree.hpp>
// #include <boost/property_tree/json_parser.hpp>
// #include <boost/foreach.hpp>

// #include <fstream>


class TileMapSystem : public System
{
public:

    void Initialize() override 
    {

    }

    void Update(float deltaTime) override 
    {

    }

    void Render() override  
    {

    }

    
    // TODO: Delete map method, store entities of map (e.g. container or something)
    // TODO: Add Tilecomponents and json format to readme
    void LoadMap(Entity entity)
    {
        auto& components = Components::GetInstance();
        auto map = MapFactory::CreateMap(components.TilemapManager->GetComponent(entity));
        map->CreateMap();
    }


};

#endif