
#ifndef MOVE_HPP
#define MOVE_HPP 
#include "Piece.hpp"

class Move
{
	private:
		int x_;
		int y_;
		bool humanMove_; 
		std::shared_ptr<Piece> piece_;
	public:
		Move(int x, int y, bool humanMove, std::shared_ptr<Piece> piece): x_(x), y_(y), humanMove_(humanMove) , piece_(piece) {};	
		~Move(){};
		int getX() const { return x_; };
		int getY() const { return y_; };
		bool isHumanMove() const { return humanMove_ == true; };
		void setX(int x) { x_ = x; }; 
		void setY(int y) { y_ = y; } ;
		void setWhoseMove(bool isHumanMove) { humanMove_ = isHumanMove; } ;
};

#endif //GAME_HPP
