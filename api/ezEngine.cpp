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


#include "api/ezEngine.hpp"    
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




EZ_ENGINE_PUBLIC void ezEngine::TransformComponent::Create(const Entity entity, const int x, const int y, const int width, const int height, const unsigned int movingSpeed, const int scale)
{
    auto& components = Components::GetInstance();
    components.TransformManager->Create(entity, glm::vec2(x,y), width, height, movingSpeed,  scale);
}

EZ_ENGINE_PUBLIC void ezEngine::TransformComponent::Update(const Entity entity, const int x, const int y, const int width, const int height, const unsigned int movingSpeed, const int scale)
{
    auto& components = Components::GetInstance();
    auto transform = components.TransformManager->GetComponent(entity);
    transform->setPosition = glm::vec2(x,y);
    transform->width = width;
    transform->height = height;
    transform->movingSpeed = movingSpeed;
    transform->scale = scale;
}
EZ_ENGINE_PUBLIC void ezEngine::TransformComponent::SetPosition(const Entity entity, const int x, const int y)
{
    auto& components = Components::GetInstance();
    auto& transform = components.TransformManager->GetComponent(entity);
    transform->setPosition = glm::vec2(x,y);
}

EZ_ENGINE_PUBLIC void ezEngine::TransformComponent::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.TransformManager->Remove(entity);
}




EZ_ENGINE_PUBLIC void ezEngine::SpriteComponent::Create(const Entity entity, const std::string& textureId, Rectangle source, Rectangle destination, ezEngine::SpriteComponent::Layer layer)
{
    auto& components = Components::GetInstance();
    components.SpriteManager->Create(entity, 
        Game::assetManager->GetTexture(textureId.c_str()),     
        SDL_Rect{source.x, source.y, source.w, source.h },
        SDL_Rect{destination.x, destination.y, destination.w, destination.h },
        layer);
}

EZ_ENGINE_PUBLIC void ezEngine::SpriteComponent::Update(const Entity entity, const std::string& textureId, Rectangle source, Rectangle destination, ezEngine::SpriteComponent::Layer layer)
{
    auto& components = Components::GetInstance();
    auto& sprite = components.SpriteManager->GetComponent(entity);
    sprite->texture = Game::assetManager->GetTexture(textureId.c_str());
    sprite->source = SDL_Rect{source.x, source.y, source.w, source.h };
    sprite->destination = SDL_Rect{destination.x, destination.y, destination.w, destination.h };
    
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
EZ_ENGINE_PUBLIC void ezEngine::ColliderComponent::Update(const Entity entity, const std::string& type, const bool active)
{
    auto& components = Components::GetInstance();
    auto& collider = components.CollisionManager->GetComponent(entity);
    collider->type = type;
    collider->active = active;
}
EZ_ENGINE_PUBLIC void ezEngine::ColliderComponent::Activate(const Entity entity)
{
    auto& components = Components::GetInstance();
    collider->active = true;
}
EZ_ENGINE_PUBLIC void ezEngine::ColliderComponent::Deactivate(const Entity entity)
{
    auto& components = Components::GetInstance();
    collider->active = false;
}
EZ_ENGINE_PUBLIC void ezEngine::ColliderComponent::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.CollisionManager->Remove(entity);
}





EZ_ENGINE_PUBLIC bool ezEngine::UserInputs::MouseClicked()
{
    return Game::GetClick();
}

EZ_ENGINE_PUBLIC ezEngine::Vector2d ezEngine::UserInputs::GetMouseCoordinates()
{
    return Vector2d{Game::GetMouseX(), Game::GetMouseY()};
}

