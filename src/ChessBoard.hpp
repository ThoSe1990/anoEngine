
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

    int toggleSquareColor(int currentSquare);


public: 
    ChessBoard(std::string textureId, int scale, int squareSize, int boardOffset);
    ~ChessBoard();

    static std::map<std::string, glm::vec2> squareCoordinates;

    void LoadBoard();
    void AddSquare(int sourceRectX, int sourceRectY, int x, int y, std::string squareTitle);
    void AddValidation(int x, int y, std::string squareTitle);

    static glm::vec2 GetCoordinatesFromSquare(std::string title);
    static std::string GetSquareTitleByCoordinates(glm::vec2 coordinates);

    const std::map<std::string, glm::vec2>& GetSquareCoordinates()  const;


};

#endif 