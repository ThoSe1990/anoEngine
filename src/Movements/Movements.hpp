#ifndef _MOVEMENTS_MOVEMENT_HPP_
#define _MOVEMENTS_MOVEMENT_HPP_

#include "Constants.hpp"

#include "Entity/Entity.hpp"

#include "Components/ChesspieceComponent.hpp"
#include "Components/TransformComponent.hpp"

class Movement
{
protected: 

    std::tuple<std::string, std::string> getColorAndPosition(Entity* piece)
    {
        ChesspieceComponent* cp = piece->GetComponent<ChesspieceComponent>();
        TransformComponent* tp = piece->GetComponent<TransformComponent>();
        return std::make_tuple(cp->color_, tp->square);
    }

public:
    virtual ~Movement() {}
    virtual std::map<std::string, std::string> GetMovements(Chesscontroller* chesscontroller, Entity* piece)
    {
        std::map<std::string, std::string> empty;
        return empty;
    }
};






#endif