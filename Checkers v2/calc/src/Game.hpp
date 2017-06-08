#ifndef GAME_HPP
#define GAME_HPP
#include "Move.hpp"
#include "Player.hpp"
#include "AI.hpp"
#include "Piece.hpp"
#include "State.hpp"
#include "Declarations.hpp"
#include "Human.hpp"


class Game
{
	private:
	    int x = 5;
	    bool isHumanTurn_;
	    std::shared_ptr<AI> ai_;
	    std::shared_ptr<Human> human_;
	    std::shared_ptr<State> state_;
	public:
	    Game();
	    ~Game();
	    int getX();
	    bool isHumanTurn() const; //sprawdza czyj ruch
	    bool checkMove(std::shared_ptr<Move>) const; // sprawdza możliwość wykonania ruchu
	    void executeMove(std::shared_ptr<Move> move, std::shared_ptr<Player> player) ; // wykonuje ruch
	    bool checkVictory(const Player& player) const; //sprawdza wygraną
	    void notify(); // wzorzec obserwatora
            std::shared_ptr<AI> getAI();
	    std::shared_ptr<Human> getHuman();
	    std::shared_ptr<State> getState();
};




#endif //GAME_HPP
