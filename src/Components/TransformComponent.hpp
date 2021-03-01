#ifndef _COMPONENTS_TRANSFORMCOMPONENT_HPP_
#define _COMPONENTS_TRANSFORMCOMPONENT_HPP_

#include <SDL2/SDL.h>

#include "Components/Component.hpp"
#include "glm/glm.hpp"

#include "SimpleChess.hpp"
#include "Log.hpp"

#include "Constants.hpp"

#include "ChessBoard.hpp"

extern std::shared_ptr<ChessBoard> chessBoard;

class TransformComponent : public Component
{
public:
    glm::vec2 ActPosition;
    glm::vec2 velocity;
    std::string square;

    int width_;
    int height_;
    int scale_;
    int offset_;

    TransformComponent(
        int pos_x, 
        int pos_y, 
        int vel_x, 
        int vel_y, 
        int width,
        int height,
        int scale,
        int offset) :
        ActPosition(glm::vec2(pos_x+offset, pos_y+offset)),
        setPosition(ActPosition),
        velocity(glm::vec2(vel_x, vel_y)),
        width_(width),
        height_(height),
        scale_(scale) ,
        offset_(offset)
        { }


    void Initialize() override 
    { 
        square = chessBoard->GetSquareTitleByCoordinates(ActPosition);
        Logger::Log(logging::trivial::debug, log_location, "creating: ", Owner->name , " at " , square);
    }


    void Update(float deltaTime) override 
    {
        velocity.x = calculateVelocity(setPosition.x, ActPosition.x);
        velocity.y = calculateVelocity(setPosition.y, ActPosition.y);

        ActPosition.x += velocity.x * deltaTime;
        ActPosition.y += velocity.y * deltaTime;
    }

    void SetPosition(int x, int y)
    {
        setPosition_internal(glm::vec2(x,y), chessBoard->GetSquareTitleByCoordinates(glm::vec2(x,y)));
    }

    void SetPosition(glm::vec2 newPosition)
    {
        setPosition_internal(newPosition, chessBoard->GetSquareTitleByCoordinates(newPosition));
    }

    void SetPosition(std::string title)
    {
        setPosition_internal( chessBoard->GetCoordinatesFromSquare(title), title );
    }


private: 
    glm::vec2 setPosition;

    void setPosition_internal(glm::vec2 position, std::string title)
    {
        Logger::Log(logging::trivial::debug, log_location, Owner->name  , ": " , square, "->" , title);
        setPosition = position + glm::vec2(offset_, offset_);
        square = title; 
    }

    int calculateVelocity(int position_set, int position_act)
    {
        if (position_set - position_act > 0)
            return Constants::chessfigures_velocity;
        else if (position_set - position_act < 0)
            return (-1 * Constants::chessfigures_velocity);
        else return 0;
    }

};

#endif
