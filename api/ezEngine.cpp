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
        #define EZ_ENGCINE_HIDDEN
    #endif
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include "ezEngine.hpp"    
#include "UserInputs.hpp"
#include "Components/Components.hpp"
#include "Systems/TextlabelSystem.hpp"
#include "Systems/TileMapSystem.hpp"
#include "Constants.hpp"
#include "Game.hpp"


namespace ezEngine {


    EZ_ENGINE_PUBLIC void Initialize ()
    {
        Game::GetInstance().Initialize();
    }

    EZ_ENGINE_PUBLIC bool IsRunning()
    {
        auto& game = Game::GetInstance();
        return game.IsRunning();
    }

    EZ_ENGINE_PUBLIC void ProcessInput()
    {
        Game::GetInstance().ProcessInput();
    }

    EZ_ENGINE_PUBLIC void Update()
    {
        Game::GetInstance().Update();
    }

    EZ_ENGINE_PUBLIC void Render()
    {
        Game::GetInstance().Render();
    }

    EZ_ENGINE_PUBLIC void Destroy()
    {
        Game::GetInstance().Destroy();
    }

    EZ_ENGINE_PUBLIC const float GetDeltaTime()
    {
        return Game::GetInstance().GetDeltaTime();
    }

    EZ_ENGINE_PUBLIC const Vector2d GetWindowSize()
    {
        auto& game = Game::GetInstance();
        return Vector2d{ static_cast<int>(game.GetWindowWidth()) , static_cast<int>(game.GetWindowHeight()) };
    }







    EZ_ENGINE_PUBLIC void AddTexture(const std::string& textureId, const char* filePath)
    {
        Game::assetManager->AddTexture(textureId, filePath);
    }
    EZ_ENGINE_PUBLIC void AddFont(const std::string& fontId, const char* filePath, int fontSize)
    {
        Game::assetManager->AddFont(fontId, filePath, fontSize);
    }


    EZ_ENGINE_PUBLIC const Entity CreateEntity()
    {
        return System::AddEntity(); 
    }

    EZ_ENGINE_PUBLIC void RemoveAllComponents(Entity entity)
    {
        auto& components = Components::GetInstance();
        components.RemoveAllComponents(entity);
    }








    namespace Transform {


        EZ_ENGINE_PUBLIC void Create(const Entity entity, const int x, const int y, const int width, const int height, const Vector2d& velocity, const int scale)
        {
            auto& components = Components::GetInstance();
            components.TransformManager->Create(entity, Rectangle{x, y, width, height}, velocity,  scale);
        }
        EZ_ENGINE_PUBLIC void Create(const Entity entity, const Rectangle& rectangle, const Vector2d& velocity, const int scale)
        {
            auto& components = Components::GetInstance();
            components.TransformManager->Create(entity, rectangle, velocity, scale);
        }
        EZ_ENGINE_PUBLIC const TransformComponent GetComponent(const Entity entity)
        {
            auto& components = Components::GetInstance();
            auto& transform = components.TransformManager->GetComponent(entity);
            return *transform.get();
        }
        EZ_ENGINE_PUBLIC void SetRectangle(const Entity entity, const Rectangle& rectangle)
        {
            auto& components = Components::GetInstance();
            auto& transform = components.TransformManager->GetComponent(entity);
            transform->rectangle = rectangle;
        }
        EZ_ENGINE_PUBLIC void SetVelocity(const Entity entity, const int x, const int y)
        {
            auto& components = Components::GetInstance();
            auto& transform = components.TransformManager->GetComponent(entity);
            transform->velocity = Vector2d{x,y};
        }
        EZ_ENGINE_PUBLIC void SetVelocity(const Entity entity, const Vector2d& velocity)
        {
            auto& components = Components::GetInstance();
            auto& transform = components.TransformManager->GetComponent(entity);
            transform->velocity = velocity;
        }
        
        EZ_ENGINE_PUBLIC void Remove(const Entity entity)
        {
            auto& components = Components::GetInstance();
            components.TransformManager->Remove(entity);
        }

    }






    namespace Position {


