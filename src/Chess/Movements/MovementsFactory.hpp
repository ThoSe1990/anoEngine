#ifndef _MOVEMENTS_MOVEMENTSFACTORY_HPP_
#define _MOVEMENTS_MOVEMENTSFACTORY_HPP_

#include <memory>

#include "Log.hpp"
#include "Components/Components.hpp"
#include "Chess/Movements/Movements.hpp"
#include "Chess/Movements/Pawn.hpp"
// #include "Chess/Movements/Knight.hpp"
// #include "Chess/Movements/Bishop.hpp"
// #include "Chess/Movements/Rook.hpp"
// #include "Chess/Movements/Queen.hpp"
// #include "Chess/Movements/King.hpp"

using Entity = unsigned int;


class MovementFactory
{
public:
    // static std::unique_ptr<Movement> Create(std::shared_ptr<Chesscontroller>& chesscontroller, std::shared_ptr<Entity> entity)
    static std::unique_ptr<Movement> Create(Entity entity)
    {
        auto& components = Components::GetInstance();
        auto cp = components.ChesspieceManager->GetComponent(entity);
        if (cp->type.compare("pawn") == 0)
        {
            return std::make_unique<Pawn>(entity);
        }
        
        return std::make_unique<Movement>();
        // else if (cp->GetType().compare("knight") == 0)
        // {
        //     return std::make_unique<Knight>(chesscontroller, entity);
        // }
        // else if (cp->GetType().compare("bishop") == 0)
        // {
        //     return std::make_unique<Bishop>(chesscontroller, entity);
        // }
        // else if (cp->GetType().compare("rook") == 0)
        // {
        //     return std::make_unique<Rook>(chesscontroller, entity);
        // }
        // else if (cp->GetType().compare("queen") == 0)
        // {
        //     return std::make_unique<Queen>(chesscontroller, entity);
        // }
        // else if (cp->GetType().compare("king") == 0)
        // {
        //     return std::make_unique<King>(chesscontroller, entity);
        // }
        // else
        // {
        //     Logger::Log(logging::trivial::debug, log_location, "no movements found for " , entity->name);
        //     return std::make_unique<Movement>(chesscontroller, entity);
        // }
    }   
};

#endif