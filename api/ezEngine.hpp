#ifndef _API_EZENGINE_HPP_
#define _API_EZENGINE_HPP_

#include <string>

using Entity = unsigned int;

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
    
    void AddTexture(const std::string& textureId, const char* filePath);

    const Entity CreateEntity();

    namespace TransformComponent {

        enum class ControlType {
            Position = 0,
            Velocity = 1
        };
        void Create(const Entity entity, ezEngine::TransformComponent::ControlType controlType, const int x, const int y, const int width, const int height, const unsigned int movingSpeed, const int scale);
        void Update(const Entity entity, const int x, const int y, const int width, const int height, const unsigned int movingSpeed, const int scale);
        void SetPosition(const Entity entity, const int x, const int y);
        void Remove(const Entity entity);
        void test(Rectangle test);
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
        void Update(const Entity entity, const std::string& textureId, Rectangle source, Rectangle destination, ezEngine::SpriteComponent::Layer layer);
        void UpdateSourceRect(const Entity entity, Rectangle source);
        void UpdateDestinationRect(const Entity entity, Rectangle  destination);
        void UpdateTexture(const Entity entity, const std::string& textureId);
        void Remove(const Entity entity);
    }


    namespace ColliderComponent {

        void Create(const Entity entity, const std::string& type, const bool active);
        void Update(const Entity entity, const std::string& type, const bool active);
        void Activate(const Entity entity);
        void Deactivate(const Entity entity);
        void Remove(const Entity entity);
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




#endif