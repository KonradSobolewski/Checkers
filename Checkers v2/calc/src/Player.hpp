
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Piece.hpp"
#include "Declarations.hpp"

typedef std::vector<std::shared_ptr<Piece>> pieces;

class Player
{
private:
    Color color_;
    bool isActive_;
    bool isWinner_;
protected:
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
    std::shared_ptr<Piece>  getPieceByPosition(int pos);
    virtual void update();
};




#endif //PLAYER_HPP
