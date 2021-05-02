#ifndef _CHESS_CHESS_HPP_
#define _CHESS_CHESS_HPP_

#include <lua/sol.hpp>
#include <unordered_map>

#include "ezEngine.hpp"
#include "State.hpp"
#include "Chesspiece.hpp"

class Chess 
{
    std::unique_ptr<State> currentState;
    std::shared_ptr<Chessboard> chessboard;
    

    static std::shared_ptr<Chesspiece> selectedPiece;

    void loadPieces();
    void setInitialGameState();
    void initializeLua();
    void loadAssets();
    void createValidation();
    void updatePieces();
    void updateValidation();
    static bool isValidMove(const std::string& toSquare);
    static void captureOpponent(const std::string& square);
public:


    void Initialize() ;
    void Update() ;
    void Render() ;

    sol::state lua;

    void SetState(std::unique_ptr<State> state) ;
    static void SetSelectedPiece(std::shared_ptr<Chesspiece> cp);
    static void ResetSelectedPiece();
    static bool MovePiece(const std::string& toSquare);
    static void MovePiece(const std::string& fromSquare, const std::string& toSquare);
    static std::shared_ptr<Chesspiece> GetSelectedPiece();
    static std::shared_ptr<Chesspiece> GetChesspieceFromSquare(const std::string& square);
    static std::vector<std::shared_ptr<Chesspiece>> AllPieces;
    static std::unordered_map<std::string, Entity> validMoves;

};

#endif 