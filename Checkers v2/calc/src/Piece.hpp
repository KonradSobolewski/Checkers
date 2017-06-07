
#ifndef PIECE_HPP
#define PIECE_HPP
#include "Declarations.hpp"


class Piece
{
private:
    int id_;
    int position_;
    Element color_;
    bool isHumanPiece_;
    bool isUpgraded_;
public:
    Piece(int position, int id, Element color, bool isHumanPiece, bool isUpgraded);
    ~Piece(){};
    int getID();
    int getPosition() const ;
    Element getColor() const ;
    bool getWhoseMove() const ;
    bool isUpgraded() const ;
    void setPosition(int pos) ;
    void setWhosePiece( bool isHumanPiece ) ;
    void upgrade() ;
};




#endif //PIECE_HPP
