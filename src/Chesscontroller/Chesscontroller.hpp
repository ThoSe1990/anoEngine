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
    occupied_by_friend = 1,
    occupied_by_opponent = 2,
    invalid = 3
};


class Chesscontroller
{
private:
    std::unique_ptr<State> currentState;
    std::shared_ptr<Entity> selectedPiece;

    std::vector<std::shared_ptr<Entity>> chessPieces;
    std::vector<std::shared_ptr<Entity>> pawnPromotionEntities;
    std::vector<std::shared_ptr<Entity>> validationEntities;

    std::string clickedSquare;
    glm::vec2 clickedCoordinates;
    
    bool mouseClick = false;

    std::string getColorOfPiece(std::shared_ptr<Entity> piece) const;
    std::shared_ptr<Entity> getClickedEntity() const;
    void captureIfSquareIsOccupied();

    std::tuple<std::shared_ptr<Entity>, std::string> getRook();

public:

    Chesscontroller(std::vector<std::shared_ptr<Entity>> ChessPieces, std::vector<std::shared_ptr<Entity>> ValidationEntities, std::vector<std::shared_ptr<Entity>> PawnPromotionEntities);
    ~Chesscontroller ();

    void Update();

    void SetState(std::unique_ptr<State> state) ;
    void SetClickedCoordinates(const int x, const int y);
    glm::vec2 GetClickedCoordinates();

    void SetSelectedPiece(std::shared_ptr<Entity>& entity);
    std::shared_ptr<Entity> GetSelectedPiece() const; 

    std::shared_ptr<Entity> GetPromotionEntity(const std::string& color) const;

    void SetMouseClick();
    bool GetMouseClick() const;

    void MoveSelectedPiece();
    void Castle();
    bool HasValidMoves();


    ValidationType GetValidationFromSquare(const std::string& square);
    bool IsValidPosition(const std::string& square);
    
    void ResetValidation();    
    void SetValidation(const std::string& square, ValidationType type);

    std::shared_ptr<Entity> GetEntityFromSqaure(const std::string& square) const;
    std::tuple<std::shared_ptr<Entity>, std::string, std::string> GetClickedPieceColorSquare() const;   
    std::tuple<std::string, std::string> GetColorAndPosition(const std::shared_ptr<Entity>& entity) const;

    SquareState GetSquareState(const std::string& square, const std::string& playerColor);
};






#endif