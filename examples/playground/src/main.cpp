#include "ezEngine.hpp"


int main(int argc, char* argv[]) 
{
    ezEngine::Initialize_sdl();

    ezEngine::Initialize();


    ezEngine::AddFont("font", "./examples/playground/assets/fonts/charriot.ttf", 25);
    auto textlabel = ezEngine::CreateEntity();
    ezEngine::Textlabel::Create(textlabel, "some text here ... ", ezEngine::Rectangle{10,10,200,50}, "font", ezEngine::Color{255,255,255,255} );


    while (ezEngine::IsRunning()) 
    {
        ezEngine::ProcessInput();
        ezEngine::Update();
        ezEngine::Render();
    }

    ezEngine::Destroy();

    return 0;
}

