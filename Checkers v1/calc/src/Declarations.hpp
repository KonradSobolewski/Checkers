#ifndef DECLARATIONS_HPP
#define DECLARATIONS_HPP

#include <memory>
#include <iostream>
#include <cstdlib>
#include <vector>



const static int BOARD_SIZE = 8;

typedef std::vector<std::vector<bool>> Board;

enum Color {BLACK, WHITE};

enum class Element {WHITE_BLANK, BLACK_BLANK, WHITE_PIECE, BLACK_PIECE};

#endif //DECLARATIONS_HPP
