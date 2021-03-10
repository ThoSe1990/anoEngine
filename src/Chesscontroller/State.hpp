#ifndef _CHESSCONTROLLER_STATE_HPP_
#define _CHESSCONTROLLER_STATE_HPP_

#include <memory>

class Chesscontroller;

class State
{
public:
    virtual ~State() { }
    virtual void UpdateGame(std::shared_ptr<Chesscontroller> chesscontroller) = 0;  
};



#endif