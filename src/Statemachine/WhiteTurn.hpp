
#ifndef _STATEMACHINE_WHITETURN_HPP_
#define _STATEMACHINE_WHITETURN_HPP_

#include "Statemachine/Statemachine.hpp"

class WhiteTurn : public State
{
public:
    void Select(Statemachine* Statemachine) override ;
    void Move(Statemachine* Statemachine) override ;
};


#endif