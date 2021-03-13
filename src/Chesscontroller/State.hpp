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
    std::shared_ptr<Chesscontroller>& chesscontroller;

public:
    State (std::shared_ptr<Chesscontroller>& Chesscontroller, std::string PlayerColor, std::string OpponentColor) : chesscontroller(Chesscontroller), playerColor(PlayerColor), opponentColor(OpponentColor) { }
    virtual ~State() { }
    virtual void UpdateGame() = 0;  
};



#endif