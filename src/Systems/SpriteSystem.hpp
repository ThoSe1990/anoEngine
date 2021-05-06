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
        auto& components = Components::GetInstance();

        for (const auto& layer : ezEngine::Sprite::Layer() )
            components.SpriteManagers.emplace(layer, std::make_shared<ComponentManager<SpriteComponent>>());
    
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
                current->destination.x = transform->position.x;
                current->destination.y = transform->position.y;
                current->destination.w = transform->width;
                current->destination.h = transform->height;
            }
        }       
    }
    void Render() override  
    {
        auto& components = Components::GetInstance();

        // TODO not the best, but it will do it for now --> refactor
        for (size_t layer = static_cast<size_t>(ezEngine::Sprite::Layer::layer_0) ; layer < static_cast<size_t>(ezEngine::Sprite::Layer::layer_count) ; layer++)
        {
            for (size_t i = 0 ; i<components.SpriteManager->GetCount() ; i++)
            {
                auto current = components.SpriteManager->at(i);
                if (layer == static_cast<size_t>(current->layer))
                    TextureManager::Draw(current->textureId, current->source, current->destination);
            }
            
        }

    }

};



#endif