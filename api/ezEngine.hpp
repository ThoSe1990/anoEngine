#ifndef _API_EZENGINE_HPP_
#define _API_EZENGINE_HPP_

#include <string>

using Entity = unsigned int;

struct TransformComponent;

namespace ezEngine
{
    struct Vector2d {
        Vector2d() {}
        Vector2d(const int x, const int y) : x(x), y(y) {}
        int x; 
        int y;
        Vector2d operator+(const Vector2d& other)
        {
            Vector2d v(*this);
            v.x += other.x;
            v.y += other.y;
            return v;
        }
    };

    struct Rectangle {
        Rectangle() {}
        Rectangle(const int x, const int y, const int w, const int h) : x(x), y(y), w(w), h(h) {}
        int x;
        int y;
        int w;
        int h;
    };

    void Initialize_sdl();
    void Initialize();
    bool IsRunning();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();

    void RemoveAllComponents(Entity entity);
    
    void AddTexture(const std::string& textureId, const char* filePath);
    const Entity CreateEntity();

    namespace Transform {

        enum class ControlType {
            Position = 0,
            Velocity = 1
        };
        void Create(const Entity entity, const int x, const int y, const int width, const int height, const Vector2d& velocity, const int scale);
        void Create(const Entity entity, const Rectangle& size, const Vector2d& velocity, const int scale);
        const TransformComponent GetComponent(const Entity entity);
        void SetPosition(const Entity entity, const int x, const int y);
        void Remove(const Entity entity);
    }

    namespace PositionComponent{
        void Create(const Entity entity, Vector2d setPosition, Vector2d velocity);
        void SetPosition(const Entity entity, Vector2d position);
        void SetVelocity(const Entity entity, Vector2d velocity);
        void Remove(const Entity entity);

    }

    namespace UserInputComponent {
        void Create(const Entity entity, const std::string& inputScript);
        void Remove(const Entity entity);
    }

    namespace SpriteComponent {

        enum class Layer {
            layer_0 = 0,
            layer_1 = 1,
            layer_2 = 2,
            layer_3 = 3,
            layer_4 = 4,
            layer_count = 5
        };
        void Create(const Entity entity, const std::string& textureId, Rectangle source, Rectangle destination, ezEngine::SpriteComponent::Layer layer);
        void UpdateSourceRect(const Entity entity, Rectangle source);
        void UpdateDestinationRect(const Entity entity, Rectangle  destination);
        void UpdateTexture(const Entity entity, const std::string& textureId);
        void Remove(const Entity entity);
    }


    namespace ColliderComponent {

        void Create(const Entity entity, const std::string& type, const bool active);
        void Activate(const Entity entity);
        void Deactivate(const Entity entity);
        void Remove(const Entity entity);
        bool CollisionDetected(const Entity entity);
        std::string CollidesWithType(const Entity entity);
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


#endif