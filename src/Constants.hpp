#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "glm/glm.hpp"
#include <string>

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 800;

const unsigned int FPS = 200;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;


class Constants
{
public:
    static const int chesspiece_sidelength;
    static const int square_sidelength;
    static const int offset_figures_squares;
    static const glm::vec2 offset_figures_squares_vec2;
    static const int number_of_squares_per_row;
    static const int number_of_squares_per_col;

    static const std::string color_white;
    static const std::string color_black;

    static const std::string invalid_square;

    static int chespieces_velocity;
    static int chessboard_offset;
};

enum class Layer
{
    square = 0,
    chess_piece = 1,
    validation = 2,
    layer_count = 3
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

#endif
