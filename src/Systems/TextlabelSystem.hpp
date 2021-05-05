

#ifndef _SYSTEMS_TEXTLABELSYSTEM_HPP_
#define _SYSTEMS_TEXTLABELSYSTEM_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Constants.hpp"
#include "Systems/System.hpp"
#include "Components/Components.hpp"
#include "FontManager.hpp"




class TextlabelSystem : public System
{

    std::unordered_map<Entity, SDL_Texture*> textureContainer;

public:

    void Initialize() override 
    {

    }

    void Update(float deltaTime) override 
    {
    
    }

    void Render() override  
    {
        auto& components = Components::GetInstance();
    
        for (int i = 0 ; i < components.TextlabelManager->GetCount() ; i++)
        {
            auto textlabel = components.TextlabelManager->at(i);
            FontManager::Draw( textureContainer[textlabel->owner] , SDL_Rect{textlabel->position.x, textlabel->position.y, textlabel->position.w, textlabel->position.h});
        }   
    }

    void AddTextlabel(const std::shared_ptr<TextlabelComponent>& textlabel)
    {
        SDL_Surface* surface = TTF_RenderText_Blended(Game::assetManager->GetFont(textlabel->fontId), 
            textlabel->text.c_str(), 
            SDL_Color{textlabel->color.r,textlabel->color.g,textlabel->color.b,textlabel->color.a}
            );

        SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(texture, NULL, NULL, &textlabel->position.w, &textlabel->position.h);
        textureContainer.emplace(textlabel->owner, texture);
    }
};

#endif