#ifndef _CHESSCONTROLLER_PLAYERSTURN_HPP_
#define _CHESSCONTROLLER_PLAYERSTURN_HPP_

#include "Chesscontroller/Chesscontroller.hpp"
#include "Chesscontroller/Validate.hpp"


class Validate;

class PlayersTurn : public State
{
private:
    void selectPiece(std::shared_ptr<Chesscontroller>& chesscontroller, std::shared_ptr<Entity> piece, std::string color);
    void movePiece(std::shared_ptr<Chesscontroller>& chesscontroller, std::string square);
public:

    PlayersTurn(const std::string& PlayerColor, const std::string& OpponentColor); 
    PlayersTurn(std::shared_ptr<Chesscontroller>& chesscontroller, const std::string& PlayerColor, const std::string& OpponentColor); 

    void UpdateGame(std::shared_ptr<Chesscontroller> chesscontroller) override;

};





#endif 