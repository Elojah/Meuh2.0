#include "Player.hpp"

Player::Player(void) :
	_ia(false)
{}

Player::~Player(void)
{}

const Player::vec2		&Player::play(Board const &b, Player::vec2 const &event)
{
	if (_ia)
		return (calculus(b));
	else
		return (event);
}

const Player::vec2		&Player::calculus(Board const &b)
{
	static vec2			result;

	result.x = -1;
	result.y = -1;
	return (result);
}
