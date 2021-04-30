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
            auto currentSprite = components.SpriteManager->GetComponent(current->owner);
            if (!currentSprite) continue;

            for (size_t j = i+1 ; j < components.CollisionManager->GetCount() ; j++ )
            {
                auto other = components.CollisionManager->at(j);
                auto otherSprite = components.SpriteManager->GetComponent(other->owner);
                if (!otherSprite) continue;

                if (checkCollision(currentSprite->destination, otherSprite->destination))
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

    bool checkCollision(const SDL_Rect& rectangleA, const SDL_Rect& rectangleB) 
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