

#include "Statemachine/WhiteTurn.hpp"
#include "Statemachine/BlackTurn.hpp"
#include "Components/ChesspieceComponent.hpp"


void WhiteTurn::NextTurn(Statemachine* statemachine)  
{
    Logger::Log(logging::trivial::debug, log_location, "white moves piece" );
    BlackTurn* state = new BlackTurn();
    statemachine->SetCurrentState(state);
    delete this;
}

void WhiteTurn::SetSelectedPiece(Statemachine* statemachine, Entity* entity) 
{
    ChesspieceComponent* cp = entity->GetComponent<ChesspieceComponent>();
    if (cp->color_.compare("white") == 0)
    {
        Logger::Log(logging::trivial::debug, log_location, "selected: " , entity->name);
        this->selected = entity;
        statemachine->rdyToMove = true;
    }

}
