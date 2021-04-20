#ifndef _CHESS_MOVEMENTS_MOVEMENTSFACTORY_HPP_
#define _CHESS_MOVEMENTS_MOVEMENTSFACTORY_HPP_

#include <memory>

#include "Log.hpp"
#include "Components/Components.hpp"
#include "Chess/Movements/Movement.hpp"
#include "Chess/Movements/Pawn.hpp"
#include "Chess/Movements/Knight.hpp"
#include "Chess/Movements/Bishop.hpp"
#include "Chess/Movements/Rook.hpp"
#include "Chess/Movements/Queen.hpp"
#include "Chess/Movements/King.hpp"

using Entity = unsigned int;


class MovementFactory
{
public:

    static std::unique_ptr<Movement> Create(Entity entity)
    {
        auto& components = Components::GetInstance();
        auto cp = components.ChesspieceManager->GetComponent(entity);

        if (cp->type.compare("pawn") == 0)
        {
            return std::make_unique<Pawn>(std::move(cp));
        }
        else if (cp->type.compare("knight") == 0)
        {
            return std::make_unique<Knight>(std::move(cp));
        }
        else if (cp->type.compare("bishop") == 0)
        {
            return std::make_unique<Bishop>(std::move(cp));
        }
        else if (cp->type.compare("rook") == 0)
        {
            return std::make_unique<Rook>(std::move(cp));
        }
        else if (cp->type.compare("queen") == 0)
        {
            return std::make_unique<Queen>(std::move(cp));
        }
        else if (cp->type.compare("king") == 0)
        {
            return std::make_unique<King>(std::move(cp));
        }
        else
        {
            Logger::Log(logging::trivial::debug, log_location, "no movements found for " , cp->color, ' ', cp->type);
            return nullptr;
        }

    }   
};

#endif