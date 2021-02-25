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

public: 

    ChessController(std::vector<Entity*> ChessPieces) 
     : chessPieces(ChessPieces) 
     { }

    void UpdateGame ()  
    {
        if (SimpleChess::event.type == SDL_MOUSEBUTTONDOWN) 
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::string square = chessBoard->GetSquareTitleByCoordinates(glm::vec2(x,y));
            
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

            TransformComponent* tc = selectedPiece->GetComponent<TransformComponent>();
            tc->SetPosition(square);
        }
    } 

};

#endif