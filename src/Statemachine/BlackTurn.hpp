
#ifndef _STATEMACHINE_BLACKTURN_HPP_
#define _STATEMACHINE_BLACKTURN_HPP_

#include "Statemachine/Statemachine.hpp"

class BlackTurn : public State
{
public:
    void NextTurn(Statemachine* Statemachine) override ;
    void SetSelectedPiece(Statemachine* statemachine, Entity* entity) override ;
};


#endif