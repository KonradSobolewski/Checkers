
#include "Game.hpp"
#include "Human.hpp"

Game::Game()
{
    state_ = std::make_shared<State>();
    ai_ = std::make_shared<AI>(false, BLACK);
    human_ = std::make_shared<Human>(true, WHITE);

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
    return isHumanTurn_ == true;

}

bool Game::checkMove(std::shared_ptr<Move> move) const
{
    std::vector<int> possibleMoves = state_->getPossibleMoves(move->getPiece());
    for(auto const &moves: possibleMoves) {
        if (moves == move->getPos())
            return true;
    }
    return false;
}



bool Game::checkVictory(const Player& player) const
{

    if(human_->getPieces().empty() || ai_->getPieces().empty())
        return true;
    return false;


}

bool Game::executeMove(std::shared_ptr<Move> move, std::shared_ptr<Player> player)
{    
    int newPosition = move->getPos();

    state_->changeBoard(move->getPiece()->getPosition(), Element::BLACK_BLANK);
    state_->changeBoard(newPosition, move->getPiece()->getColor());
    move->getPiece()->setPosition(newPosition);
    
    if(move->isHit()) {
        state_->changeBoard(move->getHitPos(), Element::BLACK_BLANK);
        if(move->isHumanMove() == true)
	    ai_->hitPiece(move->getHitPos());	
	else
	    human_->hitPiece(move->getHitPos());
    }
    //isHumanTurn_ = !isHumanTurn_;
    return true;
}


void Game::notify()
{
    //for(auto p: players_)
    //    p->update();
}


std::shared_ptr<AI> Game::getAI()
{
	return ai_;
}

std::shared_ptr<Human> Game::getHuman()
{
	return human_;
}

std::shared_ptr<State> Game::getState()
{
	return state_;
}
