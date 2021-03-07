#ifndef _CHESSCONTROLLER_CHESSCONTROLLER_HPP_
#define _CHESSCONTROLLER_CHESSCONTROLLER_HPP_

#include <iostream>
#include <tuple>
#include "glm/glm.hpp"

#include "Entity/EntityManager.hpp"
#include "Entity/Entity.hpp"

#include "Components/Component.hpp"

#include "Log.hpp"



class Chesscontroller;

class State
{
public:
    virtual ~State() {}
    virtual void UpdateGame(Chesscontroller* chesscontroller) = 0;  
};



class Chesscontroller
{
private:
    State* currentState;
    Entity* selectedPiece;

    std::vector<Entity*> chessPieces;
    std::vector<Entity*> validationEntities;

    std::string clickedSquare;
    bool mouseClick = false;

    std::string getColorOfPiece(Entity* piece) const;
    Entity* getClickedEntity() const;
    Entity* getEntityFromSqaure(std::string square) const;

public:

    Chesscontroller(State* state, std::vector<Entity*> ChessPieces, std::vector<Entity*> ValidationEntities);
    ~Chesscontroller ();

    void Update();

    void SetState(State* state) ;
    void SetClickedSquare(int x, int y);
    void SetSelectedPiece(Entity* entity);
    void SetMouseClick();
    bool GetMouseClick();
    bool MoveSelectedPiece();

    void ResetValidation();    
    void SetValidation(std::string square, std::string assetId);


    std::tuple<Entity*, std::string> GetClickedPieceAndColor() const;   
    std::tuple<Entity*, std::string> GetPieceAndColor(std::string square) const;   
    std::tuple<Entity*, std::string> GetSelectedPieceAndColor() const;   



};






#endif