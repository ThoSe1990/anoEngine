
#ifndef _ASSETMANAGER_HPP_
#define _ASSETMANAGER_HPP_


#include <map>
#include <string>
#include "TextureManager.hpp"
#include "Entity/EntityManager.hpp"

class AssetManager 
{
private:
    EntityManager* manager;
    std::map<std::string, SDL_Texture*> textures;
public:
    AssetManager(EntityManager* manager);
    ~AssetManager();
    void ClearData();
    void AddTexture(std::string textureId, const char* filePath);
    SDL_Texture* GetTexture(std::string textureId);
};


#endif