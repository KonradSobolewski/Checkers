#include "Move.hpp"
#include "Piece.hpp"
Move::Move(int pos, bool humanMove, std::shared_ptr<Piece> piece, bool isHit, int hitPosition)
{ 
 pos_ = pos;
 humanMove_ = humanMove;
 piece_ = piece;
 isHit_ = isHit;
 hitPosition_ = hitPosition;
}

int Move::getPos() const 
{ 
	return pos_; 
}

std::shared_ptr<Piece> Move::getPiece() 
{ 
	return piece_; 
}

bool Move::isHumanMove() const 
{ 
	return humanMove_ == true; 
}

void Move::setPos(int pos) 
{ 
	pos_ = pos; 
}

void Move::setWhoseMove(bool isHumanMove) 
{ 
	humanMove_ = isHumanMove; 
}


bool Move::isHit() 
{ 
	return isHit_; 
}

int Move::getHitPos() 
{ 
	return hitPosition_; 
}
