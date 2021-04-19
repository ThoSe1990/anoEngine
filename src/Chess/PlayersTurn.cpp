

#include "Chess/PlayersTurn.hpp"
#include "Chess/Chess.hpp"
#include "Log.hpp"

PlayersTurn::PlayersTurn(const std::string& PlayerColor, const std::string& OpponentColor) : State(PlayerColor, OpponentColor)
{
    Logger::Log(logging::trivial::debug, log_location, "players turn: " , PlayerColor);
}

std::unique_ptr<State> PlayersTurn::UpdateGame()
{

    auto clicked = this->getClickedComponent();

    if (clicked && clicked->color.compare(playerColor) == 0)
    {
        Logger::Log(logging::trivial::debug, log_location, "selected: " ,  clicked->color, ' ', clicked->type);
        Chess::SetSelectedPiece(clicked);
    }
    else
    {
        std::string destination = Chessboard::GetSquareTitleByCoordinates(Game::userInputs->GetMouseCoordinates());
        return (Chess::MovePiece(destination)) ?
            std::make_unique<PlayersTurn>(opponentColor, playerColor) : nullptr;
    }
    return nullptr;
}


std::shared_ptr<ChesspieceComponent> PlayersTurn::getClickedComponent()
{
    std::string clickedSquare = Chessboard::GetSquareTitleByCoordinates(Game::userInputs->GetMouseCoordinates());
    std::string color = this->playerColor;

    auto lambda = [&clickedSquare, &color](const std::shared_ptr<ChesspieceComponent>& cp)
    {
        return ( (cp->square.compare(clickedSquare) == 0) && (cp->color.compare(color) == 0 ))  ? true : false;
    };

    auto& components = Components::GetInstance();
    return components.ChesspieceManager->GetComponent(lambda);
}


