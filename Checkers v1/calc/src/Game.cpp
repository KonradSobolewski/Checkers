
#include "Game.hpp"

Game::Game()
{
	
}

Game::~Game()
{

}


int Game::getX()
{
	return x;
}

bool Game::isHumanTurn() const
{
	return true;

} 

bool Game::checkMove() const
{
	return true;

}

bool Game::checkVictory(const Player& player) const
{
	return true;

}	

void Game::executeMove(std::shared_ptr<Move> move, std::shared_ptr<Player> player) const
{

}

void Game::notify()
{
	for(auto p: players)
		p->update();
}
