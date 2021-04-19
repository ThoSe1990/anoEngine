#ifndef _CHESS_CHESS_HPP_
#define _CHESS_CHESS_HPP_

#include "Systems/System.hpp"
#include "Chess/State.hpp"


class Chess : public System
{
    std::unique_ptr<State> currentState;
    std::shared_ptr<Chessboard> chessboard;
    
    static std::shared_ptr<ChesspieceComponent> selectedPiece;

    void loadPieces();
    void setInitialGameState();
    void createValidation();
    void updatePieces();
    void updateValidation();
    static bool isValidMove(const std::string& toSquare);
    static void captureOpponent(const std::string& square);
public:

    void Initialize() override;
    void Update(float deltaTime) override;
    void Render() override;

    sol::state lua;

    void SetState(std::unique_ptr<State> state) ;
    static void SetSelectedPiece(std::shared_ptr<ChesspieceComponent> cp);
    static void ResetSelectedPiece();
    static bool MovePiece(const std::string& toSquare);
    static std::shared_ptr<ChesspieceComponent> GetSelectedPiece();
};

#endif 