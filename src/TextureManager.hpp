#ifndef _TEXTUREMANAGER_HPP_
#define _TEXTUREMANAGER_HPP_

#include "SimpleChess.hpp"

class TextureManager 
{
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip);
};

#endif
