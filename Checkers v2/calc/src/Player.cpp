#include "Player.hpp"

Player::Player(bool isActive, Color color){
    color_ = color;    
    //createPieces();
    isActive_ = isActive;
}

Player::~Player()
{

}

Color Player::getColor()
{
    return color_;
}

bool Player::isActive()
{
    return isActive_;
}

bool Player::isWinner()
{
    return isWinner_;
}

void Player::setActive(bool state)
{
    isActive_ = state;
}

void Player::setWinner(bool state)
{
    isWinner_ = state;
}

void Player::addPiece(std::shared_ptr<Piece> piece)
{
    pieces_.push_back(piece);
}

int Player::getPiecesNumber()
{
    return pieces_.size();
} //todo

Player::pieces Player::getPieces()
{
    return pieces_;
}

void Player::createPieces() {
    if (getColor() == WHITE){
        pieces_.push_back(std::make_shared<Piece>(0, 1, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(2, 2, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(4, 3, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(6, 4, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(9, 5, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(11, 6, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(13, 7, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(15, 8, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(16, 9, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(18, 10, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(20, 11, Element::WHITE_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(22, 12, Element::WHITE_PIECE, true, false));
    }
    else{
        pieces_.push_back(std::make_shared<Piece>(41, 1, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(43, 2, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(45, 3, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(47, 4, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(48, 5, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(50, 6, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(52, 7, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(54, 8, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(57, 9, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(59, 10, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(61, 11, Element::BLACK_PIECE, true, false));
        pieces_.push_back(std::make_shared<Piece>(63, 12, Element::BLACK_PIECE, true, false));
    }

}

void Player::hitPiece(int pos) {

    for(auto i = pieces_.begin(); i!=pieces_.end();i++) {

        if((*i)->getPosition() == pos)
        {
            pieces_.erase(i);
            break;
        }

    }

}

void Player::update()
{
    for (auto &piece : pieces_)
    {
        if(getColor()== BLACK) {
            if (piece->getPosition()>=0 && piece->getPosition()<=7)
            {
                piece->upgrade();
            }
        }
        else
        {
            if (piece->getPosition()>=56 && piece->getPosition()<=63)
            {
                piece->upgrade();
            }
        }
    }
}


std::shared_ptr<Piece> Player::getPieceById(int id) 
{

    
    for(auto piece: pieces_) 
	if( piece->getID() == id ) 
		return piece;
	
    
    
    return pieces_[0];
    

}
