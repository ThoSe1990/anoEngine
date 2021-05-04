
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
    std::map<std::string, TTF_Font*> fonts;
    std::map<std::string, std::string> tilemaps;
public:
    void ClearData();

    void AddTexture(const std::string& textureId, const char* filePath);
    SDL_Texture* GetTexture(const std::string& textureId);

    void AddFont(std::string fontId, const char* filePath, int fontSize);        
    TTF_Font* GetFont(std::string fontId);

    void AddMap(const std::string& mapId, const std::string& filePath);
    std::string GetMap(const std::string& mapId);
};


#endif