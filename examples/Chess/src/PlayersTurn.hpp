#ifndef _CHESSCONTROLLER_PLAYERSTURN_HPP_
#define _CHESSCONTROLLER_PLAYERSTURN_HPP_

#include "State.hpp"
#include "Chesspiece.hpp"

class Validate;

class PlayersTurn : public State
{
    std::shared_ptr<Chesspiece> getClickedComponent();
    std::shared_ptr<Chesspiece> getSelectedComponent();

    void castling(const std::string& destination);

public:
    PlayersTurn(const std::string& PlayerColor, const std::string& OpponentColor); 
    std::unique_ptr<State>  UpdateGame() override;
};
 




#endif 