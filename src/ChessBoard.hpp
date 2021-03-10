
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

    static const char* numbers;
    static const char* letters;

    int toggleSquareColor(const int currentSquare);
    void addSquare(const int sourceRectX, const int sourceRectY, const int x, const int y, const std::string& squareTitle);
    void addValidation(const int x, const int y, const std::string& squareTitle);

public: 
    ChessBoard(const std::string& textureId, const int scale, const int squareSize, const int boardOffset);
    ~ChessBoard();

    static std::map<std::string, glm::vec2> squareCoordinates;

    void LoadBoard();

    static glm::vec2 GetCoordinatesFromSquare(const std::string& title);
    static std::string GetSquareTitleByCoordinates(glm::vec2 coordinates);

};

#endif 