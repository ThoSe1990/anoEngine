
#include "Chesscontroller/PlayersTurn.hpp"
#include "Chesscontroller/Validate.hpp"
#include "Chesscontroller/Promotion.hpp"

#include "Components/ChesspieceComponent.hpp"

PlayersTurn::PlayersTurn(std::shared_ptr<Chesscontroller>& Chesscontroller, const std::string& PlayerColor, const std::string& OpponentColor) : State(Chesscontroller, PlayerColor, OpponentColor)
{
    Logger::Log(logging::trivial::debug, log_location, "players turn: " , PlayerColor);
}

void PlayersTurn::UpdateGame()
{
    if (!chesscontroller->GetMouseClick())
        return;

    auto [clickedPiece, clickedColor, clickedSquare] = chesscontroller->GetClickedPieceColorSquare();

    ValidationType validationType = chesscontroller->GetValidationFromSquare(clickedSquare);

    if (clickedPiece && clickedColor.compare(playerColor) == 0)
    {
        this->selectPiece(clickedPiece);
    }
    else if (validationType != ValidationType::none)
    {
        this->doMovement(validationType);
    }
}

void PlayersTurn::selectPiece(std::shared_ptr<Entity> piece)
{
    chesscontroller->SetSelectedPiece(piece);
    chesscontroller->ResetValidation();

    auto next = std::make_unique<Validate>(chesscontroller, playerColor, opponentColor);
    chesscontroller->SetState(std::move(next));
}

void PlayersTurn::doMovement(const ValidationType& type)
{
    if (type == ValidationType::castling)    
    {
        chesscontroller->Castle();
    } 
    else 
        chesscontroller->MoveSelectedPiece();
    
    
    chesscontroller->ResetValidation();

    if (this->pawnCanPromote())
    {
        auto next = std::make_unique<Promotion>(chesscontroller, playerColor, opponentColor);
        chesscontroller->SetState(std::move(next)); 
        return;
    }

    auto next = std::make_unique<PlayersTurn>(chesscontroller, opponentColor, playerColor);
    chesscontroller->SetState(std::move(next));

}


bool PlayersTurn::pawnCanPromote()
{
    auto piece = chesscontroller->GetSelectedPiece();
    if (piece)
    {
        if (piece->HasComponent<ChesspieceComponent>())
        {
            auto* pc = piece->GetComponent<ChesspieceComponent>();
            return pc->PawnCanPromote();
        }
    }
    return false;
}

