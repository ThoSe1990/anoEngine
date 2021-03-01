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

    TransformComponent(
        std::string positionSquare,
        int width,
        int height,
        int scale) :
        ActPosition(chessBoard->GetCoordinatesFromSquare(std::string(positionSquare))),
        setPosition(ActPosition),
        velocity(glm::vec2(0,0)),
        width_(width),
        height_(height),
        scale_(scale)
        {}

    TransformComponent(
        int pos_x, 
        int pos_y, 
        int vel_x, 
        int vel_y, 
        int width,
        int height,
        int scale) :
        ActPosition(glm::vec2(pos_x, pos_y)),
        setPosition(ActPosition),
        velocity(glm::vec2(vel_x, vel_y)),
        width_(width),
        height_(height),
        scale_(scale)
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
        setPosition = position;
        square = title; 
    }

    int calculateVelocity(int position_set, int position_act)
    {
        if (position_set - position_act > 0)
            return Constants::chespieces_velocity;
        else if (position_set - position_act < 0)
            return (-1 * Constants::chespieces_velocity);
        else return 0;
    }

};

#endif
