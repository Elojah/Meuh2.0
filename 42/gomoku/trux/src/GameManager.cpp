// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameManager.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/18 11:07:18 by erobert           #+#    #+#             //
//   Updated: 2015/05/26 15:49:52 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameManager.hpp"

GameManager::GameManager(void):
	_size(19),
	_turn(true),
	_exit(false)
{}
GameManager::~GameManager(void) {}

void					GameManager::initBoard(eSize size)
{
	unsigned int		i;

	if (size != BIG)
		_size = (size == MEDIUM ? 13 : 9);
	_gB.init(_size);
	for (i = 0; i < _size; ++i)
	{
		_board[i][0] = GUIBoard::EMPTY;
	}
}
void					GameManager::gameLoop(void)
{
	_gB.render(reinterpret_cast<GUIBoard::eCell const **>(_board));
	while (!_exit)
	{
		eventHandler();
		_gB.render(reinterpret_cast<GUIBoard::eCell const **>(_board));
	}
}

void					GameManager::eventHandler(void)
{
	GUIBoard::sEvent	event;

	event = _gB.getEvent();
	if (event.e == GUIBoard::EXIT)
		_exit = true;

	// {
	// 	if ()
	// }
}
