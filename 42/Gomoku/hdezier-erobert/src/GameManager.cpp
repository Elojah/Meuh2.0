#include "GameManager.hpp"
#include "Rules.hpp"
#include <cstdlib>
#include <ctime>

GameManager::GameManager(void) :
	_turn(Cell::P1),
	_exit(false)
{
	std::srand(std::time(0));
}

GameManager::~GameManager(void)
{}

void				GameManager::init(void)
{
	/*Nothing to do here except if size changes*/
}

void				GameManager::loop(void)
{
	Player::vec2	move;

	_ui.init(19);
	_ui.render(_b, _p1, _p2);
	_p2.setIA(true);
	while (!_exit)
	{
		move = eventHandler();
		if (_turn == Cell::P1)
			move = _p1.play(_b, move);
		else if (_turn == Cell::P2)
			move = _p2.play(_b, move);
		if (move.x > -1 && move.y > -1
			&& Rules::makeMove(_b, move, _turn))
			_turn = _turn == Cell::P1 ? Cell::P2 : Cell::P1;
		_ui.render(_b, _p1, _p2);
	}
}

const Player::vec2	&GameManager::eventHandler(void)
{
	static Player::vec2				result;
	static UserInterface::sEvent	event;

	result.x = result.y = -1;
	event = _ui.getEvent();
	if (event.e == UserInterface::EXIT)
		_exit = true;
	else if (event.e == UserInterface::MOUSE)
	{
		result.x = event.x;
		result.y = event.y;
	}
	return (result);
}

