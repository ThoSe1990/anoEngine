#ifndef _COMPONENTS_TRANSFORMCOMPONENT_HPP_
#define _COMPONENTS_TRANSFORMCOMPONENT_HPP_

#include <SDL2/SDL.h>

#include "Components/Component.hpp"
#include "glm/glm.hpp"

#include "SimpleChess.hpp"

class TransformComponent : public Component
{
public:
    glm::vec2 position;
    glm::vec2 velocity;
    int width_;
    int height_;
    int scale_;

    TransformComponent(
        int pos_x, 
        int pos_y, 
        int vel_x, 
        int vel_y, 
        int width,
        int height,
        int scale) :
        position(glm::vec2(pos_x, pos_y)),
        velocity(glm::vec2(vel_x, vel_y)),
        width_(width),
        height_(height),
        scale_(scale) { }


    void Initialize() override { }

    void Update(float deltaTime) override 
    {
        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;
    }

};

#endif