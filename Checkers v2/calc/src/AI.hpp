#ifndef AI_HPP
#define AI_HPP
#include "Player.hpp"
#include "State.hpp"
#include "Move.hpp"
#include "RandElement.h"

/*!
	Klasa odpowiada ze sztuczną inteligencje 
	@ color - decyzja jaki kolor pionków posiada AI
	@ isActive  - czy obecnie jest ruch AI
*/
class AI: public Player
{
private:
public:
    AI(bool isActive, Color color);
    ~AI();
    void update();
    std::shared_ptr<Move> makeMove(std::shared_ptr<State>);
};


#endif //AI_HPP
