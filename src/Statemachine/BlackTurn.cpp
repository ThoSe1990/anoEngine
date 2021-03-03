


#include "Statemachine/BlackTurn.hpp"
#include "Statemachine/WhiteTurn.hpp"
#include "Components/ChesspieceComponent.hpp"

void BlackTurn::NextTurn(Statemachine* statemachine) 
{
    Logger::Log(logging::trivial::debug, log_location, "black moves piece" );
    WhiteTurn* state = new WhiteTurn();
    statemachine->SetCurrentState(state);
    delete this;
}

void BlackTurn::SetSelectedPiece(Statemachine* statemachine, Entity* entity) 
{
    ChesspieceComponent* cp = entity->GetComponent<ChesspieceComponent>();
    if (cp->color_.compare("black") == 0)
    {
        Logger::Log(logging::trivial::debug, log_location, "selected: " , entity->name);
        this->selected = entity;
        statemachine->rdyToMove = true;
    }
}

