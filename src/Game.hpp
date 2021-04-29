#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 

#include "glm/glm.hpp"

#include "lua/sol.hpp"

#include "AssetManager.hpp"
#include "Systems/SystemsManager.hpp"


class Game
{
private:
    Game ();

public:

    Game(Game const&) = delete;
    void operator=(Game const&) = delete;

    static Game& GetInstance() noexcept;

    static SDL_Renderer *renderer;
    static std::shared_ptr<AssetManager> assetManager;
    static std::shared_ptr<SystemManager> systemManager;
    static SDL_Event event;

    sol::state lua;

    void Initialize();
    void Initialize_sdl();
    void Update();
    void Render();
    void ProcessInput();
    void Destroy();
    bool IsRunning() const ;


protected:

    bool isRunning;
    SDL_Window* window;
    int ticksLastFrame = 0;
    void InitializeLua();
    void LoadAssets();
};

#endif 