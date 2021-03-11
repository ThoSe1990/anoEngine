#include "AssetManager.hpp"
#include "Components/TransformComponent.hpp"

AssetManager::AssetManager(std::shared_ptr<EntityManager> manager) : manager(manager) 
{

}
AssetManager::~AssetManager()
{
    
}

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
