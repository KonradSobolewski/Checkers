
#ifndef MOVE_HPP
#define MOVE_HPP
#include "Piece.hpp"

/*!
	# klasa tworzy obiekt ruchu jaki jest planowany do wykonania, umożliwia to testy o poprwaności ruchu
	@ pos - pozycja pionka
	@ humanMove - czyj ruch
	@ piece - pionek który wykonuje ruch 
	@ isHit - czy ruch powoduje bicie pionka
	@ hitPosition - pozycja bitego pionka
*/
class Move
{
private:
    int pos_;
    bool humanMove_;
    bool isHit_;
    int hitPosition_;
    std::shared_ptr<Piece> piece_;
public:
    Move(int pos, bool humanMove, std::shared_ptr<Piece> piece, bool isHit, int hitPosition);
    ~Move(){};
    int getPos() const ;
    std::shared_ptr<Piece> getPiece() ;
    bool isHumanMove() const ;
    void setPos(int pos) ;
    void setWhoseMove(bool isHumanMove);
    bool isHit() ;
    int getHitPos() ;
};

#endif //GAME_HPP
