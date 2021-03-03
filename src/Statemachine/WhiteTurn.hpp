
#ifndef _STATEMACHINE_WHITETURN_HPP_
#define _STATEMACHINE_WHITETURN_HPP_

#include "Statemachine/Statemachine.hpp"

class WhiteTurn : public State
{
public:
    void NextTurn(Statemachine* Statemachine) override ;
    void SetSelectedPiece(Statemachine* statemachine, Entity* entity) override ;
    
};


#endif