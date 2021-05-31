#ifndef CHESS_CONSTANTS_H
#define CHESS_CONSTANTS_H

#include <string>
#include "ezEngine.hpp"

class Constants
{
public:
    static const int chesspiece_sidelength;
    static const int square_sidelength;
    static const int offset_figures_squares;
    static const ezEngine::Vector2d offset_figures_squares_vec2;
    static const int number_of_squares_per_row;
    static const int number_of_squares_per_col;
    static const int scale;

    static const std::string color_white;
    static const std::string color_black;

    static const std::string invalid_square;

    static int chespieces_velocity;
    static int chespieces_acceleration;
    static int chessboard_offset;
};


class Movements
{
public:

    static const int up;
    static const int right;
    static const int left;
    static const int down;
    static const int none;

    static const int x;
    static const int y;

};

enum class ValidationType {
    none = 0,
    move = 1,
    capture = 2,
    castling = 3
};


#endif
