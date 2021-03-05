

#include "ChessBoard.hpp"

#include <algorithm>
#include <iterator>

#include "SimpleChess.hpp"
#include "Entity/EntityManager.hpp"
#include "Components/SquareComponent.hpp"
#include "Components/ValidationComponent.hpp"
#include "Constants.hpp"


extern EntityManager manager;

const char* ChessBoard::numbers = "87654321";
const char* ChessBoard::letters = "ABCDEFGH";

std::map<std::string, glm::vec2> ChessBoard::squareCoordinates;

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
    for (int rows = 0 ; rows < Constants::number_of_squares_per_row ; rows++)
    {
        currentSquare = toggleSquareColor(currentSquare);
        for (int cols = 0 ; cols < Constants::number_of_squares_per_row ; cols++)
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
            AddValidation(
                cols * (scale_ * squareSize_)+ boardOffset_,
                rows * (scale_ * squareSize_)+ boardOffset_,
                title
                );
        }
    }
}

void ChessBoard::AddSquare(int sourceRectX, int sourceRectY, int x, int y, std::string squareTitle)
{
    Entity& newSquare(manager.AddEntity("Square", Layer::square));
    newSquare.AddComponent<SquareComponent>(sourceRectX, sourceRectY, x, y, squareSize_, scale_, textureId_, squareTitle);

    squareCoordinates.emplace(squareTitle, glm::vec2(x, y));
}

// TODO: magic numbers ... 
void ChessBoard::AddValidation(int x, int y, std::string squareTitle)
{
    Entity& newValidation(manager.AddEntity("Validation", Layer::validation));
    newValidation.Deactivate();
    newValidation.AddComponent<ValidationComponent>(x, y, squareTitle, 15, 60, 0.66f, "validation_circle");
} 


int ChessBoard::toggleSquareColor(int currentSquare)
{
    return (currentSquare == whiteSquare) ? blackSquare : whiteSquare;
}

glm::vec2 ChessBoard::GetCoordinatesFromSquare(std::string title)
{
    return squareCoordinates[title] + Constants::offset_figures_squares_vec2;
}

std::string ChessBoard::GetSquareTitleByCoordinates(glm::vec2 coordinates)
{   

    if ( (coordinates.x < Constants::chessboard_offset) ||
        (coordinates.x > (Constants::square_sidelength * Constants::number_of_squares_per_col) + Constants::chessboard_offset) ||
        (coordinates.y < Constants::chessboard_offset) ||
        (coordinates.y > (Constants::square_sidelength * Constants::number_of_squares_per_row) + Constants::chessboard_offset) )
            return "00"; //click outside of chess board
    
    int x = (coordinates.x - Constants::chessboard_offset) / Constants::square_sidelength ;
    int y = (coordinates.y - Constants::chessboard_offset) / Constants::square_sidelength ;

    std::string title = "";
    title += letters[x];
    title += numbers[y];    
    return title;
}
