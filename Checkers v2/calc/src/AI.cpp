#include "AI.hpp"

AI::AI(bool isActive, Color color): Player(isActive, color)
{
	createPieces();
}

AI::~AI()
{

}

void AI::update()
{

}

std::shared_ptr<Move> AI::makeMove(std::shared_ptr<State> state)
{
     std::vector<int> moves;
     std::shared_ptr<Piece> piece;
     bool isHit;
     int hitPos;
     int newPos;
     do 
	{
     		piece = *select_randomly(pieces_.begin(), pieces_.end());
  		moves = state->getPossibleMoves(piece);
	} 
     while( moves.size() == 0 ) 
		;// checking for possible move 
	
     newPos = *select_randomly(moves.begin(), moves.end());
     if(abs(newPos - piece->getPosition()) >= 14)
	{
	     isHit = true;
	     hitPos = (newPos - piece->getPosition())/2 + piece->getPosition();
	}
     return std::make_shared<Move>(newPos, false, piece, isHit, hitPos);
}


