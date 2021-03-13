#ifndef _CHESSCONTROLLER_PROMOTION_HPP_
#define _CHESSCONTROLLER_PROMOTION_HPP_

#include "Chesscontroller/Chesscontroller.hpp"
#include "Chesscontroller/State.hpp"

class Promotion : public State
{
private:

public:
    Promotion(std::shared_ptr<Chesscontroller>& chesscontroller, const std::string& PlayerColor, const std::string& OpponentColor); 
    void UpdateGame() override;

};

#endif