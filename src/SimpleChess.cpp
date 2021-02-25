
#include <iostream>

#include "Constants.hpp"
#include "SimpleChess.hpp"

#include "glm/glm.hpp"

#include "AssetManager.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"

#include "ChessBoard.hpp"
#include "ChessController.hpp"

const int Constants::chessfigures_sidelength = 60;
const int Constants::chessboard_square_sidelength = 70;
const int Constants::offset_figures_squares = (Constants::chessboard_square_sidelength - Constants::chessfigures_sidelength) / 2 ;
const int Constants::chessfigures_velocity = 500;


EntityManager manager;
ChessBoard* chessBoard;
ChessController* chessController;

SDL_Event SimpleChess::event;
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

    assetManager->AddTexture("white_bishop", "./assets/images/white_bishop.png");
    assetManager->AddTexture("white_king", "./assets/images/white_king.png");
    assetManager->AddTexture("white_knight", "./assets/images/white_knight.png");
    assetManager->AddTexture("white_pawn", "./assets/images/white_pawn.png");
    assetManager->AddTexture("white_queen", "./assets/images/white_queen.png");
    assetManager->AddTexture("white_rook", "./assets/images/white_rook.png");
    assetManager->AddTexture("black_bishop", "./assets/images/black_bishop.png");
    assetManager->AddTexture("black_king", "./assets/images/black_king.png");
    assetManager->AddTexture("black_knight", "./assets/images/black_knight.png");
    assetManager->AddTexture("black_pawn", "./assets/images/black_pawn.png");
    assetManager->AddTexture("black_queen", "./assets/images/black_queen.png");
    assetManager->AddTexture("black_rook", "./assets/images/black_rook.png");
    assetManager->AddTexture("board_squares", "./assets/images/board_squares.png");

    
    chessBoard = new ChessBoard("board_squares", 1, Constants::chessboard_square_sidelength, 40);
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



    // chesscontroller after chesspieces!
    chessController = new ChessController( manager.GetEntities(Layer::chess_piece) ) ;

}


void SimpleChess::ProcessInput() 
{
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
        // case SDL_MOUSEBUTTONDOWN:
        // {
        //     int x, y, w, h;
        //     SDL_GetMouseState(&x, &y);
        //     std::string square = chessBoard->GetSquareTitleByCoordinates(glm::vec2(x,y));
        //     Logger::Log(logging::trivial::debug, log_location, "coordinates: " , x, " / " , y , " --> " , square);
        // }
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