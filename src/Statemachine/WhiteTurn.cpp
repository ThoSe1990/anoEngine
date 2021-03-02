

#include "Statemachine/WhiteTurn.hpp"
#include "Statemachine/BlackTurn.hpp"

void WhiteTurn::Select(Statemachine* statemachine)  
{
    
    std::cout << "White selecting piece " << std::endl;
}   
void WhiteTurn::Move(Statemachine* statemachine)  
{
    std::cout << "White moves piece " << std::endl;
    BlackTurn* state = new BlackTurn();
    statemachine->SetCurrentState(state);

    delete this;
}