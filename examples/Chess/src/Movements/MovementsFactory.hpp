#ifndef _CHESS_MOVEMENTS_MOVEMENTSFACTORY_HPP_
#define _CHESS_MOVEMENTS_MOVEMENTSFACTORY_HPP_

#include <memory>



#include "Chess.hpp"

#include "Movements/Movement.hpp"
#include "Movements/Pawn.hpp"
#include "Movements/Knight.hpp"
#include "Movements/Bishop.hpp"
#include "Movements/Rook.hpp"
#include "Movements/Queen.hpp"
#include "Movements/King.hpp"


class MovementFactory
{
public:

    static std::unique_ptr<Movement> Create(Entity entity)
    {

        auto lambda = [&entity](const auto& current)
        {
            return current->owner == entity;
        };

        auto it = std::find_if(Chess::AllPieces.begin(), Chess::AllPieces.end(), lambda);
        if (it == Chess::AllPieces.end()) return nullptr;
        
        auto cp = (*it); 

        std::cout << "factory: " << cp->color << cp->type << std::endl;

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
            std::cout << "no movements found for " << cp->color << ' ' << cp->type << std::endl;
            return nullptr;
        }

    }   
};

#endif