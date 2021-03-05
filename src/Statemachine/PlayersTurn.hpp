#ifndef _STATEMACHINE_PLAYERSTURN_HPP_
#define _STATEMACHINE_PLAYERSTURN_HPP_

#include "Statemachine/Statemachine.hpp"

class PlayersTurn : public State
{
    std::string playerColor;
    std::string opponentColor;
    bool pieceSelected = false;

public:

    PlayersTurn(std::string PlayerColor, std::string OpponentColor) : playerColor(PlayerColor), opponentColor(OpponentColor)
    {
        Logger::Log(logging::trivial::debug, log_location, "players turn: " , PlayerColor);
    }


    void UpdateGame(Statemachine* statemachine) override
    {
        auto [piece, color] = statemachine->GetClickedntityAndColor();
        
        //TODO: Refactor in deciated states (??)
        if (color.compare(playerColor) == 0)
        {
            statemachine->SetSelectedPiece(piece);
            pieceSelected = true;
        }
        else if (color.compare(opponentColor) == 0)
        {
            // TODO: validate if possible
            // move and cick
        }
        else if (pieceSelected)
        {
            // TODO: validate if possible
            // move
            if (statemachine->MoveSelectedPiece())
            {
                PlayersTurn* next = new PlayersTurn(opponentColor, playerColor);
                statemachine->SetState(next);
                delete this;
            }
        }
        
    }



};





#endif 