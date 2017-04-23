// class represents actual board state
#ifndef STATE_HPP
#define STATE_HPP
#include "Declarations.hpp"
#include "Move.hpp"
class State
{
	private:
		Board board;
	public:
		State();
		~State(){}
		int getBoardSize();
		std::vector<std::vector<bool>> getPossibleMoves(std::shared_ptr<Move> move){return board;}
};




#endif //STATE
