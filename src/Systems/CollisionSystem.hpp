#ifndef _SYSTEMS_COLLISIONSYSTEM_HPP_
#define _SYSTEMS_COLLISIONSYSTEM_HPP_


#include "Systems/System.hpp"
#include "Components/Components.hpp"

class CollisionSystem : public System
{
public:

    void Initialize() override 
    {

    }

    void Update(float deltaTime) override 
    {
        auto& components = Components::GetInstance();

        for (size_t i = 0 ; i < components.CollisionManager->GetCount() ; i++ )
        {
            auto current = components.CollisionManager->at(i);
            auto currentTransform = components.TransformManager->GetComponent(current->owner);
            if (!currentTransform) continue;

            for (size_t j = i+1 ; j < components.CollisionManager->GetCount() ; j++ )
            {
                auto other = components.CollisionManager->at(j);
                auto otherTransform = components.TransformManager->GetComponent(other->owner);
                if (!otherTransform) continue;

                if (checkCollision(currentTransform, otherTransform))
                {
                    current->collision = true;
                    current->collisionWithType = other->type;
                    return;
                } 
                else
                {
                    current->collision = false;
                    current->collisionWithType = std::string("");
                }
            } 
        }       
    }

    void Render() override  
    {

    }

private:

    bool checkCollision(const std::shared_ptr<TransformComponent>& TransformA, const std::shared_ptr<TransformComponent>& TransformB) 
    {
        return (
            TransformA->position.x + TransformA->width >= TransformB->position.x &&
            TransformB->position.x + TransformB->width >= TransformA->position.x &&
            TransformA->position.y + TransformA->height >= TransformB->position.y &&
            TransformB->position.y + TransformB->height >= TransformA->position.y
        );

    }

};

#endif