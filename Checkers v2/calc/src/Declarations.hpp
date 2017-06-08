#ifndef DECLARATIONS_HPP
#define DECLARATIONS_HPP

#include <memory>
#include <iostream>
#include <cstdlib>
#include <vector>



const static int BOARD_SIZE = 8;

enum Color {BLACK, WHITE};

enum Element {WHITE_BLANK, BLACK_BLANK, WHITE_PIECE, BLACK_PIECE, OUT_OF_BOARD};

typedef std::vector<std::vector<Element>> Board;

#endif //DECLARATIONS_HPP
