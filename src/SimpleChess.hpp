#ifndef _SIMPLECHESS_HPP_
#define _SIMPLECHESS_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 


#include "Entity/Entity.hpp"
#include "Entity/EntityManager.hpp"
#include "Components/Component.hpp"

class AssetManager;

class SimpleChess
{
private:
    bool isRunning;
    SDL_Window* window;

public:
    SimpleChess();
    ~SimpleChess();

    int ticksLastFrame = 0;
    bool IsRunning() const;
    void Initialize(int width, int height);

    void LoadBoard();

    void ProcessInput();
    void Update();
    void Render();
    void Destroy();

    static SDL_Renderer *renderer;
    static AssetManager* assetManager;

};

#endif