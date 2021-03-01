
#include <iostream>

#include "Constants.hpp"
#include "SimpleChess.hpp"

#include "lua/sol.hpp"
#include "glm/glm.hpp"

#include "AssetManager.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "ChessBoard.hpp"
#include "ChessController.hpp"

#include "Log.hpp"

const int Constants::chessfigures_sidelength = 60;
const int Constants::chessboard_square_sidelength = 70;
const int Constants::offset_figures_squares = (Constants::chessboard_square_sidelength - Constants::chessfigures_sidelength) / 2 ;
const int Constants::chessfigures_velocity = 500;
const int Constants::chessboard_offset = 40;
const int Constants::number_of_squares_per_row = 8;
const int Constants::number_of_squares_per_col = 8;



EntityManager manager;


std::shared_ptr<ChessBoard> chessBoard;
std::shared_ptr<ChessController> chessController;
std::shared_ptr<AssetManager> SimpleChess::assetManager = std::make_shared<AssetManager>(&manager);



SDL_Event SimpleChess::event;
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

    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);

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


    chessBoard = std::make_shared<ChessBoard>("board_squares", 1, Constants::chessboard_square_sidelength, Constants::chessboard_offset);
    chessBoard->LoadBoard();


    glm::vec2 coordinates = chessBoard->GetCoordinatesFromSquare(std::string("B8"));
    
    
    Entity& white_pawn1(manager.AddEntity("white_pawn", Layer::chess_piece));
    white_pawn1.AddComponent<TransformComponent>(coordinates.x, coordinates.y, 0, 0, Constants::chessfigures_sidelength, Constants::chessfigures_sidelength, 1, Constants::offset_figures_squares);
    white_pawn1.AddComponent<SpriteComponent>("white_pawn");


    glm::vec2 newcoordinates = chessBoard->GetCoordinatesFromSquare(std::string("A1"));
    auto test = white_pawn1.GetComponent<TransformComponent>();
    test->SetPosition(newcoordinates.x, newcoordinates.y);


    coordinates = chessBoard->GetCoordinatesFromSquare(std::string("D4"));
    Entity& newEntity (manager.AddEntity("black_king", Layer::chess_piece));
    newEntity.AddComponent<TransformComponent>(coordinates.x, coordinates.y, 0, 0, Constants::chessfigures_sidelength, Constants::chessfigures_sidelength, 1, Constants::offset_figures_squares);
    newEntity.AddComponent<SpriteComponent>("black_king");

    chessController = std::make_shared<ChessController>( manager.GetEntities(Layer::chess_piece) ) ;

}


void SimpleChess::ProcessInput() 
{
    while (SDL_PollEvent(&event))
    {
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
                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                chessController->SetMousebutton(true);
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
                chessController->SetMousebutton(false);
                break;
            }
            case SDL_MOUSEMOTION:
            {
                chessController->SetMousePosition( static_cast<int>(event.motion.x), static_cast<int>(event.motion.y) );

                break;
            }
            default: 
            {
                break;
            }
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

    chessController->UpdateGame();

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