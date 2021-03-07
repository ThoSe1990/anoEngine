#ifndef _CHESSCONTROLLER_PLAYERSTURN_HPP_
#define _CHESSCONTROLLER_PLAYERSTURN_HPP_

#include "Chesscontroller/Chesscontroller.hpp"
#include "Chesscontroller/Validate.hpp"


class Validate;

class PlayersTurn : public State
{
    std::string playerColor;
    std::string opponentColor;
    
    std::map<std::string, std::string> validMoves;

public:

    PlayersTurn(std::string PlayerColor, std::string OpponentColor); 
    PlayersTurn(Chesscontroller* chesscontroller, std::string PlayerColor, std::string OpponentColor); 

    void UpdateGame(Chesscontroller* chesscontroller) override;

};





#endif 