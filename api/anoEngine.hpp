#ifndef _API_anoEngine_HPP_
#define _API_anoEngine_HPP_

#include <string>
#include<algorithm>

using Entity = unsigned int;

struct TransformComponent;
struct PositionComponent;
struct SpriteComponent;
struct ColliderComponent;
struct UserInputComponent;


#include "types/types.hpp"

namespace anoEngine
{
    void Initialize();
    bool IsRunning();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();

    const float GetDeltaTime();
    const Vector2d GetWindowSize();

    void RemoveAllComponents(Entity entity);
    
    void AddTexture(const std::string& textureId, const char* filePath);
    void AddFont(const std::string& fontId, const char* filePath, int fontSize);
    const Entity CreateEntity();




    namespace Transform {

        void Create(const Entity entity, const int x, const int y, const int width, const int height, const Vector2d& velocity, const int scale);
        void Create(const Entity entity, const Rectangle& rectangle, const Vector2d& velocity, const int scale);
        const TransformComponent GetComponent(const Entity entity);
        void SetRectangle(const Entity entity, const Rectangle& position);
        void SetVelocity(const Entity entity, const int x, const int y);
        void SetVelocity(const Entity entity, const Vector2d& velocity);
        void Remove(const Entity entity);
    }




    namespace Position {
        void Create(const Entity entity, const Vector2d& setPosition, const Vector2d& maxVelocity, const Vector2d& kp, const Vector2d& ki, const Vector2d& kd);
        const PositionComponent GetComponent(const Entity entity);
        void SetPosition(const Entity entity, const Vector2d& position);
        void SetMaxVelocity(const Entity entity, const Vector2d& maxVelocity);
        void Remove(const Entity entity);

    }




    namespace UserInput {
        void Create(const Entity entity, const std::string& inputScript);
        const UserInputComponent GetComponent(const Entity entity);
        void Remove(const Entity entity);
    }




    namespace Sprite {

        enum class Layer {
            layer_0 = 0,
            layer_1 = 1,
            layer_2 = 2,
            layer_3 = 3,
            layer_4 = 4,
            layer_count = 5
        };

        enum class Flip {
            none = 0,
            horizontal = 1,
            vertical = 2
        };

        Layer operator++(Layer& next);
        Layer operator*(Layer layer);
        Layer begin(Layer layer);
        Layer end(Layer layer);

        void Create(const Entity entity, const std::string& textureId, Rectangle source, Rectangle destination, Flip flip, Layer layer);
        const SpriteComponent GetComponent(const Entity entity); 
        void UpdateSourceRect(const Entity entity, Rectangle source);
        void UpdateDestinationRect(const Entity entity, Rectangle  destination);
        void UpdateTextureId(const Entity entity, const std::string& textureId);
        void FlipSprite(const Entity entity, const Flip flip);
        void Remove(const Entity entity);
    }




    namespace Collider {

        void Create(const Entity entity, const float offset, const std::string& type, const bool active);
        const ColliderComponent GetComponent(const Entity entity);
        void Activate(const Entity entity);
        void Deactivate(const Entity entity);
        void Remove(const Entity entity);
        bool CollisionDetected(const Entity entity);
        std::string CollidesWithType(const Entity entity);
    }




    namespace Textlabel {
        void Create(const Entity entity, const std::string& text, const anoEngine::Rectangle& position, const std::string& fontId, const anoEngine::Color& color);
    }





    namespace TileMap {
        void Create(const Entity entity, const std::string& filePath, const std::string& textureId);
        void LoadMap(const Entity entity);
    }


    
    namespace Inputs {
        bool MouseButtonLeftClick();
        bool MouseButtonLeftUp();
        bool MouseButtonLeftDown();
        bool MouseButtonRightClick();
        bool MouseButtonRightUp();
        bool MouseButtonRightDown();
        Vector2d GetMouseCoordinates();
    }

}




#include "Components/TransformComponent.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/ColliderComponent.hpp"
#include "Components/UserInputComponent.hpp"

#endif