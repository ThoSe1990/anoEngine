

#include "anoEngine.hpp"

#include "Chess.hpp"

int main(int argc, char* argv[]) 
{

    Chess chess;
    chess.Initialize();

    while (anoEngine::IsRunning()) 
    {
        anoEngine::ProcessInput();
        chess.Update();
        anoEngine::Render();
    }

    anoEngine::Destroy();

    return 0;
}

