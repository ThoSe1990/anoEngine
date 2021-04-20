#ifndef _CHESS_MOVEMENTS_QUEEN_HPP_
#define _CHESS_MOVEMENTS_QUEEN_HPP_

#include "Chess/Movements/Movement.hpp" 

class Queen : public Movement
{

public:
    Queen(const std::shared_ptr<ChesspieceComponent>& Chesspiece) : Movement(Chesspiece) { }

    void CreateValidMovements() override
    {
        createValidationMultiSteps(Movements::none, Movements::up);
        createValidationMultiSteps(Movements::right, Movements::none);
        createValidationMultiSteps(Movements::none, Movements::down);
        createValidationMultiSteps(Movements::left, Movements::none);
        createValidationMultiSteps(Movements::right, Movements::up);
        createValidationMultiSteps(Movements::right, Movements::down);
        createValidationMultiSteps(Movements::left, Movements::down);
        createValidationMultiSteps(Movements::left, Movements::up);
    }

};

#endif