// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameManager.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/18 11:07:18 by erobert           #+#    #+#             //
//   Updated: 2015/05/25 16:51:51 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameManager.hpp"

GameManager::GameManager(void):
	_size(19),
	_turn(P1),
	_exit(false)
{}

GameManager::~GameManager(void)
{}

void					GameManager::initBoard(eSize size)
{
	if (size != BIG)
		_size = (size == MEDIUM ? 13 : 9);
	_gB.init(_size);
	for (unsigned int i = 0; i < _size; ++i)
	{
		for (unsigned int j = 0; j < _size; ++j)
			_board[i][j] = EMPTY;
	}
}

void					GameManager::gameLoop(void)
{
	Player::sMove				currentMove;

	_gB.render();
	while (!_exit)
	{
		if (_turn == P1)
			currentMove = _p1.getMove();
		else if (_turn == P2)
			currentMove = _p2.getMove();
		if (isValidMove(currentMove))
			applyMove(currentMove);
		else
			continue ;
		_gB.render();
	}
}

void					GameManager::eventHandler(void)
{
	static int	e;

	e = _gB.getEvent();
	if (e == GUIBoard::EXIT)
		_exit = true;
	// else if (e == GUIBoard::TOKEN)
	// {
	// 	if ()
	// }
}

bool				GameManager::isValidMove(Player::sMove &move)
{
	for (unsigned short i = 0; i < _size; ++i)
	{
		for (unsigned short j = 0; j < _size; ++j)
		{
			;
		}
	}
}

void			GameManager::applyMove(Player::sMove &move)
{
	_board[move.x][move.y] = _turn;
}
