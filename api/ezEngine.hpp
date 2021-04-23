#ifndef _ezEngine_HPP_
#define _ezEngine_HPP_

#include <string>
#include "Constants.hpp"

using Entity = unsigned int;


namespace ezEngine
{
    struct Vector2d {
        int x; 
        int y;
    };

    struct Rectangle {
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
    void Create_TransformComponent(const Entity entity, const int x, const int y, const int width, const int height, const unsigned int movingSpeed, const int scale);
    void Update_TransformComponent(const Entity entity, const int x, const int y, const int width, const int height, const unsigned int movingSpeed, const int scale);
    void SetPosition_TransformComponent(const Entity entity, const int x, const int y);
    void Remove_TransformComponent(const Entity entity);


    void Create_SpriteComponent(const Entity entity,  const std::string& textureId, Rectangle source, Rectangle destination, Layer layer);
    void Remove_SpriteComponent(const Entity entity);

    bool MouseClicked();
    Vector2d GetMouseCoordinates();


}




#endif