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
            auto& current = components.CollisionManager->at(i);

            for (size_t j = i+1 ; i < components.CollisionManager->GetCount() ; i++ )
            {
                auto& other = components.CollisionManager->at(j)    
                if (!other) return;

                // get rectangles and call check collisions.. 

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