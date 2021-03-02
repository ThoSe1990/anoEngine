#include <iostream>
#include "Constants.hpp"
#include "SimpleChess.hpp"

#include "Log.hpp"
    
int main(int argc, char* argv[]) 
{

    Logger::Init("debug");
    Logger::Log(logging::trivial::debug, log_location, "starting SimpleChess\n");
    
    SimpleChess simpleChess;

    simpleChess.Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (simpleChess.IsRunning()) 
    {
        simpleChess.ProcessInput();
        simpleChess.Update();
        simpleChess.Render();
    }

    simpleChess.Destroy();

    return 0;
}