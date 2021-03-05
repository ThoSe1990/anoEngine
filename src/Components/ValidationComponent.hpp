
#ifndef _COMPONENTS_VALIDATIONCOMPONENT_HPP_
#define _COMPONENTS_VALIDATIONCOMPONENT_HPP_

#include <SDL2/SDL.h>
#include "TextureManager.hpp"
#include "AssetManager.hpp"

class ValidationComponent: public Component 
{
private:
    SDL_Texture* texture;
    SDL_Rect source;
    SDL_Rect destination;
    glm::vec2 position;
    std::string title_;
    int offset_;

public:
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    std::string GetTitle()
    {
        return title_;
    }

    void SetTextureId(std::string id)
    {
        texture = SimpleChess::assetManager->GetTexture(id);
    }

    ValidationComponent(int x, int y, std::string title, int offset, int sidelength, float scale, std::string textureId) 
    {
        title_ = title;
        texture = SimpleChess::assetManager->GetTexture(textureId);
        source.x = 0;
        source.y = 0;
        source.w = sidelength;
        source.h = sidelength;

        destination.x = x + offset;
        destination.y = y + offset;
        destination.w = sidelength * scale;
        destination.h = sidelength * scale;
    }

    void Render() override 
    {
        TextureManager::Draw(texture, source, destination, spriteFlip);
    }
};


#endif