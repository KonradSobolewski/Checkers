
#ifndef AI_HPP
#define AI_HPP
#include "Declarations.hpp"	
#include "Piece.hpp"

class AI
{
	private:
		Color color_;
		bool isActive_;
		bool isWinner_;		
		typedef std::vector<std::shared_ptr<Piece>> pieces;
		pieces pieces_;
	public:
		AI(bool isActive, Color color);
		~AI();
		Color getColor();
		bool isActive();
		bool isWinner();
		void setActive(bool state);
		void setWinner(bool state);
		//pieces getPieces();
		void createPieces();
		void makeMove();  
		int getPiecesNumber() { return pieces_.size(); } 
};


#endif //AI_HPP
