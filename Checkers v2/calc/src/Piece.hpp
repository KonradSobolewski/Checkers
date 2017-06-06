
#ifndef PIECE_HPP
#define PIECE_HPP
#include "Declarations.hpp"


class Piece
{
	private:
		int x_;
		int y_;
		Color color_;
		bool isHumanPiece_;
		bool isUpgraded_;
	public:
		Piece(int x, int y, Color color, bool isHumanPiece, bool isUpgraded): x_(x), y_(y), color_(color), isHumanPiece_(isHumanPiece), isUpgraded_(false) {};
		~Piece(){};
		int getX() const { return x_; }
		int getY() const { return y_; } 
		Color getColor() const { return color_; }
		bool getWhoseMove() const { return isHumanPiece_; }
                bool isUpgraded() const { return isUpgraded_; }
		void setPosition(int x, int y) { x_= x; y_ = y; }
		void setWhosePiece( bool isHumanPiece ) { isHumanPiece_ = isHumanPiece; }
		void upgrade() { isUpgraded_ = true; }
};




#endif //PIECE_HPP
