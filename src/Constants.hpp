#ifndef CONSTANTS_H
#define CONSTANTS_H

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 800;

const unsigned int FPS = 200;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;


class Constants
{
public:
    static const int chessfigures_sidelength;
    static const int chessboard_square_sidelength;
    static const int offset_figures_squares;
    static const int chessfigures_velocity;
    static const int chessboard_offset;
    static const int number_of_squares_per_row;
    static const int number_of_squares_per_col;
};

enum class Layer
{
    square = 0,
    chess_piece = 1,
    validation = 2

};

#endif
