
#ifndef GAME_HPP
#define GAME_HPP
#include "Move.hpp"
#include "Player.hpp" 
#include "AI.hpp"
#include "Piece.hpp"
#include "State.hpp"
#include "Declarations.hpp"


class Game
{
	private:
		int x = 5;
		std::vector<std::shared_ptr<Player>> players;
	public:
		Game();
		~Game();
		int getX();
		bool isHumanTurn() const; //sprawdza czyj ruch
		bool checkMove() const; // sprawdza możliwość wykonania ruchu
		void executeMove(std::shared_ptr<Move> move, std::shared_ptr<Player> player) const; // wykonuje ruch
		bool checkVictory(const Player& player) const; //sprawdza wygraną 
		void notify(); // wzorzec obserwatora	
};




#endif //GAME_HPP
