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
    class UserInputs 
    {
        friend class Game;
        bool click;
        int mouse_x;
        int mouse_y;
        public:
            bool GetClick() {return click;}
            glm::vec2 GetMouseCoordinates() {return glm::vec2(mouse_x, mouse_y);}
            int GetMouseX() {return mouse_x;}
            int GetMouseY() {return mouse_y;}
    };

public:
    static SDL_Renderer *renderer;
    static std::shared_ptr<AssetManager> assetManager;
    static std::shared_ptr<SystemManager> systemManager;
    static SDL_Event event;
    static std::unique_ptr<UserInputs> userInputs;

    sol::state lua;

    virtual ~Game() {}
    void Initialize();
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