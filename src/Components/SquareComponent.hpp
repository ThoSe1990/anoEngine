#ifndef _COMPONENTS_SQUARECOMPONENT_HPP_
#define _COMPONENTS_SQUARECOMPONENT_HPP_

#include "Components/Component.hpp"
#include "AssetManager.hpp"

#include "glm/glm.hpp"
#include <SDL2/SDL.h>
#include <string>

class SquareComponent : public Component
{
public:
    SDL_Texture *texture;
    SDL_Rect source;
    SDL_Rect destination;
    glm::vec2 position;
    std::string title;

    SquareComponent(int sourceSqureX, int sourceSqureY, int x, int y, int squareSize, int squareScale, const std::string& assetTextureId, const std::string& squareTitle) 
    {
        texture = SimpleChess::assetManager->GetTexture(assetTextureId);

        source.x = sourceSqureX;
        source.y = sourceSqureY;
        source.w = squareSize;
        source.h = squareSize;

        destination.x = x;
        destination.y = y;
        destination.w = squareSize * squareScale;
        destination.h = squareSize * squareScale;

        position.x = x;
        position.y = y;

        title = squareTitle;
    }
    
    ~SquareComponent() 
    {
        SDL_DestroyTexture(texture);
    }

    void Update(float deltaTime) override 
    {
        destination.x = position.x;
        destination.y = position.y;
    }

    void Render() override 
    {
        TextureManager::Draw(texture, source, destination, SDL_FLIP_NONE);
    }

};

#endif