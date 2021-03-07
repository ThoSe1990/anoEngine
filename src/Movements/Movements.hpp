#ifndef _MOVEMENTS_MOVEMENT_HPP_
#define _MOVEMENTS_MOVEMENT_HPP_

#include "Constants.hpp"

#include "Entity/Entity.hpp"

#include "Components/ChesspieceComponent.hpp"
#include "Components/TransformComponent.hpp"

class Movement
{

public:
    virtual ~Movement() {}
    virtual void CreateValidMovements(Chesscontroller* chesscontroller, Entity* piece) { }
};






#endif