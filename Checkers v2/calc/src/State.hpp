// class represents actual board state
#ifndef STATE_HPP
#define STATE_HPP
#include "Declarations.hpp"
#include "Piece.hpp"
class State
{
private:
    Board board;
public:
    State();
    ~State(){};
    Element at(int position);
    void changeBoard(int position, Element element);
    std::vector<int>&& getPossibleMoves(std::shared_ptr<Piece> piece);
    Board getBoard();
};




#endif //STATE
