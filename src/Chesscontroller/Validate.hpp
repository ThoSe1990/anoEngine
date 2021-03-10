#ifndef _CHESSCONTROLLER_VALIDATE_HPP_
#define _CHESSCONTROLLER_VALIDATE_HPP_

#include "Chesscontroller/Chesscontroller.hpp"


class Validate : public State
{
    std::string playerColor;
    std::string opponentColor;

public:
    
    Validate (const std::string& PlayerColor, const std::string& OpponentColor);
    void UpdateGame (std::shared_ptr<Chesscontroller> chesscontroller) override;

};


#endif