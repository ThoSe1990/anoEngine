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

EZ_ENGINE_PUBLIC void ezEngine::RemoveAllComponents(Entity entity)
{
    auto& components = Components::GetInstance();
    components.RemoveAllComponents(entity);
}






EZ_ENGINE_PUBLIC void ezEngine::Transform::Create(const Entity entity, const int x, const int y, const int width, const int height, const Vector2d& velocity, const int scale)
{
    auto& components = Components::GetInstance();
    components.TransformManager->Create(entity, ezEngine::Vector2d{x,y}, width, height, velocity,  scale);
}
EZ_ENGINE_PUBLIC void ezEngine::Transform::Create(const Entity entity, const Rectangle& size, const Vector2d& velocity, const int scale)
{
    auto& components = Components::GetInstance();
    components.TransformManager->Create(entity, ezEngine::Vector2d{size.x,size.y}, size.w, size.h, velocity, scale);
}
EZ_ENGINE_PUBLIC const TransformComponent ezEngine::Transform::GetComponent(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& transform = components.TransformManager->GetComponent(entity);
    return *transform.get();
}
EZ_ENGINE_PUBLIC void ezEngine::Transform::SetPosition(const Entity entity, const int x, const int y)
{
    auto& components = Components::GetInstance();
    auto& transform = components.TransformManager->GetComponent(entity);
    transform->position = ezEngine::Vector2d{x,y};
}

EZ_ENGINE_PUBLIC void ezEngine::Transform::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.TransformManager->Remove(entity);
}








EZ_ENGINE_PUBLIC void ezEngine::Position::Create(const Entity entity, Vector2d setPosition, Vector2d velocity)
{
    auto& components = Components::GetInstance();
    components.PositionManager->Create(entity, setPosition, velocity);
}
EZ_ENGINE_PUBLIC const PositionComponent ezEngine::Position::GetComponent(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& position = components.PositionManager->GetComponent(entity);
    return *position.get();
}
EZ_ENGINE_PUBLIC void ezEngine::Position::SetPosition(const Entity entity, Vector2d position)
{
    auto& components = Components::GetInstance();
    auto positionComponent = components.PositionManager->GetComponent(entity);
    positionComponent->setPosition = position;
}
EZ_ENGINE_PUBLIC void ezEngine::Position::SetVelocity(const Entity entity, Vector2d velocity)
{
    auto& components = Components::GetInstance();
    auto position = components.PositionManager->GetComponent(entity);
    position->velocity = velocity;
}
EZ_ENGINE_PUBLIC void ezEngine::Position::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.PositionManager->Remove(entity);
}









EZ_ENGINE_PUBLIC void ezEngine::UserInput::Create(const Entity entity, const std::string& inputScript)
{
    auto& components = Components::GetInstance();
    components.UserInputManager->Create(entity, inputScript);
}
EZ_ENGINE_PUBLIC const UserInputComponent ezEngine::UserInput::GetComponent(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& userInput = components.UserInputManager->GetComponent(entity);
    return *userInput.get();
}
EZ_ENGINE_PUBLIC void ezEngine::UserInput::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.UserInputManager->Remove(entity);
}









EZ_ENGINE_PUBLIC void ezEngine::Sprite::Create(const Entity entity, const std::string& textureId, ezEngine::Rectangle source, ezEngine::Rectangle destination, ezEngine::Sprite::Layer layer)
{
    auto& components = Components::GetInstance();
    components.SpriteManager->Create(entity, 
        textureId,  
        source, 
        destination,
        layer
        );
}
EZ_ENGINE_PUBLIC const SpriteComponent ezEngine::Sprite::GetComponent(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& sprite = components.SpriteManager->GetComponent(entity);
    return *sprite.get();
}
EZ_ENGINE_PUBLIC void ezEngine::Sprite::UpdateSourceRect(const Entity entity, ezEngine::Rectangle source)
{
    auto& components = Components::GetInstance();
    auto& sprite = components.SpriteManager->GetComponent(entity);
    sprite->source = source;
}
EZ_ENGINE_PUBLIC void ezEngine::Sprite::UpdateDestinationRect(const Entity entity, ezEngine::Rectangle destination)
{
    auto& components = Components::GetInstance();
    auto& sprite = components.SpriteManager->GetComponent(entity);
    sprite->destination = destination;
}

EZ_ENGINE_PUBLIC void ezEngine::Sprite::UpdateTextureId(const Entity entity, const std::string& textureId)
{
    auto& components = Components::GetInstance();
    auto& sprite = components.SpriteManager->GetComponent(entity);
    sprite->textureId = textureId;
}
EZ_ENGINE_PUBLIC void ezEngine::Sprite::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.SpriteManager->Remove(entity);
}









EZ_ENGINE_PUBLIC void ezEngine::Collider::Create(const Entity entity, const std::string& type, const bool active)
{
    auto& components = Components::GetInstance();
    components.CollisionManager->Create(entity, type, active);
}
EZ_ENGINE_PUBLIC const ColliderComponent ezEngine::Collider::GetComponent(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& collider = components.CollisionManager->GetComponent(entity);
    return *collider.get();
}
EZ_ENGINE_PUBLIC void ezEngine::Collider::Activate(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& collider = components.CollisionManager->GetComponent(entity);
    collider->active = true;
}
EZ_ENGINE_PUBLIC void ezEngine::Collider::Deactivate(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& collider = components.CollisionManager->GetComponent(entity);
    collider->active = false;
}
EZ_ENGINE_PUBLIC void ezEngine::Collider::Remove(const Entity entity)
{
    auto& components = Components::GetInstance();
    components.CollisionManager->Remove(entity);
}

EZ_ENGINE_PUBLIC bool ezEngine::Collider::CollisionDetected(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& collider = components.CollisionManager->GetComponent(entity);
    return collider->collision;
}
EZ_ENGINE_PUBLIC std::string ezEngine::Collider::CollidesWithType(const Entity entity)
{
    auto& components = Components::GetInstance();
    auto& collider = components.CollisionManager->GetComponent(entity);
    return collider->collisionWithType;
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


