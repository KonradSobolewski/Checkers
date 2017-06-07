
#include "Game.hpp"
#include "Human.hpp"

Game::Game()
{
    //isHumanTurn_ = true;
   // human_ = std::make_shared<Human>(true, Color::WHITE);
   // ai_ = std::make_shared<AI>(false, Color::BLACK);
    //state_ = std::make_shared<State>();
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

void Game::executeMove(std::shared_ptr<Move> move, std::shared_ptr<Player> player)
{
    int newPosition = move->getPos();
    int pieceMovedId = move->getPiece()->getID();

    state_->changeBoard(move->getPiece()->getPosition(), Element::BLACK_BLANK);
    state_->changeBoard(newPosition, move->getPiece()->getColor());
    for(auto &piece: player->getPieces()) {
        if(piece->getID() == pieceMovedId)
            piece->setPosition(newPosition);
    }
    if(move->isHit()) {
        state_->changeBoard(move->getHitPos(), Element::BLACK_BLANK);
        if(isHumanTurn_ == true)
            ai_->getPieces();
    }
    isHumanTurn_ = !isHumanTurn_;

}

void Game::notify()
{
    //for(auto p: players_)
    //    p->update();
}
