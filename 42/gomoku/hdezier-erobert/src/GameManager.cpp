#include "GameManager.hpp"
#include "Rules.hpp"

GameManager::GameManager(void) :
	_turn(P1),
	_exit(false)
{}

GameManager::~GameManager(void)
{}

void				GameManager::init(void)
{
	/*Nothing to do here except if size change*/
}

void				GameManager::loop(void)
{
	Player::vec2	move;

	_ui.render(_b, _p1, _p2);
	_b.display();
	while (!_exit)
	{
		move = eventHandler();
		if (_turn == P1)
			move = _p1.play(_b, move);
		else if (_turn == P2)
			move = _p2.play(_b, move);
		if (Rules::makeMove(_b, move, _turn))
			_turn = _turn == P1 ? P2 : P1;
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
	return (result);
}

