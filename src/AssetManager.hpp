
#ifndef _ASSETMANAGER_HPP_
#define _ASSETMANAGER_HPP_


#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 

class AssetManager 
{
private:
    std::map<std::string, SDL_Texture*> textures;
    
public:
    void ClearData();
    void AddTexture(const std::string& textureId, const char* filePath);
    SDL_Texture* GetTexture(const std::string& textureId);
};


#endif