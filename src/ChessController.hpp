#ifndef _CHESSCONTROLLER_HPP_
#define _CHESSCONTROLLER_HPP_

#include "SimpleChess.hpp"
#include "Entity/EntityManager.hpp"
#include "Entity/Entity.hpp"
#include "Components/Component.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/ChesspieceComponent.hpp"
#include "Constants.hpp"
#include "Log.hpp"

extern EntityManager manager;

class ChessController 
{
private:
    std::vector<Entity*> chessPieces;
    Entity* selectedPiece;
    
    glm::vec2 mousePosition;
    bool mouseButtonPressed = false;

    // std::map<std::string, Entity*> positionsWithPieces;
    bool SquareOccupied(std::string square);

public: 

    ChessController(std::vector<Entity*> ChessPieces);

    void SetMousebutton(bool mousebutton);
    void SetMousePosition(int x, int y);
    void UpdateGame ();

};

#endif