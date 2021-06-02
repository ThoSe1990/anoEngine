#include "anoEngine.hpp"


int main(int argc, char* argv[]) 
{
    anoEngine::Initialize();

    anoEngine::AddTexture("background", "./examples/debug_playground/assets/images/background.jpg");
    anoEngine::AddTexture("runningCharacter", "./examples/debug_playground/assets/images/running.png");


    auto background = anoEngine::CreateEntity();
    anoEngine::Sprite::Create(background, "background", anoEngine::Rectangle{0,0,2560,1440}, anoEngine::Rectangle{0,0,1920,1080}, anoEngine::Sprite::Layer::layer_0);

    
    anoEngine::AddFont("font", "./examples/debug_playground/assets/fonts/charriot.ttf", 25);
    auto textlabel = anoEngine::CreateEntity();
    anoEngine::Textlabel::Create(textlabel, "some text here ... ", anoEngine::Rectangle{10,10,200,50}, "font", anoEngine::Color{255,255,255,255} );

    
    auto runningCharacter = anoEngine::CreateEntity();
    anoEngine::Sprite::Create(runningCharacter, "runningCharacter", anoEngine::Rectangle{0,0,1200,1000}, anoEngine::Rectangle{800,10,120,100}, anoEngine::Sprite::Layer::layer_0);

    while (anoEngine::IsRunning()) 
    {
        anoEngine::ProcessInput();
        anoEngine::Update();
        anoEngine::Render();
    }

    anoEngine::Destroy();

    return 0;
}

