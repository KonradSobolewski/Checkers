#include "Human.hpp"

Human::Human(bool isActive, Color color): Player(isActive, color)
{
	createPieces();
}

Human::~Human()
{
	
}

void Human::update()
{

}

