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
	_turn(P1),
	_exit(false)
<<<<<<< HEAD
=======
{}

GameManager::~GameManager(void)
>>>>>>> 82f5b62da3802cdffdbfc432b6413544d02ec05b
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
<<<<<<< HEAD
	_gB.render(reinterpret_cast<GUIBoard::eCell const **>(_board));
	while (!_exit)
	{
		eventHandler();
		_gB.render(reinterpret_cast<GUIBoard::eCell const **>(_board));
=======
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
>>>>>>> 82f5b62da3802cdffdbfc432b6413544d02ec05b
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
