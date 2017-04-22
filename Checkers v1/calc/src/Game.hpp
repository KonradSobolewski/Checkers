
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
		int x =5; 
		std::shared_ptr<Player> player;
		std::shared_ptr<AI> ai;
		Board playerState;
		Board aiState;
	public:
		Game();
		~Game();
		void initializeGame(std::shared_ptr<Move> move);
		int getX();
		bool isHumanTurn() const; //sprawdza czyj ruch
		bool checkMove(std::shared_ptr<Move> move) const; // sprawdza możliwość wykonania ruchu
		void executeMove(std::shared_ptr<Move> move, std::shared_ptr<Player> player) const; // wykonuje ruch
		bool checkVictory() const; //sprawdza wygraną 	
};




#endif //GAME_HPP
