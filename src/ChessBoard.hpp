
#ifndef _CHESSBOARD_HPP_
#define _CHESSBOARD_HPP_


#include <string>
#include <map>
#include "glm/glm.hpp"

class ChessBoard 
{
private: 
    std::string textureId_;
    int scale_;
    int squareSize_;
    int boardOffset_;

    const int blackSquare = 0;
    const int whiteSquare = 1;

    const int boardSize = 8;

    const char* numbers = "87654321";
    const char* letters = "ABCDEFGH";

    int toggleSquareColor(int currentSquare);


public: 
    ChessBoard(std::string textureId, int scale, int squareSize, int boardOffset);
    ~ChessBoard();

    //TODO: check if needed static
    static std::map<std::string, glm::vec2> squareCoordinates;

    void LoadBoard();
    void AddSquare(int sourceRectX, int sourceRectY, int x, int y, std::string squareTitle);
    
    glm::vec2 GetCoordinatesFromSquare(std::string title);
    std::string GetSquareTitleByCoordinates(glm::vec2 coordinates);

    const std::map<std::string, glm::vec2>& GetSquareCoordinates()  const;


};

#endif 