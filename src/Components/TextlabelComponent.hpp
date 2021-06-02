
#ifndef _COMPONENTS_TEXTLABELCOMPONENT_HPP_
#define _COMPONENTS_TEXTLABELCOMPONENT_HPP_

#include "anoEngine.hpp"

struct TextlabelComponent
{

    TextlabelComponent () {}
    TextlabelComponent (Entity owner, const std::string& text, const anoEngine::Rectangle& position, const std::string& fontId, const anoEngine::Color& color) :
    owner(owner), text(text), position(position), fontId(fontId), color(color) { }
    
    Entity owner;

    anoEngine::Rectangle position;
    std::string text;
    std::string fontId;
    anoEngine::Color color;

};


#endif