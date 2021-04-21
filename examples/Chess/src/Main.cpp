

#include <iostream>
#include "../../../api/ezEngine.hpp"

int main(int argc, char* argv[]) 
{

    std::cout << "starting game " << std::endl;

    api_ezEngine::Initialize();

    while (api_ezEngine::IsRunning()) 
    {
        api_ezEngine::ProcessInput();
        api_ezEngine::Update();
        api_ezEngine::Render();
    }

    api_ezEngine::Destroy();

    return 0;
}

