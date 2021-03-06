#ifndef _CHESSCONTROLLER_PLAYERSTURN_HPP_
#define _CHESSCONTROLLER_PLAYERSTURN_HPP_

#include "Chesscontroller/Chesscontroller.hpp"
#include "Chesscontroller/Validate.hpp"


class Validate;

class PlayersTurn : public State
{
    std::string playerColor;
    std::string opponentColor;
    
    //TODO this initial false does pieces not move when coming back from validation
    // initialize properly in constructor
    bool pieceSelected = false;

public:

    PlayersTurn(std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor)
    {
        Logger::Log(logging::trivial::debug, log_location, "players turn: " , PlayerColor);
    }


    void UpdateGame(Chesscontroller* chesscontroller) override;

};





#endif 