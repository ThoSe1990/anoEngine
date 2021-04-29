#if defined _WIN32 || defined __CYGWIN__
    #ifdef _EXPORT_DLL
        #ifdef __GNUC__
            #define EZ_ENGINE_PUBLIC __attribute__((dllexport))
        #else
            #define EZ_ENGINE_PUBLIC __declspec(dllexport)
        #endif
    #else
        #ifdef __GNUC__
            #define EZ_ENGINE_PUBLIC __attribute__((dllimport))
        #else
            #define EZ_ENGINE_PUBLIC __declspec(dllimport)
        #endif
    #endif
    #define EZ_ENGINE_HIDDEN
#else
    #if __GNUC__ >= 4
        #define EZ_ENGINE_PUBLIC __attribute__((visibility("default")))
        #define EZ_ENGINE_HIDDEN __attribute__((visibility("hidden")))
    #else
        #define EZ_ENGINE_PUBLIC
        #define EZ_ENGINE_HIDDEN
    #endif
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include "ezEngine.hpp"    
#include "UserInputs.hpp"
#include "Components/Components.hpp"
#include "Constants.hpp"
#include "Game.hpp"

EZ_ENGINE_PUBLIC void ezEngine::Initialize ()
{
    Game::GetInstance().Initialize();
}

EZ_ENGINE_PUBLIC void ezEngine::Initialize_sdl ()
{
    Game::GetInstance().Initialize_sdl();
}

EZ_ENGINE_PUBLIC bool ezEngine::IsRunning()
{
    auto& game = Game::GetInstance();
    return game.IsRunning();
}

EZ_ENGINE_PUBLIC void ezEngine::ProcessInput()
{
    Game::GetInstance().ProcessInput();
}

EZ_ENGINE_PUBLIC void ezEngine::Update()
{
    Game::GetInstance().Update();
}

EZ_ENGINE_PUBLIC void ezEngine::Render()
{
    Game::GetInstance().Render();
}

EZ_ENGINE_PUBLIC void ezEngine::Destroy()
{
    Game::GetInstance().Destroy();
}

EZ_ENGINE_PUBLIC void ezEngine::AddTexture(const std::string& textureId, const char* filePath)
{
    Game::assetManager->AddTexture(textureId, filePath);
}




EZ_ENGINE_PUBLIC const Entity ezEngine::CreateEntity()
{
    return System::AddEntity(); 
}







EZ_ENGINE_PUBLIC void ezEngine::TransformComponent::Create(const Entity entity, const int x, const int y, const int width, const int height, const Vector2d velocity, const int scale)
{
    auto& components = Components::GetInstance();
    components.TransformManager->Create(entity, glm::vec2(x,y), width, height, glm::vec2(velocity.x, velocity.y),  scale);
}


EZ_ENGINE_PUBLIC void ezEngine::TransformComponent::SetPosition(const Entity entity, const int x, const int y)
{
    auto& components = Components::GetInstance();
    auto& transform = components.TransformManager->GetComponent(entity);
    transform->position = glm::vec2(x,y);
}

EZ_ENGINE_PUBLIC void ezEngine::TransformComponent::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.TransformManager->Remove(entity);
}










EZ_ENGINE_PUBLIC void ezEngine::PositionComponent::Create(const Entity entity, Vector2d setPosition, Vector2d velocity)
{
    auto& components = Components::GetInstance();
    components.PositionManager->Create(entity, glm::vec2(setPosition.x, setPosition.y), glm::vec2(velocity.x, velocity.y));
}
EZ_ENGINE_PUBLIC void ezEngine::PositionComponent::SetPosition(const Entity entity, Vector2d position)
{
    auto& components = Components::GetInstance();
    auto positionComponent = components.PositionManager->GetComponent(entity);
    positionComponent->setPosition = glm::vec2(position.x, position.y);
}
EZ_ENGINE_PUBLIC void ezEngine::PositionComponent::SetVelocity(const Entity entity, Vector2d velocity)
{
    auto& components = Components::GetInstance();
    auto position = components.PositionManager->GetComponent(entity);
    position->velocity = glm::vec2(velocity.x, velocity.y);
}
EZ_ENGINE_PUBLIC void ezEngine::PositionComponent::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.PositionManager->Remove(entity);
}









