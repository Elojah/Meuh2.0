#include "GameManager.hpp"
#include "Rules.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

GameManager::GameManager(void):
	_end(false),
	_exit(false)
{
	std::srand(std::time(0));
}
GameManager::~GameManager(void) {}

void				GameManager::init(unsigned int size)
{
	_b.init(size);
	_ui.init(size);
	_p1.switchTurn();
	_p2.switchAI();
	_ui.render(_b, _p1, _p2);
}
void				GameManager::loop(void)
{
	Player::vec2	move;
	int				validMove;

	while (!_exit)
	{
		move = eventHandler();
		if (!_end)
		{
			if (_p1.attribute().turn)
				move = _p1.play(_b, move);
			else if (_p2.attribute().turn)
				move = _p2.play(_b, move);
			if (move.x > -1 && move.y > -1)
			{
				validMove = Rules::makeMove(_b, move, _p1, _p2);
				if (validMove == Rules::OK)
				{
					_p1.switchTurn();
					_p2.switchTurn();
				}
				else if (_p1.attribute().win || _p2.attribute().win)
					_end = true;
			}
			_ui.render(_b, _p1, _p2);
		}
	}
}

Player::vec2 const	&GameManager::eventHandler(void)
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
	else if (event.e == UserInterface::P1_AI)
		_p1.switchAI();
	else if (event.e == UserInterface::P2_AI)
		_p2.switchAI();
	else if (event.e == UserInterface::PLAY)
		_audio.playMusic(AudioManager::HYMNE_A_LA_KRO);
	else if (event.e == UserInterface::NEXT)
		_audio.nextMusic();
	else if (event.e == UserInterface::STOP)
		_audio.stopMusic();
	return (result);
}

