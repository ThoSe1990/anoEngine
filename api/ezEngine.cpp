#if defined _WIN32 || defined __CYGWIN__
    #ifdef _EXPORT_DLL
        #ifdef __GNUC__
            #define EZ_ENGINE__PUBLIC __attribute__((dllexport))
        #else
            #define EZ_ENGINE__PUBLIC __declspec(dllexport)
        #endif
    #else
        #ifdef __GNUC__
            #define EZ_ENGINE__PUBLIC __attribute__((dllimport))
        #else
            #define EZ_ENGINE__PUBLIC __declspec(dllimport)
        #endif
    #endif
    #define EZ_ENGINE__HIDDEN
#else
    #if __GNUC__ >= 4
        #define EZ_ENGINE__PUBLIC __attribute__((visibility("default")))
        #define EZ_ENGINE__HIDDEN __attribute__((visibility("hidden")))
    #else
        #define EZ_ENGINE__PUBLIC
        #define EZ_ENGINE__HIDDEN
    #endif
#endif


#include "api/ezEngine.hpp"    
#include "Game.hpp"

EZ_ENGINE__PUBLIC void ezEngine::Initialize ()
{
    Game::GetInstance().Initialize();
}

EZ_ENGINE__PUBLIC bool ezEngine::IsRunning()
{
    auto& game = Game::GetInstance();
    return game.IsRunning();
}

EZ_ENGINE__PUBLIC void ezEngine::ProcessInput()
{
    Game::GetInstance().ProcessInput();
}

EZ_ENGINE__PUBLIC void ezEngine::Update()
{
    Game::GetInstance().Update();
}

EZ_ENGINE__PUBLIC void ezEngine::Render()
{
    Game::GetInstance().Render();
}

EZ_ENGINE__PUBLIC void ezEngine::Destroy()
{
    Game::GetInstance().Destroy();
}

