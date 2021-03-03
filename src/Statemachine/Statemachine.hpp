#ifndef _STATEMACHINE_STATEMACHINE_HPP_
#define _STATEMACHINE_STATEMACHINE_HPP_

#include <iostream>
#include "glm/glm.hpp"
#include "Entity/EntityManager.hpp"
#include "Entity/Entity.hpp"
#include "Components/Component.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/ChesspieceComponent.hpp"

#include "Log.hpp"

class Statemachine;

class State
{
protected: 
    Entity* selected;
public:
    virtual ~State() {}
    virtual void Select(Statemachine* Statemachine) = 0;
    virtual void Move(Statemachine* Statemachine) = 0;
    virtual void SetSelectedPiece(Statemachine* statemachine, std::string square) = 0;

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

    void UpdateStatemachine ();

    void SetCurrentState(State* state) ;
    void SetSelectedPiece();
    void CallSelect();
    void CallMove();
    void ProcessMouseclick();
    
    Entity* GetEntityFromSquare(std::string square);


    void SetMousebutton(bool mousebutton);
    void SetMousePosition(int x, int y);
};






#endif