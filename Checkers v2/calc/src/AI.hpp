
#ifndef AI_HPP
#define AI_HPP
#include "Player.hpp"

class AI: public Player
{
private:
public:
    AI(bool isActive, Color color);
    ~AI();
    void update();
    int* makeMove();
};


#endif //AI_HPP
