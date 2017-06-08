
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Piece.hpp"
#include "Declarations.hpp"

class Player
{
private:
    Color color_;
    bool isActive_;
    bool isWinner_;
    typedef std::vector<std::shared_ptr<Piece>> pieces;
    pieces pieces_;
public:
    Player(bool isActive, Color color);
    ~Player();
    Color getColor();
    bool isActive();
    bool isWinner();
    void setActive(bool state);
    void setWinner(bool state);
    void addPiece(std::shared_ptr<Piece> piece);
    pieces getPieces();
    int getPiecesNumber();
    void createPieces();
    void hitPiece(int pos);
    std::shared_ptr<Piece>  getPieceById(int id);
    virtual void update();
};




#endif //PLAYER_HPP
