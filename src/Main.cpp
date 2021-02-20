#include <iostream>
#include "constants.hpp"
#include "SimpleChess.hpp"

int main(int argc, char* argv[]) 
{
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