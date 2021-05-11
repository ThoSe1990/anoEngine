#include "ezEngine.hpp"


int main(int argc, char* argv[]) 
{
    ezEngine::Initialize();

    ezEngine::AddTexture("background", "./examples/debug_playground/assets/images/background.jpg");
    ezEngine::AddTexture("runningCharacter", "./examples/debug_playground/assets/images/running.png");


    auto background = ezEngine::CreateEntity();
    ezEngine::Sprite::Create(background, "background", ezEngine::Rectangle{0,0,2560,1440}, ezEngine::Rectangle{0,0,1920,1080}, ezEngine::Sprite::Layer::layer_0);

    
    ezEngine::AddFont("font", "./examples/debug_playground/assets/fonts/charriot.ttf", 25);
    auto textlabel = ezEngine::CreateEntity();
    ezEngine::Textlabel::Create(textlabel, "some text here ... ", ezEngine::Rectangle{10,10,200,50}, "font", ezEngine::Color{255,255,255,255} );

    
    auto runningCharacter = ezEngine::CreateEntity();
    ezEngine::Sprite::Create(runningCharacter, "runningCharacter", ezEngine::Rectangle{0,0,1200,1000}, ezEngine::Rectangle{800,10,120,100}, ezEngine::Sprite::Layer::layer_0);

    while (ezEngine::IsRunning()) 
    {
        ezEngine::ProcessInput();
        ezEngine::Update();
        ezEngine::Render();
    }

    ezEngine::Destroy();

    return 0;
}

