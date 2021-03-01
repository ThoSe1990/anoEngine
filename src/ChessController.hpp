#ifndef _CHESSCONTROLLER_HPP_
#define _CHESSCONTROLLER_HPP_

#include "SimpleChess.hpp"
#include "Entity/EntityManager.hpp"
#include "Entity/Entity.hpp"
#include "Components/Component.hpp"
#include "Components/TransformComponent.hpp"
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

public: 

    ChessController(std::vector<Entity*> ChessPieces) 
     : chessPieces(ChessPieces) 
     { }

    void SetMousebutton(bool mousebutton)
    {
        mouseButtonPressed = mousebutton;
    }

    void SetMousePosition(int x, int y)
    {
        mousePosition.x = x;
        mousePosition.y = y;
    }

    void UpdateGame ()  
    {
        
        if (mouseButtonPressed) 
        {
            std::string square = chessBoard->GetSquareTitleByCoordinates(glm::vec2( static_cast<int>(mousePosition.x),static_cast<int>(mousePosition.y) ));
            
            for (const auto& piece : chessPieces)
            {
                TransformComponent* tc = piece->GetComponent<TransformComponent>();
                if (tc->square.compare(square) == 0)
                {
                    selectedPiece = piece;
                    Logger::Log(logging::trivial::debug, log_location, "selected piece: ", selectedPiece->name);
                    return;
                }
            }    
            if (selectedPiece)
            {
                TransformComponent* tc = selectedPiece->GetComponent<TransformComponent>();
                tc->SetPosition(square);
            }
        }
    } 

};

#endif