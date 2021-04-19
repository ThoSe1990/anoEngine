#ifndef _CHESS_STATE_HPP_
#define _CHESS_STATE_HPP_

#include <memory>
#include <string>

#include "Chessboard.hpp"

class State
{
protected:
    std::string playerColor;
    std::string opponentColor;

public:
    State (std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor) { }
    virtual ~State() { }
    virtual std::unique_ptr<State> UpdateGame() = 0;  
};



#endif