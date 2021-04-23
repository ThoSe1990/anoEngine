#ifndef _CHESS_CHESSPIECE_HPP_
#define _CHESS_CHESSPIECE_HPP_

#include <string>

struct Chesspiece
{
    Chesspiece () {}
    Chesspiece (Entity Owner, std::string Color, std::string Type, std::string Square, bool Captured, int MovesCount) 
    : owner(Owner), color(Color), type(Type), square(Square), captured(Captured), movesCount(MovesCount), castling(false)
    { }

    Entity owner;
    
    std::string color;
    std::string type;
    std::string square;
    
    bool captured;
    int movesCount;

    bool castling;
    std::string castlingWithRook;
};

#endif
