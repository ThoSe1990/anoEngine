

#include "ChessBoard.hpp"

#include <algorithm>
#include <iterator>

#include "SimpleChess.hpp"
#include "Entity/EntityManager.hpp"
#include "Components/SquareComponent.hpp"
#include "Constants.hpp"

#include "Log.hpp"

extern EntityManager manager;


map<std::string, glm::vec2> ChessBoard::squareCoordinates;

ChessBoard::ChessBoard(std::string textureId, int scale, int squareSize, int boardOffset) :
textureId_(textureId), 
scale_(scale), 
squareSize_(squareSize), 
boardOffset_(boardOffset)
{ }


ChessBoard::~ChessBoard() 
{
    
}

void ChessBoard::LoadBoard()
{
    int currentSquare = whiteSquare;
    for (int rows = 0 ; rows < boardSize ; rows++)
    {
        currentSquare = toggleSquareColor(currentSquare);
        for (int cols = 0 ; cols < boardSize ; cols++)
        {
            std::string title = "";
            title += letters[cols];
            title += numbers[rows];
            currentSquare = toggleSquareColor(currentSquare);

            AddSquare(currentSquare * squareSize_, 
                0,
                cols * (scale_ * squareSize_)+ boardOffset_,
                rows * (scale_ * squareSize_)+ boardOffset_, 
                title);
        }
    }
}

void ChessBoard::AddSquare(int sourceRectX, int sourceRectY, int x, int y, std::string squareTitle)
{
    Entity& newSqure(manager.AddEntity("Square", Layer::square));
    newSqure.AddComponent<SquareComponent>(sourceRectX, sourceRectY, x, y, squareSize_, scale_, textureId_, squareTitle);

    squareCoordinates.emplace(squareTitle, glm::vec2(x, y));
}


int ChessBoard::toggleSquareColor(int currentSquare)
{
    return (currentSquare == whiteSquare) ? blackSquare : whiteSquare;
}

glm::vec2 ChessBoard::GetCoordinatesFromSquare(std::string title)
{
    return squareCoordinates[title];
}

std::string ChessBoard::GetSquareTitleByCoordinates(glm::vec2 coordinates)
{

    auto lambda =[&coordinates](auto current_item)
    {
        auto squareCenter = current_item.second + glm::vec2(Constants::chessboard_square_sidelength/2.0, Constants::chessboard_square_sidelength/2.0);
        auto distanceCenterToClick = abs(squareCenter - coordinates);
        auto squareCenterToBorder = Constants::chessboard_square_sidelength / 2.0;
        return (distanceCenterToClick.x < squareCenterToBorder && distanceCenterToClick.y < squareCenterToBorder) ? true : false;
    };

    auto it = std::find_if(std::begin(squareCoordinates),std::end(squareCoordinates), lambda);

    if ( it != std::end(squareCoordinates) )    
        return it->first;
    else return std::string("not found ... ");
}
