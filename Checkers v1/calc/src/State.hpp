// class represents actual board state
#ifndef STATE_HPP
#define STATE_HPP
#include "Declarations.hpp"

class State
{
	private:
		typedef std::vector<std::vector<bool>> gameBoard;
	public:
		State();
		~State();
};




#endif //STATE
