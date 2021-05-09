

#include "Game.hpp"
#include "Constants.hpp"
#include "Log.hpp"

#include "Systems/UserControlSystem.hpp"
#include "Systems/SpriteSystem.hpp"
#include "Systems/TransformSystem.hpp"
#include "Systems/PositionSystem.hpp"
#include "Systems/CollisionSystem.hpp"
#include "Systems/TextlabelSystem.hpp"

#include "UserInputs.hpp"

std::shared_ptr<AssetManager> Game::assetManager = std::make_shared<AssetManager>();
std::shared_ptr<SystemManager> Game::systemManager = std::make_shared<SystemManager>();

unsigned int System::entitiesCount = 0;
std::unordered_map<Entity, size_t>  System::componentsPerEntity;

SDL_Event Game::event;
SDL_Renderer* Game::renderer;

Game::Game()
{

}

Game& Game::GetInstance() noexcept
{
    static Game instance; 
    return instance;
}

bool Game::IsRunning() const noexcept 
{
    return this->isRunning;
}

void Game::Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }
    if (TTF_Init() != 0) {
        std::cerr << "Error initializing SDL TTF" << std::endl;
        return;
    }
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->windowWidth,
        this->windowHeight,
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


    this->frameTargetTime = 1000 / this->fps;

    systemManager->AddSystem<UserControlSystem>();
    systemManager->AddSystem<PositionSystem>(); 
    systemManager->AddSystem<SpriteSystem>();
    systemManager->AddSystem<TransformSystem>();
    systemManager->AddSystem<CollisionSystem>();
    systemManager->AddSystem<TextlabelSystem>();

    isRunning = true;
    return;
}

const float Game::GetDeltaTime() const noexcept
{
    return this->deltaTime;
}
const unsigned int Game::GetWindowWidth() const noexcept
{
    return this->windowWidth;
}
const unsigned int Game::GetWindowHeight() const noexcept
{
    return this->windowHeight;
}


void Game::Update()
{
    int timeToWait = this->frameTargetTime - (SDL_GetTicks() - ticksLastFrame);

    if (timeToWait > 0 && timeToWait <= this->frameTargetTime) 
        SDL_Delay(timeToWait);
    

    this->deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    this->deltaTime = (this->deltaTime > 0.05f) ? 0.05f : this->deltaTime;

    ticksLastFrame = SDL_GetTicks();

    systemManager->Update(this->deltaTime);
}


void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    systemManager->Render();

    SDL_RenderPresent(renderer);
}

void Game::ProcessInput() 
{
    auto& userInputs = UserInputs::GetInstance();
    userInputs.mouseButtonLeftClick = false;
    userInputs.mouseButtonRightClick = false;
    userInputs.mouseX = static_cast<int>(event.motion.x);
    userInputs.mouseY = static_cast<int>(event.motion.y);

    while (SDL_PollEvent(&event))
    {
        switch (event.type) 
        {
            case SDL_QUIT: 
            {
                this->isRunning = false;
                break;
            }
            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym == SDLK_ESCAPE) this->isRunning = false;

                if (event.key.keysym.sym == SDLK_a) userInputs.keyboard_a = true;
                if (event.key.keysym.sym == SDLK_s) userInputs.keyboard_s = true;
                if (event.key.keysym.sym == SDLK_d) userInputs.keyboard_d = true;
                if (event.key.keysym.sym == SDLK_w) userInputs.keyboard_w = true;
                break;
            }
            case SDL_KEYUP:
            {
                if (event.key.keysym.sym == SDLK_a) userInputs.keyboard_a = false;
                if (event.key.keysym.sym == SDLK_s) userInputs.keyboard_s = false;
                if (event.key.keysym.sym == SDLK_d) userInputs.keyboard_d = false;
                if (event.key.keysym.sym == SDLK_w) userInputs.keyboard_w = false;
                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                if (event.button.button == SDL_BUTTON_LEFT) userInputs.mouseButtonLeftDown = true;
                if (event.button.button == SDL_BUTTON_RIGHT) userInputs.mouseButtonRightDown = true;
                if (event.button.button == SDL_BUTTON_LEFT) userInputs.mouseButtonLeftUp = false;
                if (event.button.button == SDL_BUTTON_RIGHT) userInputs.mouseButtonRightUp = false;
                
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
                if (event.button.button == SDL_BUTTON_LEFT) userInputs.mouseButtonLeftClick = true;
                if (event.button.button == SDL_BUTTON_RIGHT) userInputs.mouseButtonRightClick = true;

                if (event.button.button == SDL_BUTTON_LEFT) userInputs.mouseButtonLeftUp = true;
                if (event.button.button == SDL_BUTTON_RIGHT) userInputs.mouseButtonRightUp = true;
                if (event.button.button == SDL_BUTTON_LEFT) userInputs.mouseButtonLeftDown = false;
                if (event.button.button == SDL_BUTTON_RIGHT) userInputs.mouseButtonRightDown = false;
                break;
            }
            case SDL_MOUSEMOTION:
            {        
                break;
            }
            default: 
            {
                break;
            }
        }
    }
}

void Game::Destroy() 
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

