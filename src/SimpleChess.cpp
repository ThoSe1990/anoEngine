
#include <iostream>

#include "./Constants.hpp"
#include "SimpleChess.hpp"

#include "glm/glm.hpp"

#include "AssetManager.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"


EntityManager manager;
AssetManager* SimpleChess::assetManager = new AssetManager(&manager);
SDL_Renderer* SimpleChess::renderer;


SimpleChess::SimpleChess()
{
    this->isRunning = false;
}

SimpleChess::~SimpleChess()
{

}

bool SimpleChess::IsRunning() const 
{
    return this->isRunning;
}


void SimpleChess::Initialize(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }
   window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_BORDERLESS
    );

    if (!window) 
    {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) 
    {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }

    LoadBoard();

    isRunning = true;
    return;

}

void SimpleChess::LoadBoard() 
{
    std::string textureFilePath = "./assets/images/white_rook.png";
    assetManager->AddTexture("tank-image", textureFilePath.c_str());

    Entity& newEntity(manager.AddEntity("tank"));
    newEntity.AddComponent<TransformComponent>(0, 0, 0, 0, 60, 60, 1);
    newEntity.AddComponent<SpriteComponent>("tank-image");
}


void SimpleChess::ProcessInput() 
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) 
    {
        case SDL_QUIT: 
        {
            isRunning = false;
            break;
        }
        case SDL_KEYDOWN:
        {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false;
            }
        }
        default: 
        {
            break;
        }
    }
}


void SimpleChess::Update() 
{
    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) 
        SDL_Delay(timeToWait);
    

    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    ticksLastFrame = SDL_GetTicks();

    manager.Update(deltaTime);
}


void SimpleChess::Render() 
{
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    if (manager.HasNoEntities()) 
        return;

    manager.Render();

    SDL_RenderPresent(renderer);
}

void SimpleChess::Destroy() 
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
