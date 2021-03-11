#ifndef _CHESSCONTROLLER_CHESSCONTROLLER_HPP_
#define _CHESSCONTROLLER_CHESSCONTROLLER_HPP_

#include <iostream>
#include <tuple>
#include "glm/glm.hpp"

#include "Entity/EntityManager.hpp"
#include "Entity/Entity.hpp"
#include "Components/Component.hpp"
#include "Chesscontroller/State.hpp"
#include "Log.hpp"


enum class SquareState
{
    free = 0,
    ocupied_by_friend = 1,
    occupied_by_opponent = 2,
    invalid = 3
};


class Chesscontroller : public std::enable_shared_from_this<Chesscontroller>
{
private:
    std::unique_ptr<State> currentState;
    std::shared_ptr<Entity> selectedPiece;

    std::vector<std::shared_ptr<Entity>> chessPieces;
    std::vector<std::shared_ptr<Entity>> validationEntities;

    std::string clickedSquare;
    bool mouseClick = false;

    std::string getColorOfPiece(std::shared_ptr<Entity> piece) const;
    std::shared_ptr<Entity> getClickedEntity() const;

public:

    Chesscontroller(State* state, std::vector<std::shared_ptr<Entity>> ChessPieces, std::vector<std::shared_ptr<Entity>> ValidationEntities);
    ~Chesscontroller ();

    void Update();

    void SetState(std::unique_ptr<State> state) ;
    void SetClickedSquare(const int x, const int y);

    void SetSelectedPiece(std::shared_ptr<Entity>& entity);
    std::shared_ptr<Entity> GetSelectedPiece() const; 

    void SetMouseClick();
    bool GetMouseClick() const;

    bool MoveSelectedPiece();
    bool HasValidMoves();
    bool IsValidMove(const std::string& square);
    bool IsValidPosition(const std::string& square);
    
    void ResetValidation();    
    void SetValidation(const std::string& square, const std::string& assetId);
    void CaptureOpponent(const std::string& square);

    std::shared_ptr<Entity> GetEntityFromSqaure(const std::string& square) const;
    std::tuple<std::shared_ptr<Entity>, std::string, std::string> GetClickedPieceColorSquare() const;   
    std::tuple<std::string, std::string> GetColorAndPosition(const std::shared_ptr<Entity>& entity) const;

    SquareState GetSquareState(const std::string& square, const std::string& playerColor);

};






#endif