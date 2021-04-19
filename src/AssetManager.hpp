
#ifndef _ASSETMANAGER_HPP_
#define _ASSETMANAGER_HPP_


#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 
// #include "Entity/EntityManager.hpp"

class AssetManager 
{
private:
    // std::shared_ptr<EntityManager> manager;
    std::map<std::string, SDL_Texture*> textures;
    
public:
    AssetManager();
    // AssetManager(EntityManager* manager);
    // AssetManager(std::shared_ptr<EntityManager> manager);
    ~AssetManager();
    void ClearData();
    void AddTexture(const std::string& textureId, const char* filePath);
    SDL_Texture* GetTexture(const std::string& textureId);
};


#endif