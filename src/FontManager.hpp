#ifndef _FONTMANAGER_HPP_
#define _FONTMANAGER_HPP_

#include "Game.hpp"


class FontManager 
{
public:
    static TTF_Font* LoadFont(const char* fileName, int fontSize);
    static void Draw(SDL_Texture* texture, SDL_Rect position);
};

#endif