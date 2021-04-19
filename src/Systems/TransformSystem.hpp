
#ifndef _SYSTEMS_TRANSFORMSYSTEM_HPP_
#define _SYSTEMS_TRANSFORMSYSTEM_HPP_

#include "Constants.hpp"
#include "Systems/System.hpp"
#include "Components/Components.hpp"

class TransformSystem : public System
{
public:

    void Initialize() override 
    {

    }

    void Update(float deltaTime) override 
    {
        auto& components = Components::GetInstance();

        for (size_t i = 0 ; i<components.TransformManager->GetCount() ; i++)
        {
            auto transform = components.TransformManager->at(i);
            transform->velocity.x = calculateVelocity(transform->setPosition.x, transform->actPosition.x);
            transform->velocity.y = calculateVelocity(transform->setPosition.y, transform->actPosition.y);

            transform->actPosition.x += transform->velocity.x * deltaTime;
            transform->actPosition.y += transform->velocity.y * deltaTime;
        }
    }

    void Render() override  
    {

    }


private:
    int calculateVelocity(int position_set, int position_act)
    {
        if (position_set - position_act > 0)
            return Constants::chespieces_velocity;
        else if (position_set - position_act < 0)
            return (-1 * Constants::chespieces_velocity);
        else return 0;
    }

};

#endif