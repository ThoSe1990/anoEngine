

#include "Statemachine/WhiteTurn.hpp"
#include "Statemachine/BlackTurn.hpp"
#include "Components/ChesspieceComponent.hpp"

void WhiteTurn::Select(Statemachine* statemachine)  
{
    
}   

void WhiteTurn::Move(Statemachine* statemachine)  
{
    Logger::Log(logging::trivial::debug, log_location, "white moves piece" );
    BlackTurn* state = new BlackTurn();
    statemachine->SetCurrentState(state);

    delete this;
}

void WhiteTurn::SetSelectedPiece(Statemachine* statemachine, std::string square) 
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
        if (cp->color_.compare("white") == 0)
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
