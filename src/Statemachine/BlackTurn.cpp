


#include "Statemachine/BlackTurn.hpp"
#include "Statemachine/WhiteTurn.hpp"


void BlackTurn::Select(Statemachine* statemachine) 
{
    std::cout << "Black selecting piece " << std::endl;
}   
void BlackTurn::Move(Statemachine* statemachine) 
{
    std::cout << "Black moves piece " << std::endl;
    WhiteTurn* state = new WhiteTurn();
    statemachine->SetCurrentState(state);

    delete this;
}

