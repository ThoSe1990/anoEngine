#ifndef _CHESSCONTROLLER_VALIDATE_HPP_
#define _CHESSCONTROLLER_VALIDATE_HPP_

#include "Chesscontroller/Chesscontroller.hpp"


class Validate : public State
{
public:
 
    void UpdateGame (Chesscontroller* chesscontroller) override;

};


#endif