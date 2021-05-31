
#ifndef _SYSTEMS_POSITIONSYSTEM_HPP_
#define _SYSTEMS_POSITIONSYSTEM_HPP_

#include "Constants.hpp"
#include "Systems/System.hpp"
#include "Components/Components.hpp"

class PositionSystem : public System
{
public:

    void Initialize() override 
    {

    }


    //TODO refactor, reduce loc
    void Update(float deltaTime) override 
    {
        auto& components = Components::GetInstance();

        for (size_t i = 0 ; i<components.PositionManager->GetCount() ; i++)
        {   
            auto pc = components.PositionManager->at(i);
            auto transform = components.TransformManager->GetComponent(pc->owner);
            if (!transform) continue;
            
            ezEngine::Vector2d error = pc->setPosition - ezEngine::Vector2d{transform->rectangle.x, transform->rectangle.y};
            
            float deltaTimeSeconds = deltaTime * 1000.0f;

            ezEngine::Vector2d kp = pc->kp * error;
            ezEngine::Vector2d ki = pc->ki * error * deltaTimeSeconds;
            ezEngine::Vector2d kd = pc->kd * (error - pc->lastError) / deltaTimeSeconds;

            transform->velocity = kp + ki + kd; 

            if (transform->velocity.x > pc->maxVelocity.x) transform->velocity.x = pc->maxVelocity.x;
            if (transform->velocity.x < (-1)*pc->maxVelocity.x) transform->velocity.x = (-1)*pc->maxVelocity.x;
            
            if (transform->velocity.y > pc->maxVelocity.y) transform->velocity.y = pc->maxVelocity.y;
            if (transform->velocity.y < (-1)*pc->maxVelocity.y) transform->velocity.y = (-1)*pc->maxVelocity.y;

            pc->lastError = error;
            
            if (abs(error.x) < 5)
            {
                error.x = 0;
                transform->rectangle.x = pc->setPosition.x;
                transform->velocity.x = 0;
            }
            if (abs(error.y) < 5)
            {
                error.y = 0;
                transform->rectangle.y = pc->setPosition.y;
                transform->velocity.y = 0;
            }
            
            pc->inPosition = (error == 0);

        }
    }

    void Render() override  
    {

    }

};

#endif