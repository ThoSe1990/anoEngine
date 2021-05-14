

#ifndef _SYSTEMS_TILEMAPSYSTEM_HPP_
#define _SYSTEMS_TILEMAPSYSTEM_HPP_

#include "Constants.hpp"
#include "Systems/System.hpp"
#include "Components/Components.hpp"

#include <fstream>


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

    void LoadMap(Entity entity)
    {
        auto& components = Components::GetInstance();
        CreateTiles(components.TilemapManager->GetComponent(entity));
    }

private:

    void CreateTiles(const std::shared_ptr<TileMapComponent>& tilemap)
    {

        std::fstream mapFile;
        mapFile.open(tilemap->filePath);


        for (int y = 0; y < tilemap->mapSize.y; y++) 
        {
            for (int x = 0; x < tilemap->mapSize.x; x++) 
            {
                ezEngine::Rectangle source{0,0,tilemap->tileSize.x,tilemap->tileSize.y};

                char ch;
                mapFile.get(ch);
                source.y =  atoi(&ch) * tilemap->tileSize.y;

                mapFile.get(ch);
                source.x = atoi(&ch) * tilemap->tileSize.x;

                ezEngine::Rectangle destination{
                    x*tilemap->tileSize.x*tilemap->scale,
                    y*tilemap->tileSize.y*tilemap->scale,
                    tilemap->tileSize.x*tilemap->scale,
                    tilemap->tileSize.y*tilemap->scale
                    };

                auto newTile = this->AddEntity();
                ezEngine::Sprite::Create(newTile, tilemap->textureId, source, destination, ezEngine::Sprite::Flip::none, ezEngine::Sprite::Layer::layer_0);
                                
                mapFile.get(ch);
                mapFile.ignore();
            }
        }
        mapFile.close();


    }

};

#endif