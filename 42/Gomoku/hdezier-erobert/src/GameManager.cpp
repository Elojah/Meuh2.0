/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:00:49 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/02 20:26:00 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameManager.hpp"
#include "Rules.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

GameManager::GameManager(void):
	_end(false),
	_restart(false),
	_exit(false)
{
	std::srand(std::time(0));
}
GameManager::~GameManager(void) {}

void								GameManager::init(unsigned int size)
{
	Rules::reset();
	_b.init(size);
	_ui.init(size);
	_p1.switchTurn();
	_p2.switchAI();
	_ui.render(_b, _p1, _p2);
}
bool								GameManager::loop(void)
{
	Player::vec2					move;
	Rules::eValidity				validity;

	while (!_exit)
	{
		move = eventHandler();
		if (!_end)
		{
			if (_p1.play(_b, move, _p2) || _p2.play(_b, move, _p1))
			{
				validity = Rules::makeMove(_b, _p1, _p2);
				if (validity == Rules::OK)
				{
					_p1.switchTurn();
					_p2.switchTurn();
				}
				else if (validity != Rules::INVALID)
					_end = true;
			}
			_ui.render(_b, _p1, _p2);
		}
	}
	return (_restart);
}

Player::vec2 const					&GameManager::eventHandler(void)
{
	static Player::vec2				result;
	static UserInterface::sEvent	event;

	result.x = -1;
	result.y = -1;
	event = _ui.getEvent();
	if (event.e == UserInterface::EXIT)
		_exit = true;
	else if (event.e == UserInterface::RESTART)
	{
		_restart = true;
		_exit = true;
	}
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

