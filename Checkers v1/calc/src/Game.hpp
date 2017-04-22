
#ifndef GAME_HPP
#define GAME_HPP
#include "Move.hpp"
#include "Player.hpp" 
#include "Declarations.hpp"


class Game
{
	private:
		int x =5; 
	public:
		Game();
		~Game();
		int getX();
		bool isHumanTurn() const; //sprawdza czyj ruch
		bool checkMove() const; // sprawdza możliwość wykonania ruchu
		void executeMove(std::shared_ptr<Move> move, std::shared_ptr<Player> player) const; // wykonuje ruch
		bool checkVictory(const Player& player) const; //sprawdza wygraną 	
};




#endif //GAME_HPP
