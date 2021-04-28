
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

    void Update(float deltaTime) override 
    {
        auto& components = Components::GetInstance();

        for (size_t i = 0 ; i<components.PositionManager->GetCount() ; i++)
        {   
            auto positionComponent = components.PositionManager->at(i);
            auto transform = components.TransformManager->GetComponent(positionComponent->owner);
            if (!transform) continue;

            transform->velocity.x = getDirection(positionComponent->velocity.x, positionComponent->setPosition.x, transform->position.x);
            transform->velocity.y = getDirection(positionComponent->velocity.y, positionComponent->setPosition.y, transform->position.y);
        }
    }

    void Render() override  
    {

    }

private:
    int getDirection(int velocity, int position_set, int position_act)
    {
        if (position_set - position_act > 0)
            return velocity;
        else if (position_set - position_act < 0)
            return (-1 * velocity);
        else return 0;
    }

};

#endif