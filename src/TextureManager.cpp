#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
    SDL_Surface* surface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip) 
{
    SDL_RenderCopyEx(Game::renderer, texture, &sourceRectangle, &destinationRectangle, 0.0, NULL, flip);
}

void TextureManager::Draw(const std::string& textureId, const ezEngine::Rectangle& source, const ezEngine::Rectangle& destination, const ezEngine::Sprite::Flip& flip)
{
    SDL_Rect source_{source.x, source.y, source.w, source.h};
    SDL_Rect destination_{destination.x, destination.y, destination.w, destination.h};
    SDL_RenderCopyEx(Game::renderer, Game::assetManager->GetTexture(textureId), &source_, &destination_, 0.0, NULL, static_cast<SDL_RendererFlip>(flip));
}
