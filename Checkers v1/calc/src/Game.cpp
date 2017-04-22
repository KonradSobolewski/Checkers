
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

bool Game::checkMove(std::shared_ptr<Move> move)const
{
	return true;

}

bool Game::checkVictory() const
{
	return true;

}	

void Game::executeMove(std::shared_ptr<Move> move, std::shared_ptr<Player> player) const
{

}
