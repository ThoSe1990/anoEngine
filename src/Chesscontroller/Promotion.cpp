
#include "Chesscontroller/Promotion.hpp"
#include "Chesscontroller/PlayersTurn.hpp"
#include "Components/PromotionComponent.hpp"
#include "Components/ChesspieceComponent.hpp"

Promotion::Promotion(std::shared_ptr<Chesscontroller>& Chesscontroller, const std::string& PlayerColor, const std::string& OpponentColor) : State(Chesscontroller, PlayerColor, OpponentColor)
{
    Logger::Log(logging::trivial::debug, log_location, "creating promotion for " , PlayerColor);
    openMenu();
}

void Promotion::UpdateGame()
{
    if (chesscontroller->GetMouseClick())
    {
        changePieceAndCloseMenu();

        auto next = std::make_unique<PlayersTurn>(chesscontroller, opponentColor, playerColor);
        chesscontroller->SetState(std::move(next));
    }
}

void Promotion::openMenu()
{
    auto selectedPiece = chesscontroller->GetSelectedPiece();
    auto* tc = selectedPiece->GetComponent<TransformComponent>();
    glm::vec2 pos = tc->GetActPosition();

    auto promotion = chesscontroller->GetPromotionEntity(playerColor);
    auto* pc = promotion->GetComponent<PromotionComponent>();
    pc->SetPosition(pos.x+Constants::square_sidelength , pos.y);
    promotion->Activate();
}

void Promotion::changePieceAndCloseMenu()
{
    auto promotion = chesscontroller->GetPromotionEntity(playerColor);
    auto* pc = promotion->GetComponent<PromotionComponent>();

    glm::vec2 coordinates = chesscontroller->GetClickedCoordinates();
    std::string playersChoice = pc->GetPlayersChoice(coordinates.x, coordinates.y);

    auto selectedPiece = chesscontroller->GetSelectedPiece();
    auto* cp = selectedPiece->GetComponent<ChesspieceComponent>();
    cp->SetNewPieceType(playersChoice);


    promotion->Deactivate();  
}