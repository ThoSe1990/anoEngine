

#include "ezEngine.hpp"



int main(int argc, char* argv[]) 
{

    ezEngine::Initialize();

    while (ezEngine::IsRunning()) 
    {
        ezEngine::ProcessInput();
        ezEngine::Update();
        ezEngine::Render();
    }

    ezEngine::Destroy();

    return 0;
}

