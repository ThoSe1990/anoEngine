#include "AssetManager.hpp"
#include "TextureManager.hpp"

void AssetManager::ClearData() 
{
    textures.clear();
}

void AssetManager::AddTexture(const std::string& textureId, const char* filePath) 
{
    textures.emplace(textureId, TextureManager::LoadTexture(filePath));
}

SDL_Texture* AssetManager::GetTexture(const std::string& textureId)
{
    return textures[textureId];
}



void AssetManager::AddMap(const std::string& mapId, const std::string& filePath)
{
    tilemaps.emplace(mapId, filePath);
}
std::string AssetManager::GetMap(const std::string& mapId)
{
    return tilemaps[mapId];
}