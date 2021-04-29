#ifndef _SYSTEM_USERCONTROLSYSTEM_HPP_
#define _SYSTEM_USERCONTROLSYSTEM_HPP_

#include "lua/sol.hpp"

#include "Systems/System.hpp"
#include "Components/Components.hpp"
#include "Game.hpp"
#include "UserInputs.hpp"

class UserControlSystem : public System 
{

    sol::state lua;

public:

    void Initialize() override 
    {
        lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);

        lua["velocity"] = lua.create_table_with(
            "x",0,
            "y",0
        );
    
        lua.new_usertype<UserInputs>("UserInputs",
		    "new", sol::no_constructor,
		    "GetInstance", &UserInputs::GetInstance,
            "mouseButtonLeftClick", &UserInputs::mouseButtonLeftClick,
            "mouseButtonLeftDown", &UserInputs::mouseButtonLeftDown,
            "mouseButtonLeftUp", &UserInputs::mouseButtonLeftUp,
            "keyboard_a", &UserInputs::keyboard_a,
            "keyboard_s", &UserInputs::keyboard_s,
            "keyboard_d", &UserInputs::keyboard_d,
            "keyboard_w", &UserInputs::keyboard_w
		);
    }

    void Update(float deltaTime) override 
    {
        auto& components = Components::GetInstance();
        auto& inputs = UserInputs::GetInstance();

        for (size_t i = 0 ; i<components.UserInputManager->GetCount() ; i++)
        {
            auto inputComponent = components.UserInputManager->at(i);    
            auto transform = components.TransformManager->GetComponent(inputComponent->owner);
            if (!transform) continue;
            
            lua.script_file(inputComponent->inputScript);

            transform->velocity.x = lua["velocity"]["x"].get_or(0);
            transform->velocity.y = lua["velocity"]["y"].get_or(0);
        }        
    }

    void Render() override  
    {

    }

    void SetVelocity(int value_x, int value_y)
    {

    }
};


#endif 