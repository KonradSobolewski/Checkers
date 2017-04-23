#include "Player.hpp"

Player::Player(bool isActive, Color color){ 
	createPieces();
	color_=color;
	isActive_=isActive;
}

Color Player::getColor() { 
	return color_; 
}
bool Player::isActive() { 
	return isActive_; 
}
bool Player::isWinner() { 
	return isWinner_; 
}
void Player::setActive(bool state) { 
	isActive_ = state; 
}
void Player::setWinner(bool state) { 
	isWinner_ = state; 
}
void Player::addPiece(std::shared_ptr<Piece> piece) { 
	pieces_.push_back(piece); 
}
int Player::getPiecesNumber() { 
	return pieces_.size(); 
} //todo 
void Player::createPieces(){}
