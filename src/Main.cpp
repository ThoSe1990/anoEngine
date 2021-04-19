#include <iostream>
#include <memory>
#include "Constants.hpp"

#include "Log.hpp"
    
#include "Components/Components.hpp"
#include "Game.hpp"

int main(int argc, char* argv[]) 
{

    Logger::Init("debug");
    Logger::Log(logging::trivial::debug, log_location, "starting SimpleChess\n");
    
    auto game = make_unique<Game>();

    game->Initialize();
    while (game->IsRunning()) 
    {
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    game->Destroy();


    return 0;
}