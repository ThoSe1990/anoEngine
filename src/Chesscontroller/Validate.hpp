#ifndef _CHESSCONTROLLER_VALIDATE_HPP_
#define _CHESSCONTROLLER_VALIDATE_HPP_

#include "Chesscontroller/Chesscontroller.hpp"


class Validate : public State
{
    std::string playerColor;
    std::string opponentColor;

public:
    
    Validate (std::string PlayersColor, std::string OpponentsColor);
    void UpdateGame (std::shared_ptr<Chesscontroller> chesscontroller) override;

};


#endif