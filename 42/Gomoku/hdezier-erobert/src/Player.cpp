#include "Player.hpp"
#include <cstdlib>

Player::Player(void):
	_ai(false)
{}
Player::~Player(void) {}

bool					Player::ai(void) const
{
	return (_ai);
}
Player::vec2 const		&Player::calculusMove(void) const
{
	return (_calculusMove);
}

void					Player::setAI(bool const &ai)
{
	_ai = ai;
}
Player::vec2 const		&Player::play(Board const &b, Player::vec2 const &event)
{
	_calculusMove = calculus(b);
	if (_ai)
		return (_calculusMove);
	else
		return (event);
}

Player::vec2 const		&Player::calculus(Board const &b)
{
	static vec2			result;

	result.x = rand() % 19;
	result.y = rand() % 19;
	return (result);
}
