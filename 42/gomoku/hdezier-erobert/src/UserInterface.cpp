// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInterface.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:13:37 by erobert           #+#    #+#             //
//   Updated: 2015/05/28 13:32:51 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "UserInterface.hpp"

UserInterface::UserInterface(void) {}
UserInterface::~UserInterface(void)
{
	if (_window.isOpen())
		_window.close();
}

void						UserInterface::init(int size)
{
	float					scale[0];
	int						i(-1);

	_tBoard.loadFromFile("data/goban-19.bmp");
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
	while (++i < E_STONE)
	{
		_stone[i].setRadius(21);
		_stone[i].setOutlineThickness(2);
	}
	_stone[BLACK].setFillColor(sf::Color::Black);
	_stone[BLACK].setOutlineColor(sf::Color::Color(5, 5, 5, 100));
	_stone[WHITE].setFillColor(sf::Color::White);
	_stone[WHITE].setOutlineColor(sf::Color::Color(250, 250, 250, 100));
	_stone[HELP].setFillColor(sf::Color::Color(5, 250, 5, 150));
	_stone[HELP].setOutlineColor(sf::Color::Color(5, 250, 5, 100));
}
void						UserInterface::render(Board const &b,
												  Player const &p1,
												  Player const &p2)
{
	_window.draw(_sBoard);
	drawStone(0, 0, BLACK);
	drawStone(8, 8, WHITE);
	drawStone(5, 7, HELP);
	_window.display();
}
UserInterface::sEvent const	&UserInterface::getEvent(void)
{
	static sEvent			event;

	event.e = E_EVENT;
	_window.waitEvent(_event);
	if (_event.type == sf::Event::Closed || _event.key.code == 'q')
		event.e = EXIT;
	return (event);
}

void						UserInterface::drawStone(int x, int y,
													 eStone stone)
{
	_stone[stone].setPosition(10 + 52.05 * x, 10 + 52.05 * y);
	_window.draw(_stone[stone]);
}
