


#include "Statemachine/BlackTurn.hpp"
#include "Statemachine/WhiteTurn.hpp"
#include "Components/ChesspieceComponent.hpp"

void BlackTurn::Select(Statemachine* statemachine) 
{

}   
void BlackTurn::Move(Statemachine* statemachine) 
{
    Logger::Log(logging::trivial::debug, log_location, "bblack moves piece" );
    WhiteTurn* state = new WhiteTurn();
    statemachine->SetCurrentState(state);

    delete this;
}

void BlackTurn::SetSelectedPiece(Statemachine* statemachine, std::string square) 
{
    try
    {
        Entity* entity = statemachine->GetEntityFromSquare(square);
        if (!entity) // if entity is nullptr ---> free suqare was selected
        {
            this->Move(statemachine);
            return;
        }
        
        ChesspieceComponent* cp = entity->GetComponent<ChesspieceComponent>();
        if (cp->color_.compare("black") == 0)
        {
            Logger::Log(logging::trivial::debug, log_location, "selected: " , entity->name);
            this->selected = entity;
        }
    }
    catch(const std::exception& e)
    {
        Logger::Log(logging::trivial::debug, log_location, "unhandled exception: \n" , e.what());
    } 
}

