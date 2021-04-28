#ifndef _SYSTEM_USERCONTROLSYSTEM_HPP_
#define _SYSTEM_USERCONTROLSYSTEM_HPP_

#include "Systems/System.hpp"
#include "Components/Components.hpp"
#include "Game.hpp"
#include "UserInputs.hpp"

class UserControlSystem : public System 
{

public:

    void Initialize() override 
    {

    }

    void Update(float deltaTime) override 
    {
        auto& components = Components::GetInstance();
        auto& inputs = UserInputs::GetInstance();

        for (size_t i = 0 ; i<components.UserInputManager->GetCount() ; i++)
        {
            auto inputComponent = components.UserInputManager->at(i);    
            if (inputComponent->active == false) continue;

            auto transform = components.TransformManager->GetComponent(inputComponent->owner);
            if (!transform) continue;

            transform->velocity = glm::vec2(0,0);

            if (inputs.keyboard_a)
                transform->velocity.x -= 250;    
            if (inputs.keyboard_d)
                transform->velocity.x += 250;         
            if (inputs.keyboard_s)
                transform->velocity.y += 250;
            if (inputs.keyboard_w)
                transform->velocity.y -= 250;

        }

        
    }

    void Render() override  
    {

    }

};


#endif 