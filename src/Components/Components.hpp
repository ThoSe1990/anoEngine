
#ifndef _COMPONENTS_COMPONENTS_HPP_
#define _COMPONENTS_COMPONENTS_HPP_


#include <memory>
#include <map>
#include "Components/ComponentManager.hpp"
#include "Components/UserInputComponent.hpp"
#include "Components/TileMapComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/ColliderComponent.hpp"
#include "Components/TextlabelComponent.hpp"

class Components
{
public:
    Components(Components const&) = delete;
    void operator=(Components const&) = delete;


    static Components& GetInstance() noexcept
    {
        static Components instance; 
        return instance;
    }

    void RemoveAllComponents(Entity entity)
    {
        UserInputManager->Remove(entity);
        TransformManager->Remove(entity);
        PositionManager->Remove(entity);
        CollisionManager->Remove(entity);
        TextlabelManager->Remove(entity);

        for (const auto& spriteManager : SpriteManagers)
            spriteManager.second->Remove(entity);
  
    }

    std::unique_ptr<ComponentManager<TileMapComponent>> TilemapManager = std::make_unique<ComponentManager<TileMapComponent>>();
    std::unique_ptr<ComponentManager<UserInputComponent>> UserInputManager = std::make_unique<ComponentManager<UserInputComponent>>();
    std::unique_ptr<ComponentManager<PositionComponent>> PositionManager = std::make_unique<ComponentManager<PositionComponent>>();
    std::unique_ptr<ComponentManager<TransformComponent>> TransformManager = std::make_unique<ComponentManager<TransformComponent>>();
    std::unique_ptr<ComponentManager<ColliderComponent>> CollisionManager = std::make_unique<ComponentManager<ColliderComponent>>();
    std::unique_ptr<ComponentManager<TextlabelComponent>> TextlabelManager = std::make_unique<ComponentManager<TextlabelComponent>>();

    std::map<anoEngine::Sprite::Layer, std::unique_ptr<ComponentManager<SpriteComponent>>> SpriteManagers;

private:
    Components() { }
};



#endif