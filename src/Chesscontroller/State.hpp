#ifndef _CHESSCONTROLLER_STATE_HPP_
#define _CHESSCONTROLLER_STATE_HPP_

#include <memory>
#include <string>

class Chesscontroller;

class State
{
protected:
    std::string playerColor;
    std::string opponentColor;

public:
    State (std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor) { }
    virtual ~State() { }
    virtual void UpdateGame(std::shared_ptr<Chesscontroller> chesscontroller) = 0;  
};



#endif