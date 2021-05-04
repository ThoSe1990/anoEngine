
#ifndef _COMPONENTS_TEXTLABELCOMPONENT_HPP_
#define _COMPONENTS_TEXTLABELCOMPONENT_HPP_

#include "ezEngine.hpp"

struct TextlabelComponent
{

    TextlabelComponent () {}
    TextlabelComponent (Entity Owner) { }
    
    Entity owner;

    ezEngine::Rectangle position;
    std::string text;
    std::string fontFamily;
    ezEngine::Color color;
    std::string textureId;

};


#endif