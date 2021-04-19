#ifndef _COMPONENTS_CHESSPIECECOMPONENT_HPP_
#define _COMPONENTS_CHESSPIECECOMPONENT_HPP_

#include <string>

struct ChesspieceComponent
{
    ChesspieceComponent () {}
    ChesspieceComponent (Entity Owner, std::string Color, std::string Type, std::string Square, bool Captured, int MovesCount) 
    : owner(Owner), color(Color), type(Type), square(Square), captured(Captured), movesCount(MovesCount)
    { }

    Entity owner;
    
    std::string color;
    std::string type;
    std::string square;
    
    bool captured;
    int movesCount;
};

#endif
