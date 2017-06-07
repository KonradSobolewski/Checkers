#include "Piece.hpp"
#include "Declarations.hpp"

Piece::Piece(int position, int id, Element color, bool isHumanPiece, bool isUpgraded){
 position_=position;
 id_=id;
 color_=color;
 isHumanPiece_=isHumanPiece;
 isUpgraded_=false;

}

int Piece::getID() { 
	return id_; 
}

int Piece::getPosition() const { 
	return position_; 
}

Element Piece::getColor() const { return color_; }
bool Piece::getWhoseMove() const { return isHumanPiece_; }
bool Piece::isUpgraded() const { return isUpgraded_; }
void Piece::setPosition(int pos) { position_= pos; }
void Piece::setWhosePiece( bool isHumanPiece ) { isHumanPiece_ = isHumanPiece; }
void Piece::upgrade() { isUpgraded_ = true; }
