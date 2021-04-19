#ifndef _CHESS_CHESSBOARD_HPP_
#define _CHESS_CHESSBOARD_HPP_

#include <string>
#include <map>
#include "glm/glm.hpp"

#include "Game.hpp"
#include "Constants.hpp"
#include "Components/Components.hpp"
#include "Systems/SpriteSystem.hpp"

class Chessboard
{
public:
    static const char* numbers;
    static const char* letters;

    const int blackSquare = 0;
    const int whiteSquare = 1;
    
    static std::map<std::string, glm::vec2> squareCoordinates;

    static std::string GetSquareTitleByCoordinates(glm::vec2 coordinates);
    static glm::vec2 GetCoordinatesFromSquare(const std::string& title);
    void Init();

private:
    int toggleSquareColor(const int currentSquare);
    void addSquareCoordinates(const int col, const int row, const int x, const int y);
    void addSquare(const int sourceRectX, const int sourceRectY, const int x, const int y);
    
};


#endif