#ifndef _COMPONENTS_PROMOTIONCOMPONENT_HPP_
#define _COMPONENTS_PROMOTIONCOMPONENT_HPP_

#include  "Components/Component.hpp"
#include "DrawManager.hpp"
#include "TextureManager.hpp"
#include "AssetManager.hpp"


class PromotionComponent : public Component
{

    int width = Constants::square_sidelength * 4;
    int height = Constants::square_sidelength;

    int r;
    int g;
    int b;
    int a;

    SDL_Rect backgroundRectangle;
    SDL_Rect sourceRectangle;

    std::vector<SDL_Rect> destinationRectangles;
    std::vector<SDL_Texture*> textures;
    std::vector<std::string> types = {"queen", "knight", "rook", "bishop"};

public: 

    std::string color;

    PromotionComponent(const std::string PlayerColor) : color(PlayerColor)
    {
        backgroundRectangle.w = 4 * Constants::square_sidelength;
        backgroundRectangle.h = Constants::square_sidelength;

        for (const auto& type : types)
        {
            std::string id = PlayerColor + '_' + type;
            textures.push_back(SimpleChess::assetManager->GetTexture(id));

            SDL_Rect rect;
            rect.w = Constants::chesspiece_sidelength;
            rect.h = Constants::chesspiece_sidelength;
            destinationRectangles.push_back(rect);
        }
    }

    void SetPosition(const int x, const int y)
    {
        backgroundRectangle.x = x;
        backgroundRectangle.y = y;

        int offsetX = 0;
        int offsetY = Constants::offset_figures_squares;
        for (auto& pos : destinationRectangles)
        {
            offsetX += Constants::offset_figures_squares;

            pos.x = x + offsetX;
            pos.y = y + offsetY;

            offsetX += Constants::chesspiece_sidelength;
            offsetX += Constants::offset_figures_squares;
        }
    }
    
    void SetBackgroundColor(const int red, const int green, const int blue, const int alpha)
    {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }

    std::string GetPlayersChoice (const int x, const int y)
    {
        for (int i = 0 ; i < destinationRectangles.size() ; i++)
        {
            if ( (x >= destinationRectangles[i].x && x < destinationRectangles[i].x + destinationRectangles[i].w ) &&
                (y >= destinationRectangles[i].y && y < destinationRectangles[i].y + destinationRectangles[i].h ) )
            {
                return types[i];
            }
        }
    
    }

    void Initialize() override
    {
        sourceRectangle.x = 0;
        sourceRectangle.y = 0;
        sourceRectangle.w = Constants::chesspiece_sidelength;
        sourceRectangle.h = Constants::chesspiece_sidelength;
        
        if (color.compare("white") == 0)
            SetBackgroundColor(21, 21, 21, 255);
        else 
            SetBackgroundColor(200, 200, 200, 255);

    }

    void Render() override 
    {
        DrawManager::Draw(&backgroundRectangle, r, g, b, a);
        
        for (int i = 0 ; i < textures.size() ; i++)
            TextureManager::Draw(textures[i], sourceRectangle, destinationRectangles[i], SDL_FLIP_NONE);
    }

};

#endif