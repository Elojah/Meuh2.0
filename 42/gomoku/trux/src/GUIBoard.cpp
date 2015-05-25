// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUIBoard.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/25 17:46:43 by erobert           #+#    #+#             //
//   Updated: 2015/05/25 18:00:32 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GUIBoard.hpp"

GUIBoard::GUIBoard(void) {}
GUIBoard::~GUIBoard(void)
{
	if (_window.isOpen())
		_window.close();
}

void	GUIBoard::init(int size)
{
	float	scale[0];

	_size = size;
	(void)_size;
	_tBoard.loadFromFile("data/goban");
	if (!_window.isOpen())
		_window.create(sf::VideoMode(WIDTH, HEIGHT), "Gomoku");
	_window.clear(sf::Color(212, 177, 106));
	_window.setFramerateLimit(60);
	scale[0] = WIDTH;
	scale[0] /= _tBoard.getSize().x;
	scale[1] = HEIGHT;
	scale[1] /= _tBoard.getSize().y;
	_sBoard.scale(scale[0], scale[1]);
	_sBoard.setTexture(_tBoard);
}
void	GUIBoard::render(int *board)
{
	_window.draw(_sBoard);
	_window.display();
}
int		GUIBoard::getEvent(void)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed || _event.key.code == 'q')
			return (EXIT);
	}
	return (E_EVENT);
}
