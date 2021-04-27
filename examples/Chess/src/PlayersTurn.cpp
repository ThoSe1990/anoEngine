
#include "PlayersTurn.hpp"
#include "Chess.hpp"

PlayersTurn::PlayersTurn(const std::string& PlayerColor, const std::string& OpponentColor) : State(PlayerColor, OpponentColor)
{
    std::cout << "players turn: " << PlayerColor << std::endl;
}

std::unique_ptr<State> PlayersTurn::UpdateGame()
{
    auto clicked = this->getClickedComponent();

    if (clicked && clicked->color.compare(playerColor) == 0)
    {
        std::cout << "selected: " << clicked->color << ' ' << clicked->type  << std::endl;
        Chess::SetSelectedPiece(clicked);
    }
    else
    {
        ezEngine::Vector2d mouse = ezEngine::Inputs::GetMouseCoordinates();
        std::string destination = Chessboard::GetSquareTitleByCoordinates(ezEngine::Vector2d{mouse.x, mouse.y});
        
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

std::shared_ptr<Chesspiece> PlayersTurn::getClickedComponent()
{
    ezEngine::Vector2d mouse = ezEngine::Inputs::GetMouseCoordinates();
    std::string clickedSquare = Chessboard::GetSquareTitleByCoordinates(ezEngine::Vector2d{mouse.x, mouse.y});
    std::string color = this->playerColor;

    auto lambda = [&clickedSquare, &color](const std::shared_ptr<Chesspiece>& cp)
    {
        return ( (cp->square.compare(clickedSquare) == 0) && (cp->color.compare(color) == 0 ))  ? true : false;
    };

    auto it = std::find_if(Chess::AllPieces.begin(), Chess::AllPieces.end(), lambda);
    return (it != Chess::AllPieces.end()) ? (*it) : nullptr;
}