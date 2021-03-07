#ifndef _MOVEMENTS_MOVEMENTSFACTORY_HPP_
#define _MOVEMENTS_MOVEMENTSFACTORY_HPP_

#include "Movements/Movements.hpp"
#include "Movements/Pawn.hpp"


class MovementFactory
{
public:
    static std::unique_ptr<Movement> Create(Entity* entity)
    {
        Logger::Log(logging::trivial::debug, log_location, "creating movements for " , entity->name);

        ChesspieceComponent* cp = entity->GetComponent<ChesspieceComponent>();
        if (cp->type_.compare("pawn") == 0)
        {
            return std::make_unique<Pawn>(entity);
        }
        else
        {
            Logger::Log(logging::trivial::debug, log_location, "no movements found for " , entity->name);
            return std::make_unique<Movement>();
        }
    }   
};

#endif