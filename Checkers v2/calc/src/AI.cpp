#include "AI.hpp"

AI::AI(bool isActive, Color color): Player(isActive, color)
{

}

AI::~AI()
{

}

void AI::update()
{

}

int* AI::makeMove()
{
    int *simpleMove = new int[2];
    simpleMove[0] = 1;
    simpleMove[1] = 2;
    return simpleMove;
}


