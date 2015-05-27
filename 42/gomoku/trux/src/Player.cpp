#include "Player.hpp"

Player::Player(void) :
	_ia(false)
{}

Player::~Player(void)
{}

sMove		Player::getMove(void)
{
	static sMove	move;

	if (_ia)
		;
	else
		;
	move.x = 0;
	move.y = 0;
	return (move);
}
