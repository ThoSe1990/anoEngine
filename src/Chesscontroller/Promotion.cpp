
#include "Chesscontroller/Promotion.hpp"
#include "Chesscontroller/PlayersTurn.hpp"


Promotion::Promotion(std::shared_ptr<Chesscontroller>& Chesscontroller, const std::string& PlayerColor, const std::string& OpponentColor) : State(Chesscontroller, PlayerColor, OpponentColor)
{
    Logger::Log(logging::trivial::debug, log_location, "creating promotion for " , PlayerColor);
}

void Promotion::UpdateGame()
{
    if (chesscontroller->GetMouseClick())
    {
        auto next = std::make_unique<PlayersTurn>(chesscontroller, opponentColor, playerColor);
        chesscontroller->SetState(std::move(next));
    }
}
