#ifndef _CHESS_MOVEMENTS_MOVEMENT_HPP_
#define _CHESS_MOVEMENTS_MOVEMENT_HPP_

#include "Components/Components.hpp"
#include "Systems/System.hpp"


class Movement
{
    void internal_createValidation(const std::string& square, const std::string textureId)
    {
        auto& components = Components::GetInstance();
        auto coordinates = Chessboard::GetCoordinatesFromSquare(square);
        auto validationEntity = System::AddEntity();     

        components.SpriteManager->Create(validationEntity,
            Game::assetManager->GetTexture(textureId),
            SDL_Rect{0, 0, Constants::chesspiece_sidelength, Constants::chesspiece_sidelength},
            SDL_Rect{static_cast<int>(coordinates.x), static_cast<int>(coordinates.y), Constants::chesspiece_sidelength, Constants::chesspiece_sidelength},
            Layer::layer_2
        );   
    }

protected: 
    std::string getNextSquare(const std::string& currentSquare, int directionX, int directionY)
    {
        std::string next = currentSquare;
        next[Movements::x] += directionX;        
        next[Movements::y] += directionY; 
        return next;
    }


    // TODO dry!!
    void createValidation(const int x, const int y)
    {
        std::string next = getNextSquare(chesspiece->square, x, y);
        if (!Chessboard::IsValidSquare(next))
            return;
        
        std::string textureId = "valid_move";
        auto opponent = Chess::GetChesspieceFromSquare(next);

        if (opponent && opponent->color.compare(opponentColor) == 0)
            textureId = "valid_capture";

        if (opponent && opponent->color.compare(opponentColor) != 0)
            return;
    
        internal_createValidation(next, textureId);
    }

    void createValidation(const std::string& square)
    {
        std::string textureId = "valid_move";
        auto cp = Chess::GetChesspieceFromSquare(square);

        if (cp && cp->color.compare(opponentColor) == 0)
            textureId = "valid_capture";

        if (cp && cp->color.compare(opponentColor) != 0)
            return;

        internal_createValidation(square, textureId);
    }

    void createValidation(const std::string& square, const std::string& textureId)
    {
        internal_createValidation(square, textureId);
    }

    void createValidationMultiSteps(const int directionX, const int directionY)
    {
        std::string nextSquare = chesspiece->square;
        while (true)
        {
            nextSquare = this->getNextSquare(nextSquare, directionX, directionY);

            if (!Chessboard::IsValidSquare(nextSquare))
                break;

            auto pieceOnSquare = Chess::GetChesspieceFromSquare(nextSquare);
            
            if (!pieceOnSquare)
            {
                internal_createValidation(nextSquare, "valid_move");
            }
            else 
            {
                if (pieceOnSquare->color.compare(opponentColor) == 0)
                    internal_createValidation(nextSquare, "valid_capture");    
                break;  
            }
        }
    }

    const std::shared_ptr<ChesspieceComponent>& chesspiece;
    std::string opponentColor;

public:
    Movement(const std::shared_ptr<ChesspieceComponent>& Chesspiece) : chesspiece(Chesspiece)
    {
        opponentColor = (chesspiece->color.compare(Constants::color_black) == 0) ? Constants::color_white : Constants::color_black;
    } 
    virtual ~Movement() {}
    virtual void CreateValidMovements() { }
};



#endif