
#include "Chesscontroller/Promotion.hpp"
#include "Chesscontroller/PlayersTurn.hpp"
#include "Components/PromotionComponent.hpp"

Promotion::Promotion(std::shared_ptr<Chesscontroller>& Chesscontroller, const std::string& PlayerColor, const std::string& OpponentColor) : State(Chesscontroller, PlayerColor, OpponentColor)
{
    Logger::Log(logging::trivial::debug, log_location, "creating promotion for " , PlayerColor);
    auto promotion = chesscontroller->GetPromotionEntity(playerColor);

    auto* pc = promotion->GetComponent<PromotionComponent>();
    pc->SetBackgroundColor(21, 21, 21, 255);
    pc->SetPosition(100, 100);
    promotion->Activate();
}

void Promotion::UpdateGame()
{
    if (chesscontroller->GetMouseClick())
    {
        glm::vec2 coordinates = chesscontroller->GetClickedCoordinates();

        auto promotion = chesscontroller->GetPromotionEntity(playerColor);

        auto* pc = promotion->GetComponent<PromotionComponent>();

        pc->GetPlayersChoice(coordinates.x, coordinates.y);

        // auto next = std::make_unique<PlayersTurn>(chesscontroller, opponentColor, playerColor);
        // chesscontroller->SetState(std::move(next));
    }
}
