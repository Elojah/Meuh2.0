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
	_width(1024),
	_height(1024),
	_size(19),
	_exit(false)
{}
GameManager::~GameManager(void)
{
	if (_window.isOpen())
		_window.close();
}

void					GameManager::initBoard(eSize size)
{
	sf::Texture			tBoard;
	sf::Sprite			sBoard;

	tBoard.loadFromFile("data/goban");
	_width = tBoard.getSize().x;
	_height = tBoard.getSize().y;
	if (size != BIG)
		_size = (size == MEDIUM ? 15 : 9);
	if (!_window.isOpen())
		_window.create(sf::VideoMode(_width, _height), "Gomoku");
	_window.clear(sf::Color(212, 177, 106));
	sBoard.scale(tBoard.getSize().x / _width, tBoard.getSize().y / _height);
	sBoard.setTexture(tBoard);
	_window.draw(sBoard);
	_window.display();
}
void					GameManager::gameLoop(void)
{
	while (!_exit)
	{
		eventHandler();
//		_window.display();
	}
}

void					GameManager::eventHandler(void)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed)
			_exit = true;
	}
}
