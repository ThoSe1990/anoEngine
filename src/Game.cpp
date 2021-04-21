

#include "Game.hpp"
#include "Constants.hpp"
#include "Log.hpp"

#include "Systems/SpriteSystem.hpp"
#include "Systems/TransformSystem.hpp"

#include "Chess/Chess.hpp"

std::shared_ptr<AssetManager> Game::assetManager = std::make_shared<AssetManager>();
std::shared_ptr<SystemManager> Game::systemManager = std::make_shared<SystemManager>();
std::unique_ptr<Game::UserInputs> Game::userInputs = std::make_unique<Game::UserInputs>();

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

bool Game::IsRunning() const 
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
   window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
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

    InitializeLua();
    LoadAssets();   


    systemManager->AddSystem<SpriteSystem>();
    systemManager->AddSystem<TransformSystem>();
    systemManager->AddSystem<Chess>();



    isRunning = true;
    return;
}

void Game::Update()
{
    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) 
        SDL_Delay(timeToWait);
    

    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    ticksLastFrame = SDL_GetTicks();

    systemManager->Update(deltaTime);
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
    this->userInputs->click = false;
    this->userInputs->mouse_x = static_cast<int>(event.motion.x);
    this->userInputs->mouse_y = static_cast<int>(event.motion.y);
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
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    this->isRunning = false;
                }
                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
                this->userInputs->click = true;
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


void Game::InitializeLua()
{
    lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);
    lua.script_file("./assets/scripts/config.lua");

    sol::optional<int> chespieces_velocity_exists = lua["config"]["chespieces_velocity"];
    Constants::chespieces_velocity = (chespieces_velocity_exists == sol::nullopt) ? Constants::chespieces_velocity : lua["config"]["chespieces_velocity"];
    Logger::Log(logging::trivial::debug, log_location, "loading chespieces_velocity: " , Constants::chespieces_velocity);

    sol::optional<int> chessboard_offset_exists = lua["config"]["chessboard_offset"];
    Constants::chessboard_offset = (chessboard_offset_exists == sol::nullopt) ? Constants::chessboard_offset : lua["config"]["chessboard_offset"];
    Logger::Log(logging::trivial::debug, log_location, "loading chessboard_offset: " , Constants::chessboard_offset);
    
}

void Game::LoadAssets()
{
    lua.script_file("./assets/scripts/assets.lua");
    sol::table chessboardAssets = lua["chessboard_assets"];

    unsigned int index = 0;
    while (true)
    {
        sol::optional<sol::table> exists = chessboardAssets[index];
        if (exists == sol::nullopt)
            break;
        sol::table asset = chessboardAssets[index];
        std::string type = asset["type"];
        if (type.compare("texture") == 0)
        {
            std::string id = asset["id"];
            std::string file = asset["file"];  
            assetManager->AddTexture(id, file.c_str());
            Logger::Log(logging::trivial::debug, log_location, "ading asset: \n    type: " , type , "\n    id: ", id , "\n    file: ", file);
        }
        index++;
    }
}