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
		State() { board.push_back(std::vector<bool>()); board[0].push_back(false); };
		~State() {};
		int getBoardSize() { return 0; };
		std::vector<std::vector<bool>> getPossibleMoves(std::shared_ptr<Move> move) { return board; }
};




#endif //STATE
