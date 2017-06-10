
#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "Player.hpp"


/*!
	#klasa potomna playera 
*/
class Human: public Player
{
private:

public:
    Human(bool isActive, Color color);
    ~Human();
    void update();

};




#endif //PLAYER_HPP
