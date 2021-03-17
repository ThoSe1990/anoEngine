
#ifndef _COMPONENTS_VALIDATIONCOMPONENT_HPP_
#define _COMPONENTS_VALIDATIONCOMPONENT_HPP_

#include <SDL2/SDL.h>
#include "TextureManager.hpp"
#include "AssetManager.hpp"



class ValidationComponent: public Component 
{
private:
    SDL_Texture* texture;
    SDL_Rect source;
    SDL_Rect destination;
    glm::vec2 position;
    std::string title_;
    ValidationType type_;
    int offset_;


public:

    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    std::string GetTitle()
    {
        return title_;
    }

    void SetValidationType(const ValidationType type)
    {
        this->type_= type;
        
        if (type == ValidationType::move)
            texture = SimpleChess::assetManager->GetTexture("valid_move");
        else if (type == ValidationType::castling)
            texture = SimpleChess::assetManager->GetTexture("valid_move");  
        else if (type == ValidationType::capture)
            texture = SimpleChess::assetManager->GetTexture("valid_capture");
    }

    ValidationType GetValidationType()
    {
        return this->type_;
    }

    void SetTextureId(const std::string& id)
    {
        texture = SimpleChess::assetManager->GetTexture(id);
    }

    ValidationComponent(int x, int y, const std::string& title, int offset, int sidelength, float scale) : title_(title)
    {
        source.x = 0;
        source.y = 0;
        source.w = sidelength;
        source.h = sidelength;

        destination.x = x + offset;
        destination.y = y + offset;
        destination.w = sidelength * scale;
        destination.h = sidelength * scale;
    }

    void Initialize() override
    {
        this->type_ = ValidationType::none;        
    }

    void Render() override 
    {
        if (type_ != ValidationType::none)
            TextureManager::Draw(texture, source, destination, spriteFlip);
    }
};


#endif