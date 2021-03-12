#ifndef _CHESSCONTROLLER_VALIDATE_HPP_
#define _CHESSCONTROLLER_VALIDATE_HPP_

#include "Chesscontroller/Chesscontroller.hpp"


class Validate : public State
{
public:
    Validate (const std::string& PlayerColor, const std::string& OpponentColor);
    void UpdateGame (std::shared_ptr<Chesscontroller> chesscontroller) override;

};


#endif