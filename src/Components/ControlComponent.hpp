#ifndef _COMPONENTS_CONTROLCOMPONENT_HPP_
#define _COMPONENTS_CONTROLCOMPONENT_HPP_

#include "SimpleChess.hpp"
#include "Entity/EntityManager.hpp"
#include "Components/Component.hpp"
#include "Components/TransformComponent.hpp"
#include "Log.hpp"


class ControlComponent : public Component
{
public: 

    TransformComponent* transformComponent; 
    
    void Initialize() override 
    {
        transformComponent = Owner->GetComponent<TransformComponent>();
    }   

    void Update (float deltaTime) override 
    {
        if (SimpleChess::event.type == SDL_MOUSEBUTTONDOWN) 
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::string square = chessBoard->GetSquareTitleByCoordinates(glm::vec2(x,y));
            transformComponent->SetPosition( square );
            Logger::Log(logging::trivial::debug, log_location, "moving to ", square);

        }
    } 


};

#endif