

#include "ezEngine.hpp"

#include "Chess.hpp"

int main(int argc, char* argv[]) 
{

    Chess chess;
    chess.Initialize();

    while (ezEngine::IsRunning()) 
    {
        ezEngine::ProcessInput();
        chess.Update();
        ezEngine::Render();
    }

    ezEngine::Destroy();

    return 0;
}

