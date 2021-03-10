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
    virtual void UpdateGame(std::shared_ptr<Chesscontroller> chesscontroller) = 0;  
};



class Chesscontroller : public std::enable_shared_from_this<Chesscontroller>
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

public:

    Chesscontroller(State* state, std::vector<Entity*> ChessPieces, std::vector<Entity*> ValidationEntities);
    ~Chesscontroller ();

    void Update();

    void SetState(State* state) ;
    void SetClickedSquare(int x, int y);

    void SetSelectedPiece(Entity* entity);
    Entity* GetSelectedPiece() const; 

    void SetMouseClick();
    bool GetMouseClick();

    bool MoveSelectedPiece();
    bool HasValidMoves();
    bool IsValidMove(std::string square);
    bool IsValidPosition(std::string square);
    
    void ResetValidation();    
    void SetValidation(std::string square, std::string assetId);
    void CaptureOpponent(std::string square);

    Entity* GetEntityFromSqaure(std::string square) const;
    std::tuple<Entity*, std::string, std::string> GetClickedPieceColorSquare() const;   
    std::tuple<std::string, std::string> GetColorAndPosition(Entity* entity) const;

};






#endif