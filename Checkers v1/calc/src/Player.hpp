
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Piece.hpp"
#include "Declarations.hpp"

class Player
{
	private:
		Color color_;
		bool isActive_;
		bool isWinner_;	
		typedef std::vector<std::shared_ptr<Piece>> pieces;
		pieces pieces_;	
	public:
		Player(bool isActive, Color color) : isActive_(isActive), color_(color){ createPieces(); };
		~Player(){};
		Color getColor() { return color_; }
		bool isActive() { return isActive_; }
		bool isWinner() { return isWinner_; }
		void setActive(bool state) { isActive_ = state; }
		void setWinner(bool state) { isWinner_ = state; }
                void addPiece(std::shared_ptr<Piece> piece) { pieces_.push_back(piece); }
		pieces getPieces() { return pieces_; }
		int getPiecesNumber() { return pieces_.size(); } //todo 
		void createPieces(){};
};




#endif //PLAYER_HPP
