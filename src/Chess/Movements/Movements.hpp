#ifndef _CHESS_MOVEMENTS_MOVEMENT_HPP_
#define _CHESS_MOVEMENTS_MOVEMENT_HPP_

#include "Components/Components.hpp"
#include "Systems/System.hpp"


class Movement
{
protected: 
    std::string getNextSquare(std::string currentSquare, int directionX, int directionY)
    {
        currentSquare[Movements::x] += directionX;        
        currentSquare[Movements::y] += directionY; 
        return currentSquare;
    }

    void createValidation(const std::string& square, const std::string& opponentsColor)
    {
        auto& components = Components::GetInstance();
        std::string id = "valid_move";
        auto e = GetEntityFromSquare(square);
        if (e && e->color.compare(opponentsColor) == 0)
        {
            id = "valid_capture";
        } else if (e && e->color.compare(opponentsColor) != 0)
            return;
        
        auto coordinates = Chessboard::GetCoordinatesFromSquare(square);
        auto validationEntity = System::AddEntity();     
        components.SpriteManager->Create(validationEntity,
            Game::assetManager->GetTexture(id),
            SDL_Rect{0, 0, Constants::chesspiece_sidelength, Constants::chesspiece_sidelength},
            SDL_Rect{static_cast<int>(coordinates.x), static_cast<int>(coordinates.y), Constants::chesspiece_sidelength, Constants::chesspiece_sidelength},
            Layer::layer_2
        );   
    }

    std::shared_ptr<ChesspieceComponent> GetEntityFromSquare(const std::string& square)
    {   
        auto& components = Components::GetInstance();
        auto lambda = [&square](const auto current)
        {
            return (current->square.compare(square) == 0);
        };

        return components.ChesspieceManager->GetComponent(lambda);
    }

public:
    virtual ~Movement() {}
    virtual void CreateValidMovements() { }
};



#endif