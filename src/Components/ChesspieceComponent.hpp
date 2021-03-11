#ifndef _COMPONENTS_CHESSPIECECOMPONENT_HPP_
#define _COMPONENTS_CHESSPIECECOMPONENT_HPP_

#include <string>
#include "Components/Component.hpp"

#include "Log.hpp"
#include "Constants.hpp"
#include "Entity/EntityManager.hpp"
#include "ChessBoard.hpp"

extern std::shared_ptr<ChessBoard> chessBoard;

extern std::shared_ptr<EntityManager> manager;

class ChesspieceComponent : public Component
{
public:

    std::string color_;
    std::string type_;
    bool killed_;
    bool isSelected;    

    ChesspieceComponent(const std::string& type, const std::string& color, bool killed) 
     : type_(type),
     color_(color),
     killed_(killed),
     isSelected(false)
     {}
};

#endif
