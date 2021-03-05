#ifndef _STATEMACHINE_STATEMACHINE_HPP_
#define _STATEMACHINE_STATEMACHINE_HPP_

#include <iostream>
#include <tuple>
#include "glm/glm.hpp"

#include "Entity/EntityManager.hpp"
#include "Entity/Entity.hpp"

#include "Components/Component.hpp"

#include "Log.hpp"


class Statemachine;

class State
{
public:
    virtual ~State() {}
    virtual void UpdateGame(Statemachine* statemachine) = 0;  
};



class Statemachine
{
private:
    State* currentState;
    Entity* selectedPiece;

    std::vector<Entity*> chessPieces;
    std::vector<Entity*> validationEntities;

    std::string clickedSquare;
    bool runGameStep;

    std::string getColorOfPiece(Entity* piece) const;
    Entity* getClickedEntity() const;

public:
    glm::vec2 GetMousePosition();

    Statemachine(State* state, std::vector<Entity*> ChessPieces, std::vector<Entity*> ValidationEntities);
    ~Statemachine ();

    void Update();

    void SetState(State* state) ;
    void SetClickedSquare(int x, int y);
    void SetSelectedPiece(Entity* entity);
    void NextGamestep();
    
    bool MoveSelectedPiece();

    void ResetValidation();    
    void SetValidation(std::string square, std::string assetId);

    std::tuple<Entity*, std::string> GetClickedntityAndColor() const;   

};






#endif