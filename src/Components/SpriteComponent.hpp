
#ifndef _COMPONENTS_SPRITECOMPONENT_HPP_
#define _COMPONENTS_SPRITECOMPONENT_HPP_

#include "anoEngine.hpp"

struct SpriteComponent
{
    SpriteComponent(){}
    SpriteComponent(Entity owner, const std::string& textureId, anoEngine::Rectangle source, anoEngine::Rectangle destination, anoEngine::Sprite::Flip flip, anoEngine::Sprite::Layer layer) :
    owner(owner), textureId(textureId), source(source), destination(destination), flip(flip), layer(layer) {}

    Entity owner;
    std::string textureId;
    anoEngine::Rectangle source;
    anoEngine::Rectangle destination;

    anoEngine::Sprite::Flip flip;

    // TODO: still needed in component??
    anoEngine::Sprite::Layer layer;

};


#endif