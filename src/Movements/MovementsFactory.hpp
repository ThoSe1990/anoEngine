#ifndef _MOVEMENTS_MOVEMENTSFACTORY_HPP_
#define _MOVEMENTS_MOVEMENTSFACTORY_HPP_

#include "Movements/Movements.hpp"
#include "Movements/Pawn.hpp"
#include "Movements/Knight.hpp"
#include "Movements/Bishop.hpp"
#include "Movements/Rook.hpp"
#include "Movements/Queen.hpp"
#include "Movements/King.hpp"


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
        else if (cp->type_.compare("knight") == 0)
        {
            return std::make_unique<Knight>(entity);
        }
        else if (cp->type_.compare("bishop") == 0)
        {
            return std::make_unique<Bishop>(entity);
        }
        else if (cp->type_.compare("rook") == 0)
        {
            return std::make_unique<Rook>(entity);
        }
        else if (cp->type_.compare("queen") == 0)
        {
            return std::make_unique<Queen>(entity);
        }
        else if (cp->type_.compare("king") == 0)
        {
            return std::make_unique<King>(entity);
        }
        else
        {
            Logger::Log(logging::trivial::debug, log_location, "no movements found for " , entity->name);
            return std::make_unique<Movement>();
        }
    }   
};

#endif