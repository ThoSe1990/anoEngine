

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
        
        castling(destination);
        
        return (Chess::MovePiece(destination)) ?
            std::make_unique<PlayersTurn>(opponentColor, playerColor) : nullptr;
    }
    return nullptr;
}

void PlayersTurn::castling(const std::string& destination)
{
    auto selected = Chess::GetSelectedPiece();
    
    if (!selected)
        return;

    if ( (selected->type.compare("king") == 0) && (selected->color.compare(Constants::color_white) == 0) )
    {
        if (destination.compare("C1") == 0 )
            Chess::MovePiece("A1", "D1");
    
        if (destination.compare("G1") == 0 )
            Chess::MovePiece("H1", "F1");
    }
    if ( (selected->type.compare("king") == 0) && (selected->color.compare(Constants::color_black) == 0) )
    {
        if (destination.compare("C8") == 0 )
            Chess::MovePiece("A8", "D8");
    
        if (destination.compare("G8") == 0 )
            Chess::MovePiece("H8", "F8");
    }
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


