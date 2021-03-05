
#include "Constants.hpp"


const int Constants::chesspiece_sidelength = 60;
const int Constants::square_sidelength = 70;
const int Constants::offset_figures_squares = (Constants::square_sidelength - Constants::chesspiece_sidelength) / 2 ;
const glm::vec2 Constants::offset_figures_squares_vec2 = glm::vec2(Constants::offset_figures_squares, Constants::offset_figures_squares);
const int Constants::number_of_squares_per_row = 8;
const int Constants::number_of_squares_per_col = 8;


const std::string Constants::color_white = "white";
const std::string Constants::color_black = "black";

const std::string Constants::invalid_square = "00";

int Constants::chespieces_velocity = 500;
int Constants::chessboard_offset = 40;

const glm::vec2 Movements::horizontal = glm::vec2(Constants::square_sidelength, 0);
const glm::vec2 Movements::vertical = glm::vec2(0, Constants::square_sidelength);
const glm::vec2 Movements::diagonal = glm::vec2(Constants::square_sidelength, Constants::square_sidelength);


