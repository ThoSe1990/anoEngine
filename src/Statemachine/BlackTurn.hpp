
#ifndef _STATEMACHINE_BLACKTURN_HPP_
#define _STATEMACHINE_BLACKTURN_HPP_

#include "Statemachine/Statemachine.hpp"

class BlackTurn : public State
{
public:
    void Select(Statemachine* Statemachine) override ;
    void Move(Statemachine* Statemachine) override ;
    void SetSelectedPiece(Statemachine* statemachine, std::string square) override ;

};


#endif