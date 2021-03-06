#ifndef _MOVEMENTS_MOVEMENT_HPP_
#define _MOVEMENTS_MOVEMENT_HPP_

#include "Entity/Entity.hpp"
#include "Components/ChesspieceComponent.hpp"

class Movement
{
public:
    virtual void GetMovements() = 0;
};


class Pawn : public Movement
{
public:
    void GetMovements() override 
    {

    }
};

class MovementFactory
{
public:
    static Movement* Create(Entity* entity)
    {
        ChesspieceComponent* cp = entity->GetComponent<ChesspieceComponent>();
        if (cp->type_.compare("pawn") == 0)
        {
            Logger::Log(logging::trivial::debug, log_location, "creating movements for " , entity->name);
        }
        else
        {
            Logger::Log(logging::trivial::debug, log_location, "no movements found for " , entity->name);
        }
    }   
};

#endif