
#ifndef _COMPONENTS_COMPONENTS_HPP_
#define _COMPONENTS_COMPONENTS_HPP_


#include <memory>
#include "Components/ComponentManager.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/ChesspieceComponent.hpp"


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
    std::shared_ptr<ComponentManager<TransformComponent>> TransformManager = std::make_shared<ComponentManager<TransformComponent>>();
    std::shared_ptr<ComponentManager<ChesspieceComponent>> ChesspieceManager = std::make_shared<ComponentManager<ChesspieceComponent>>();
    std::shared_ptr<ComponentManager<SpriteComponent>> SpriteManager = std::make_shared<ComponentManager<SpriteComponent>>();

private:
    Components() {}
};



#endif