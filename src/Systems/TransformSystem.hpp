
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

            transform->rectangle.x += transform->velocity.x * deltaTime;
            transform->rectangle.y += transform->velocity.y * deltaTime;
        }
    }

    void Render() override  
    {

    }

};

#endif