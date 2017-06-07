
#ifndef MOVE_HPP
#define MOVE_HPP
#include "Piece.hpp"

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
