#include "Player.hpp"
#include <cstdlib>

Player::Player(void) :
	_ia(false)
{}

Player::~Player(void)
{}

void					Player::setIA(bool const &ia)
{
	_ia = ia;
}

const Player::vec2		&Player::play(Board const &b, Player::vec2 const &event)
{
	if (event.x > -1 && event.y > -1)
		_calculusMove = calculus(b);
	if (_ia)
		return (_calculusMove);
	else
		return (event);
}

const Player::vec2		&Player::calculus(Board const &b)
{
	static vec2			result;

	result.x = rand() % 19;
	result.y = rand() % 19;
	return (result);
}
