#ifndef _CHESS_CHESSBOARD_HPP_
#define _CHESS_CHESSBOARD_HPP_

#include <iostream>
#include <string>
#include <map>
#include "api/ezEngine.hpp"

#include "Constants.hpp"


class Chessboard
{
public:
    static const char* numbers;
    static const char* letters;

    const int blackSquare = 0;
    const int whiteSquare = 1;
    
    static std::map<std::string, ezEngine::Vector2d> squareCoordinates;

    static std::string GetSquareTitleByCoordinates(ezEngine::Vector2d coordinates);
    static ezEngine::Vector2d GetCoordinatesFromSquare(const std::string& title);
    static bool IsValidSquare(const std::string& square);
    void Init();

private:
    int toggleSquareColor(const int currentSquare);
    void addSquareCoordinates(const int col, const int row, const int x, const int y);
    void addSquare(const int sourceRectX, const int sourceRectY, const int x, const int y);
    
};


#endif