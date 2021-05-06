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

        for (const auto& layer : ezEngine::Sprite::Layer())
            components.SpriteManagers.emplace(layer, std::make_shared<ComponentManager<SpriteComponent>>());

    }

    void Update(float deltaTime) override 
    {
        auto& components = Components::GetInstance();

        for (const auto& spriteManager : components.SpriteManagers)
        {
            for (size_t i = 0 ; i < spriteManager.second->GetCount() ; i++)
            {
                auto current = spriteManager.second->at(i);

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
    }


    void Render() override  
    {
        auto& components = Components::GetInstance();

        for (const auto& spriteManager : components.SpriteManagers)
        {
            for (size_t i = 0 ; i < spriteManager.second->GetCount() ; i++)
            {
                auto current = spriteManager.second->at(i);
                TextureManager::Draw(current->textureId, current->source, current->destination);
            }
        }

    }

};



#endif