EZ_ENGINE_PUBLIC void ezEngine::UserInputComponent::Create(const Entity entity, const std::string& inputScript)
{
    auto& components = Components::GetInstance();
    components.UserInputManager->Create(entity, inputScript);
}
EZ_ENGINE_PUBLIC void ezEngine::UserInputComponent::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.UserInputManager->Remove(entity);
}









EZ_ENGINE_PUBLIC void ezEngine::SpriteComponent::Create(const Entity entity, const std::string& textureId, ezEngine::Rectangle source, ezEngine::Rectangle destination, ezEngine::SpriteComponent::Layer layer)
{
    auto& components = Components::GetInstance();
    components.SpriteManager->Create(entity, 
        Game::assetManager->GetTexture(textureId.c_str()),     
        SDL_Rect{source.x, source.y, source.w, source.h },
        SDL_Rect{destination.x, destination.y, destination.w, destination.h },
        layer
        );
}

EZ_ENGINE_PUBLIC void ezEngine::SpriteComponent::UpdateSourceRect(const Entity entity, ezEngine::Rectangle source)
{
    auto& components = Components::GetInstance();
    auto& sprite = components.SpriteManager->GetComponent(entity);
    sprite->source = SDL_Rect{source.x, source.y, source.w, source.h };
}
EZ_ENGINE_PUBLIC void ezEngine::SpriteComponent::UpdateDestinationRect(const Entity entity, ezEngine::Rectangle destination)
{
    auto& components = Components::GetInstance();
    auto& sprite = components.SpriteManager->GetComponent(entity);
    sprite->destination = SDL_Rect{destination.x, destination.y, destination.w, destination.h };
}

EZ_ENGINE_PUBLIC void ezEngine::SpriteComponent::UpdateTexture(const Entity entity, const std::string& textureId)
{
    auto& components = Components::GetInstance();
    auto& sprite = components.SpriteManager->GetComponent(entity);
    sprite->texture = Game::assetManager->GetTexture(textureId.c_str());
}
EZ_ENGINE_PUBLIC void ezEngine::SpriteComponent::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.SpriteManager->Remove(entity);
}









EZ_ENGINE_PUBLIC void ezEngine::ColliderComponent::Create(const Entity entity, const std::string& type, const bool active)
{
    auto& components = Components::GetInstance();
    components.CollisionManager->Create(entity, type, active);
}

EZ_ENGINE_PUBLIC void ezEngine::ColliderComponent::Activate(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& collider = components.CollisionManager->GetComponent(entity);
    collider->active = true;
}
EZ_ENGINE_PUBLIC void ezEngine::ColliderComponent::Deactivate(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& collider = components.CollisionManager->GetComponent(entity);
    collider->active = false;
}
EZ_ENGINE_PUBLIC void ezEngine::ColliderComponent::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.CollisionManager->Remove(entity);
}









EZ_ENGINE_PUBLIC bool ezEngine::Inputs::MouseButtonLeftClick()
{
    auto& userInuputs = UserInputs::GetInstance();
    return userInuputs.mouseButtonLeftClick;
}
EZ_ENGINE_PUBLIC bool ezEngine::Inputs::MouseButtonLeftUp()
{
    auto& userInuputs = UserInputs::GetInstance();
    return userInuputs.mouseButtonLeftUp;
}
EZ_ENGINE_PUBLIC bool ezEngine::Inputs::MouseButtonLeftDown()
{
    auto& userInuputs = UserInputs::GetInstance();
    return userInuputs.mouseButtonLeftDown;
}
EZ_ENGINE_PUBLIC bool ezEngine::Inputs::MouseButtonRightClick()
{
    auto& userInuputs = UserInputs::GetInstance();
    return userInuputs.mouseButtonRightClick;
}
EZ_ENGINE_PUBLIC bool ezEngine::Inputs::MouseButtonRightUp()
{
    auto& userInuputs = UserInputs::GetInstance();
    return userInuputs.mouseButtonRightUp;
}
EZ_ENGINE_PUBLIC bool ezEngine::Inputs::MouseButtonRightDown()
{
    auto& userInuputs = UserInputs::GetInstance();
    return userInuputs.mouseButtonRightDown;
}

EZ_ENGINE_PUBLIC ezEngine::Vector2d ezEngine::Inputs::GetMouseCoordinates()
{
    auto& userInuputs = UserInputs::GetInstance();
    return Vector2d{userInuputs.mouseX, userInuputs.mouseY};
}


