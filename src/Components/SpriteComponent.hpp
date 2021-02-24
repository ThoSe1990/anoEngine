
#ifndef _COMPONENTS_SPRITECOMPONENT_HPP_
#define _COMPONENTS_SPRITECOMPONENT_HPP_

#include <SDL2/SDL.h>
#include "TextureManager.hpp"
#include "AssetManager.hpp"

class SpriteComponent: public Component 
{
private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    

public:
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    SpriteComponent(const char* filePath) 
    {
        SetTexture(filePath);
    }

    void SetTexture(std::string assetTextureId) 
    {
        texture = SimpleChess::assetManager->GetTexture(assetTextureId);
    }

    void Initialize() override 
    {
        transform = Owner->GetComponent<TransformComponent>();
        sourceRectangle.x = 0;
        sourceRectangle.y = 0;
        sourceRectangle.w = transform->width_;
        sourceRectangle.h = transform->height_;
    }

    void Update(float deltaTime) override 
    {
        destinationRectangle.x = static_cast<int>(transform->ActPosition.x);
        destinationRectangle.y = static_cast<int>(transform->ActPosition.y);
        destinationRectangle.w = transform->width_ * transform->scale_;
        destinationRectangle.h = transform->height_ * transform->scale_;
    }

    void Render() override 
    {
        TextureManager::Draw(texture, sourceRectangle, destinationRectangle, spriteFlip);
    }
};


#endif