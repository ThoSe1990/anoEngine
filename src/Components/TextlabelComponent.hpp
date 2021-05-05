
#ifndef _COMPONENTS_TEXTLABELCOMPONENT_HPP_
#define _COMPONENTS_TEXTLABELCOMPONENT_HPP_

#include "ezEngine.hpp"

struct TextlabelComponent
{

    TextlabelComponent () {}
    TextlabelComponent (Entity owner, const std::string& text, const ezEngine::Rectangle& position, const std::string& fontId, const ezEngine::Color& color) :
    owner(owner), text(text), position(position), fontId(fontId), color(color) { }
    
    Entity owner;

    ezEngine::Rectangle position;
    std::string text;
    std::string fontId;
    ezEngine::Color color;

};


#endif