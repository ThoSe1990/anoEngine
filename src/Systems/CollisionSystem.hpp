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

                if ( checkCollision( currentTransform->rectangle * current->offset, 
                                    otherTransform->rectangle * other->offset) ) 
                {
                    current->collision = true;
                    current->collisionWithType = other->type;
                    current->collisionWithEntity = other->owner;
                    return;
                } 
                else
                {
                    current->collision = false;
                    current->collisionWithType = std::string("");
                    current->collisionWithEntity = 0;
                }
            } 
        }       
    }

    void Render() override  
    {

    }

private:

    bool checkCollision(const anoEngine::Rectangle& rectangleA, const anoEngine::Rectangle& rectangleB) 
    {
        return (
            rectangleA.x + rectangleA.w >= rectangleB.x &&
            rectangleB.x + rectangleB.w >= rectangleA.x &&
            rectangleA.y + rectangleA.h >= rectangleB.y &&
            rectangleB.y + rectangleB.h >= rectangleA.y
        );

    }

};

#endif