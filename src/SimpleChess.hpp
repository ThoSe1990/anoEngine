#ifndef _SIMPLECHESS_HPP_
#define _SIMPLECHESS_HPP_

#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 

#include "lua/sol.hpp"

#include "Entity/Entity.hpp"
#include "Entity/EntityManager.hpp"
#include "Components/Component.hpp"

class AssetManager;

class SimpleChess
{
private:
    bool isRunning;
    SDL_Window* window;
    sol::state lua;

    void InitializeLua();
    void LoadAssets();
    void LoadBoard();
    void LoadBoardSetup();

public:
    SimpleChess();
    ~SimpleChess();

    int ticksLastFrame = 0;
    bool IsRunning() const;
    void Initialize(int width, int height);

    void ProcessInput();
    void Update();
    void Render();
    void Destroy();

    static SDL_Renderer *renderer;
    static std::shared_ptr<AssetManager> assetManager;
    static SDL_Event event;
};

#endif