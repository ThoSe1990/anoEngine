#ifndef _STATEMACHINE_STATEMACHINE_HPP_
#define _STATEMACHINE_STATEMACHINE_HPP_

#include <iostream>
#include "glm/glm.hpp"
#include "Entity/EntityManager.hpp"
#include "Entity/Entity.hpp"
#include "Components/Component.hpp"
#include "Components/ChesspieceComponent.hpp"

#include "Log.hpp"

#include <tuple>

class Statemachine;

class State
{
public:
    Entity* selected;
    virtual ~State() {}
    virtual void NextTurn(Statemachine* Statemachine) = 0;
    virtual void SetSelectedPiece(Statemachine* statemachine, Entity* entity) = 0;  
};



class Statemachine
{
private:
    State *currentState;
    std::vector<Entity*> chessPieces;

    glm::vec2 mousePosition;
    bool mouseButtonPressed = false;

    tuple<Entity*, bool>  GetEntityFromSquare(std::string square);

    
public:
    bool rdyToMove = false;

    Statemachine(State* state, std::vector<Entity*> ChessPieces);
    ~Statemachine ();

    void UpdateStatemachine ();
    void SetCurrentState(State* state) ;
    void SetMousebutton(bool mousebutton);
    void SetMousePosition(int x, int y);
};






#endif