        EZ_ENGINE_PUBLIC void Create(const Entity entity, Vector2d setPosition, Vector2d velocity)
        {
            auto& components = Components::GetInstance();
            components.PositionManager->Create(entity, setPosition, velocity);
        }
        EZ_ENGINE_PUBLIC const PositionComponent GetComponent(const Entity entity)
        {
            auto& components = Components::GetInstance();
            auto& position = components.PositionManager->GetComponent(entity);
            return *position.get();
        }
        EZ_ENGINE_PUBLIC void SetPosition(const Entity entity, Vector2d position)
        {
            auto& components = Components::GetInstance();
            auto positionComponent = components.PositionManager->GetComponent(entity);
            positionComponent->setPosition = position;
        }
        EZ_ENGINE_PUBLIC void SetVelocity(const Entity entity, Vector2d velocity)
        {
            auto& components = Components::GetInstance();
            auto position = components.PositionManager->GetComponent(entity);
            position->velocity = velocity;
        }
        EZ_ENGINE_PUBLIC void Remove(const Entity entity)
        {
            auto& components = Components::GetInstance();
            components.PositionManager->Remove(entity);
        }

    }






    namespace UserInput {

        EZ_ENGINE_PUBLIC void Create(const Entity entity, const std::string& inputScript)
        {
            auto& components = Components::GetInstance();
            components.UserInputManager->Create(entity, inputScript);
        }
        EZ_ENGINE_PUBLIC const UserInputComponent GetComponent(const Entity entity)
        {
            auto& components = Components::GetInstance();
            auto& userInput = components.UserInputManager->GetComponent(entity);
            return *userInput.get();
        }
        EZ_ENGINE_PUBLIC void Remove(const Entity entity)
        {
            auto& components = Components::GetInstance();
            components.UserInputManager->Remove(entity);
        }

    }




    namespace Sprite {
        Layer operator++(Layer& next)
        {
            return next =  static_cast<Layer>(std::underlying_type<Layer>::type(next) + 1);
        }
        Layer operator*(Layer layer) 
        {
            return layer;
        }

        Layer begin(Layer layer) 
        {
            return Layer::layer_0;
        }

        Layer end(Layer layer) 
        {
            return Layer::layer_count;
        }



        EZ_ENGINE_PUBLIC void Create(const Entity entity, const std::string& textureId, ezEngine::Rectangle source, ezEngine::Rectangle destination, Flip flip, Layer layer)
        {
            auto& components = Components::GetInstance();
            components.SpriteManagers.at(layer)->Create(entity,
                textureId,  
                source, 
                destination,
                flip,
                layer
                );
        }
        EZ_ENGINE_PUBLIC const SpriteComponent GetComponent(const Entity entity)
        {
            auto& components = Components::GetInstance();
            for (const auto& spriteManager : components.SpriteManagers)
            {
                auto& sprite = spriteManager.second->GetComponent(entity);
                if (sprite) return *sprite.get();
            }
        }
        EZ_ENGINE_PUBLIC void UpdateSourceRect(const Entity entity, Rectangle source)
        {
            auto& components = Components::GetInstance();
            for (const auto& spriteManager : components.SpriteManagers)
            {
                auto& sprite = spriteManager.second->GetComponent(entity);
                if (!sprite) continue;
                sprite->source = source;
            }
        }
        EZ_ENGINE_PUBLIC void UpdateDestinationRect(const Entity entity, Rectangle destination)
        {
            auto& components = Components::GetInstance();
            for (const auto& spriteManager : components.SpriteManagers)
            {
                auto& sprite = spriteManager.second->GetComponent(entity);
                if (!sprite) continue;
                sprite->destination = destination;
            }
        }
        EZ_ENGINE_PUBLIC void UpdateTextureId(const Entity entity, const std::string& textureId)
        {
            auto& components = Components::GetInstance();
            for (const auto& spriteManager : components.SpriteManagers)
            {
                auto& sprite = spriteManager.second->GetComponent(entity);
                if (!sprite) continue;
                sprite->textureId = textureId;
            }
        }
        EZ_ENGINE_PUBLIC void FlipSprite(const Entity entity, const Flip flip)
        {
            auto& components = Components::GetInstance();
            for (const auto& spriteManager : components.SpriteManagers)
            {
                auto& sprite = spriteManager.second->GetComponent(entity);
                if (!sprite) continue;
                sprite->flip = flip;
            }
        }
        EZ_ENGINE_PUBLIC void Remove(const Entity entity)
        {
            auto& components = Components::GetInstance();
            for (const auto& spriteManager : components.SpriteManagers)
            {
                spriteManager.second->Remove(entity);
            }
        }


    }





