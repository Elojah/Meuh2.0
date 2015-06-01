#include "GameManager.hpp"
#include "Rules.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

GameManager::GameManager(void):
	_turn(Cell::P1),
	_exit(false)
{
	std::srand(std::time(0));
}

GameManager::~GameManager(void)
{}

void				GameManager::init(unsigned int size)
{
	_b.setSize(size);
	_ui.init(size);
	_ui.render(_b, _p1, _p2);
	_p2.setAI(true);
}

void				GameManager::loop(void)
{
	Player::vec2	move;
	int				validMove;

	while (!_exit)
	{
		move = eventHandler();
		if (_turn == Cell::P1)
			move = _p1.play(_b, move);
		else if (_turn == Cell::P2)
			move = _p2.play(_b, move);
		if (move.x > -1 && move.y > -1)
		{
			validMove = Rules::makeMove(_b, move, _turn);
			if (validMove == Rules::OK)
				_turn = OPPONENT(_turn);
			else if (validMove == Rules::WIN)
			{
				std::cout << "Player:\t" << _turn << " wins !" << std::endl;
				_turn = OPPONENT(_turn);
			}
		}
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
	else if (event.e == UserInterface::P1_AI)
		_p1.setAI(!_p1.ai());
	else if (event.e == UserInterface::P2_AI)
		_p2.setAI(!_p2.ai());
	else if (event.e == UserInterface::PLAY)
		_audio.playMusic(AudioManager::HYMNE_A_LA_KRO);
	else if (event.e == UserInterface::NEXT)
		_audio.nextMusic();
	else if (event.e == UserInterface::STOP)
		_audio.stopMusic();
	return (result);
}

