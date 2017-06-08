
#include "State.hpp"

State::State() {

    for (int i = 0; i < BOARD_SIZE; i++) {
        board.push_back(std::vector<Element>(BOARD_SIZE, Element::WHITE_BLANK));
        for (int j = 0; j < BOARD_SIZE; j++) {

            if ((i + j) % 2 == 0)
                board[i][j] = Element::BLACK_BLANK;
            else
                board[i][j] = Element::WHITE_BLANK;

        }

    }

    for(int i = 0; i < BOARD_SIZE; i++) {

        if( i <= 2) {
            for(int j = 0 ; j < BOARD_SIZE; j++)
                if((i + j) % 2 == 0)
                    board[i][j] = Element::WHITE_PIECE;
        }
        else if(i >= BOARD_SIZE - 2) {
            for(int j = 0 ; j < BOARD_SIZE; j++)
                if((i + j) % 2 == 0)
                    board[i][j] = Element::BLACK_PIECE;
        }

    }
}

Element State::at(int position) {
    
    if(position < 0 || position > 63)
	return Element::OUT_OF_BOARD;
    else
    	return board[position/BOARD_SIZE][position%BOARD_SIZE];

}

std::vector<int>&& State::getPossibleMoves(std::shared_ptr<Piece> piece){

    std::vector<int> *possibleMoves = new std::vector<int>();
    int posPiece = piece->getPosition();
    Element pieceColor = piece->getColor();
    Element oppositeColor;
    if(pieceColor == Element::WHITE_PIECE)
        oppositeColor = Element::BLACK_PIECE;
    else
        oppositeColor = Element::WHITE_PIECE;

        if(at(posPiece + 9) == Element::BLACK_BLANK && posPiece % BOARD_SIZE != 7)
            possibleMoves->push_back(posPiece + 9);
        if(at(posPiece + 9 ) == oppositeColor && at(posPiece + 18) == Element::BLACK_BLANK && posPiece % BOARD_SIZE != 7)
            possibleMoves->push_back(posPiece + 18);
        if(at(posPiece + 7) == Element::BLACK_BLANK && posPiece % BOARD_SIZE != 0)
            possibleMoves->push_back(posPiece + 7);
        if(at(posPiece + 7 ) == oppositeColor && at(posPiece + 14) == Element::BLACK_BLANK && posPiece % BOARD_SIZE != 0)
            possibleMoves->push_back(posPiece + 14);



        if(at(posPiece - 9) == Element::BLACK_BLANK && posPiece % BOARD_SIZE != 0)
            possibleMoves->push_back(posPiece - 9);
        if(at(posPiece - 9 ) == oppositeColor && at(posPiece - 18) == Element::BLACK_BLANK && posPiece % BOARD_SIZE != 0)
            possibleMoves->push_back(posPiece - 18);
        if(at(posPiece - 7) == Element::BLACK_BLANK && posPiece % BOARD_SIZE != 7)
            possibleMoves->push_back(posPiece - 7);
        if(at(posPiece - 7 ) == oppositeColor && at(posPiece - 14) == Element::BLACK_BLANK && posPiece % BOARD_SIZE != 7)
            possibleMoves->push_back(posPiece - 14);



    return std::move(*possibleMoves);

}

void State::changeBoard(int position, Element element)
{

    board[position/BOARD_SIZE][position%BOARD_SIZE] = element;

}