    namespace Collider {

        EZ_ENGINE_PUBLIC void Create(const Entity entity, const float offset, const std::string& type, const bool active)
        {
            auto& components = Components::GetInstance();
            components.CollisionManager->Create(entity, offset, type, active);
        }
        EZ_ENGINE_PUBLIC const ColliderComponent GetComponent(const Entity entity)
        {
            auto& components = Components::GetInstance();
            auto& collider = components.CollisionManager->GetComponent(entity);
            return *collider.get();
        }
        EZ_ENGINE_PUBLIC void Activate(const Entity entity)
        {
            auto& components = Components::GetInstance();
            auto& collider = components.CollisionManager->GetComponent(entity);
            collider->active = true;
        }
        EZ_ENGINE_PUBLIC void Deactivate(const Entity entity)
        {
            auto& components = Components::GetInstance();
            auto& collider = components.CollisionManager->GetComponent(entity);
            collider->active = false;
        }
        EZ_ENGINE_PUBLIC void Remove(const Entity entity)
        {
            auto& components = Components::GetInstance();
            components.CollisionManager->Remove(entity);
        }

        EZ_ENGINE_PUBLIC bool CollisionDetected(const Entity entity)
        {
            auto& components = Components::GetInstance();
            auto& collider = components.CollisionManager->GetComponent(entity);
            return collider->collision;
        }
        EZ_ENGINE_PUBLIC std::string CollidesWithType(const Entity entity)
        {
            auto& components = Components::GetInstance();
            auto& collider = components.CollisionManager->GetComponent(entity);
            return collider->collisionWithType;
        }


    }





    namespace Textlabel {


        EZ_ENGINE_PUBLIC void Create(const Entity entity, const std::string& text, const Rectangle& position, const std::string& fontId, const Color& color)
        {
            auto& components = Components::GetInstance();
            auto textlabelComponent = components.TextlabelManager->Create(entity, text, position, fontId, color);
            Game::systemManager->GetSystem<TextlabelSystem>()->AddTextlabel(textlabelComponent);

        }
    }





    namespace TileMap {
        EZ_ENGINE_PUBLIC void Create(const Entity entity, const std::string& filePath, const std::string& textureId, const ezEngine::Vector2d& mapSize, const ezEngine::Vector2d& tileSize, const float scale)
        {
            auto& components = Components::GetInstance();
            components.TilemapManager->Create(entity, filePath, textureId, mapSize, tileSize, scale);
        }
        EZ_ENGINE_PUBLIC void LoadMap(const Entity entity)
        {
            Game::systemManager->GetSystem<TileMapSystem>()->LoadMap(entity);
        }
    }





    namespace Inputs {

        EZ_ENGINE_PUBLIC bool MouseButtonLeftClick()
        {
            auto& userInuputs = UserInputs::GetInstance();
            return userInuputs.mouseButtonLeftClick;
        }
        EZ_ENGINE_PUBLIC bool MouseButtonLeftUp()
        {
            auto& userInuputs = UserInputs::GetInstance();
            return userInuputs.mouseButtonLeftUp;
        }
        EZ_ENGINE_PUBLIC bool MouseButtonLeftDown()
        {
            auto& userInuputs = UserInputs::GetInstance();
            return userInuputs.mouseButtonLeftDown;
        }
        EZ_ENGINE_PUBLIC bool MouseButtonRightClick()
        {
            auto& userInuputs = UserInputs::GetInstance();
            return userInuputs.mouseButtonRightClick;
        }
        EZ_ENGINE_PUBLIC bool MouseButtonRightUp()
        {
            auto& userInuputs = UserInputs::GetInstance();
            return userInuputs.mouseButtonRightUp;
        }
        EZ_ENGINE_PUBLIC bool MouseButtonRightDown()
        {
            auto& userInuputs = UserInputs::GetInstance();
            return userInuputs.mouseButtonRightDown;
        }

        EZ_ENGINE_PUBLIC Vector2d GetMouseCoordinates()
        {
            auto& userInuputs = UserInputs::GetInstance();
            return Vector2d{userInuputs.mouseX, userInuputs.mouseY};
        }

    }

}