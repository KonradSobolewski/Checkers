
#include "AI.hpp"

AI::AI(bool isActive, Color color){ createPieces(); isActive_=isActive;  color_=color;}
AI::~AI(){}
Color AI::getColor() { return color_; }
bool AI::isActive() { return isActive_; }
bool AI::isWinner() { return isWinner_; }
void AI::setActive(bool state) { isActive_ = state; }
void AI::setWinner(bool state) { isWinner_ = state; }
//pieces AI::getPieces() { return pieces_; }
void AI::createPieces(){}
void AI::makeMove(){}


