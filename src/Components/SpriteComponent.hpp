
#ifndef _COMPONENTS_SPRITECOMPONENT_HPP_
#define _COMPONENTS_SPRITECOMPONENT_HPP_

#include "ezEngine.hpp"

struct SpriteComponent
{
    SpriteComponent(){}
    SpriteComponent(Entity owner, const std::string& textureId, ezEngine::Rectangle source, ezEngine::Rectangle destination, ezEngine::Sprite::Layer layer) :
    owner(owner), textureId(textureId), source(source), destination(destination), layer(layer) {}

    Entity owner;
    std::string textureId;
    ezEngine::Rectangle source;
    ezEngine::Rectangle destination;
    // TODO: still needed in component??
    ezEngine::Sprite::Layer layer;

};


#endif