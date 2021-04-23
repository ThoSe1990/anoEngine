#ifndef _CHESS_MOVEMENTS_ROOK_HPP_
#define _CHESS_MOVEMENTS_ROOK_HPP_

#include "Movements/Movement.hpp" 

class Rook : public Movement
{
public:
    Rook(const std::shared_ptr<Chesspiece>& Chesspiece) : Movement(Chesspiece) { }

    void CreateValidMovements() override
    {
        createValidationMultiSteps(Movements::none, Movements::up);
        createValidationMultiSteps(Movements::right, Movements::none);
        createValidationMultiSteps(Movements::none, Movements::down);
        createValidationMultiSteps(Movements::left, Movements::none);
    }

};

#endif