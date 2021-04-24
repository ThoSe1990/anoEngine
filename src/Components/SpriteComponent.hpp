
#ifndef _COMPONENTS_SPRITECOMPONENT_HPP_
#define _COMPONENTS_SPRITECOMPONENT_HPP_

#include <SDL2/SDL.h>
#include "api/ezEngine.hpp"

struct SpriteComponent
{
    SpriteComponent(){}
    SpriteComponent(Entity Owner, SDL_Texture* Texture, SDL_Rect Source, SDL_Rect Destination, ezEngine::SpriteComponent::Layer Layer)
    {
        owner = Owner;
        
        texture = Texture;

        destination.x = Destination.x;
        destination.y = Destination.y;
        destination.w = Destination.w;
        destination.h = Destination.h;

        source.x = Source.x;
        source.y = Source.y;
        source.w = Source.w;
        source.h = Source.h;

        layer = Layer;
    }

    Entity owner;
    SDL_Texture* texture;
    SDL_Rect source;
    SDL_Rect destination;

    ezEngine::SpriteComponent::Layer layer;

};


#endif