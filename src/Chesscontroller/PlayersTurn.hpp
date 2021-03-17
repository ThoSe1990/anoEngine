#ifndef _CHESSCONTROLLER_PLAYERSTURN_HPP_
#define _CHESSCONTROLLER_PLAYERSTURN_HPP_

#include "Chesscontroller/Chesscontroller.hpp"
#include "Chesscontroller/State.hpp"

class Validate;

class PlayersTurn : public State
{
private:

    void selectPiece(std::shared_ptr<Entity> piece);
    void doMovement(const ValidationType& type);

    bool pawnCanPromote();
    bool kingCastles();
    // void enPassante();

public:
    PlayersTurn(std::shared_ptr<Chesscontroller>& chesscontroller, const std::string& PlayerColor, const std::string& OpponentColor); 

    void UpdateGame() override;

};
 




#endif 