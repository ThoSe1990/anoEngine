#ifndef _SYSTEMS_SPRITESYSTEM_HPP_
#define _SYSTEMS_SPRITESYSTEM_HPP_

#include "Systems/System.hpp"
#include "Components/Components.hpp"
#include "TextureManager.hpp"

class SpriteSystem : public System
{
public:

    void Initialize() override 
    {

    }


    void Update(float deltaTime) override 
    {
        auto& components = Components::GetInstance();

        for (size_t i = 0 ; i<components.SpriteManager->GetCount() ; i++)
        {
            auto current = components.SpriteManager->at(i);

            if (components.TransformManager->Has(current->owner))
            {
                auto transform = components.TransformManager->GetComponent(current->owner);
                current->destination.x = transform->actPosition.x;
                current->destination.y = transform->actPosition.y;
            }
        }       
    }
    void Render() override  
    {
        auto& components = Components::GetInstance();

        // TODO not the best, but it will do it for now --> refactor
        for (size_t layer = static_cast<size_t>(Layer::layer_0) ; layer < static_cast<size_t>(Layer::layer_count) ; layer++)
        {
            for (size_t i = 0 ; i<components.SpriteManager->GetCount() ; i++)
            {
                auto current = components.SpriteManager->at(i);
                if (layer == static_cast<size_t>(current->layer))
                    TextureManager::Draw(current->texture, current->source, current->destination, SDL_FLIP_NONE);
            }
        }

    }

};



#endif