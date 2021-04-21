#if defined _WIN32 || defined __CYGWIN__
    #ifdef _EXPORT_DLL
        #ifdef __GNUC__
            #define EZ_ENGINE_PUBLIC __attribute__((dllexport))
        #else
            #define EZ_ENGINE_PUBLIC __declspec(dllexport)
        #endif
    #else
        #ifdef __GNUC__
            #define EZ_ENGINE_PUBLIC __attribute__((dllimport))
        #else
            #define EZ_ENGINE_PUBLIC __declspec(dllimport)
        #endif
    #endif
    #define EZ_ENGINE_HIDDEN
#else
    #if __GNUC__ >= 4
        #define EZ_ENGINE_PUBLIC __attribute__((visibility("default")))
        #define EZ_ENGINE_HIDDEN __attribute__((visibility("hidden")))
    #else
        #define EZ_ENGINE_PUBLIC
        #define EZ_ENGINE_HIDDEN
    #endif
#endif


#include "api/ezEngine.hpp"    
#include "Game.hpp"

EZ_ENGINE_PUBLIC void ezEngine::Initialize ()
{
    Game::GetInstance().Initialize();
}

EZ_ENGINE_PUBLIC bool ezEngine::IsRunning()
{
    auto& game = Game::GetInstance();
    return game.IsRunning();
}

EZ_ENGINE_PUBLIC void ezEngine::ProcessInput()
{
    Game::GetInstance().ProcessInput();
}

EZ_ENGINE_PUBLIC void ezEngine::Update()
{
    Game::GetInstance().Update();
}

EZ_ENGINE_PUBLIC void ezEngine::Render()
{
    Game::GetInstance().Render();
}

EZ_ENGINE_PUBLIC void ezEngine::Destroy()
{
    Game::GetInstance().Destroy();
}

EZ_ENGINE_PUBLIC void ezEngine::AddTexture(const std::string& textureId, const char* filePath)
{
    Game::assetManager->AddTexture(textureId, filePath);
}

