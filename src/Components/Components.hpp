
#ifndef _COMPONENTS_COMPONENTS_HPP_
#define _COMPONENTS_COMPONENTS_HPP_


#include <memory>
#include "Components/ComponentManager.hpp"
#include "Components/UserInputComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/ColliderComponent.hpp"

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
        SpriteManager->Remove(entity);
        PositionManager->Remove(entity);
        CollisionManager->Remove(entity);
    }


    std::shared_ptr<ComponentManager<UserInputComponent>> UserInputManager = std::make_shared<ComponentManager<UserInputComponent>>();
    std::shared_ptr<ComponentManager<PositionComponent>> PositionManager = std::make_shared<ComponentManager<PositionComponent>>();
    std::shared_ptr<ComponentManager<TransformComponent>> TransformManager = std::make_shared<ComponentManager<TransformComponent>>();
    std::shared_ptr<ComponentManager<SpriteComponent>> SpriteManager = std::make_shared<ComponentManager<SpriteComponent>>();
    std::shared_ptr<ComponentManager<ColliderComponent>> CollisionManager = std::make_shared<ComponentManager<ColliderComponent>>();


private:
    Components() {}
};



#endif