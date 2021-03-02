#ifndef _STATEMACHINE_STATEMACHINE_HPP_
#define _STATEMACHINE_STATEMACHINE_HPP_

#include <iostream>
#include "glm/glm.hpp"
#include "Entity/EntityManager.hpp"
#include "Entity/Entity.hpp"
#include "Components/Component.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/ChesspieceComponent.hpp"

class Statemachine;

class State
{
public:
    virtual ~State() {}
    virtual void Select(Statemachine* Statemachine) {}
    virtual void Move(Statemachine* Statemachine) {}
};



class Statemachine
{
private:
    State *currentState;
    
    std::vector<Entity*> chessPieces;
    Entity* selectedPiece;

    glm::vec2 mousePosition;
    bool mouseButtonPressed = false;

public:
    Statemachine(State* state, std::vector<Entity*> ChessPieces);
    ~Statemachine ();

    void UpdateGame ();

    void SetCurrentState(State* state) ;
    void SelectPiece();
    void MovePiece();

    void SetMousebutton(bool mousebutton);
    void SetMousePosition(int x, int y);
};






#endif