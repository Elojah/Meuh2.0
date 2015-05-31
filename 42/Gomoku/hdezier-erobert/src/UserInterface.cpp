// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInterface.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:13:37 by erobert           #+#    #+#             //
//   Updated: 2015/05/31 15:24:15 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "UserInterface.hpp"

UserInterface::UserInterface(void)
{
	_font.loadFromFile("data/open_sans_light.ttf");
	_text.setFont(_font);
}
UserInterface::~UserInterface(void)
{
	if (_window.isOpen())
		_window.close();
}

void						UserInterface::init(int size)
{
	_size = size;
	if (_size == 19)
		_tBoard.loadFromFile("data/goban-19.bmp");
	else if (_size == 13)
		_tBoard.loadFromFile("data/goban-13.bmp");
	else
		_tBoard.loadFromFile("data/goban-9.bmp");
	initWindow();
	initStone();
}
void						UserInterface::render(Board const &b,
												  Player const &p1,
												  Player const &p2)
{
	_window.clear(sf::Color(50, 100, 250));
	renderBoard(b);
	renderPlayers(p1, p2);
	if (!p1.ai())
		drawStone(p1.calculusMove().x, p1.calculusMove().y, HELP);
	if (!p2.ai())
		drawStone(p2.calculusMove().x, p2.calculusMove().y, HELP);
	_window.display();
}

UserInterface::sEvent const	&UserInterface::getEvent(void)
{
	sf::Event				event;
	float					position[2];

	_event.e = E_EVENT;
	_window.waitEvent(event);
	if (event.type == sf::Event::Closed 
		|| (event.type == sf::Event::KeyPressed
			&& event.key.code == sf::Keyboard::Escape))
		_event.e = EXIT;
	else if (event.type == sf::Event::MouseButtonPressed)
	{
		position[0] = sf::Mouse::getPosition(_window).x;
		position[1] = sf::Mouse::getPosition(_window).y;
		if (position[1] < HEIGHT)
		{
			_event.e = MOUSE;
			_event.x = position[0] / ((10 + 52.05 * 19.) / _size);
			_event.y = position[1] / ((10 + 52.05 * 19.) / _size);
		}
		else if (position[1] > HEIGHT + 12 && position[1] < HEIGHT + 52)
		{
			if (position[0] > 190 && position[0] < 290)
				_event.e = P1_AI;
			else if (position[0] < 810 && position[0] > 710)
				_event.e = P2_AI;
		}
	}
	return (_event);
}

void						UserInterface::initWindow(void)
{
	float					scale[0];

	if (!_window.isOpen())
		_window.create(sf::VideoMode(WIDTH, HEIGHT + 64), "Gomoku");
	_window.setFramerateLimit(60);
	scale[0] = WIDTH;
	scale[0] /= _tBoard.getSize().x;
	scale[1] = HEIGHT;
	scale[1] /= _tBoard.getSize().y;
	_sBoard.scale(scale[0], scale[1]);
	_sBoard.setTexture(_tBoard);
}
void						UserInterface::initStone(void)
{
	int						i(-1);

	while (++i < E_STONE)
	{
		_stone[i].setRadius(21 * 19. / _size);
		_stone[i].setOutlineThickness(2);
	}
	_stone[BLACK].setFillColor(sf::Color::Black);
	_stone[BLACK].setOutlineColor(sf::Color::Color(5, 5, 5, 100));
	_stone[WHITE].setFillColor(sf::Color::White);
	_stone[WHITE].setOutlineColor(sf::Color::Color(250, 250, 250, 100));
	_stone[HELP].setFillColor(sf::Color::Color(5, 250, 5, 150));
	_stone[HELP].setOutlineColor(sf::Color::Color(5, 250, 5, 100));
}
void						UserInterface::drawStone(int x, int y,
													 eStone stone)
{
	_stone[stone].setPosition((10 + 52.05 * x) * 19. / _size,
							  (10 + 52.05 * y) * 19. / _size);
	_window.draw(_stone[stone]);
}
void						UserInterface::renderBoard(Board const &b)
{
	int						i(-1);
	int						j;
	Cell::eValue			value;

	_window.draw(_sBoard);
	while (++i < _size)
	{
		j = -1;
		while (++j < _size)
		{
			value = b.getValue(i, j);
			if (value == Cell::P1)
				drawStone(i, j, BLACK);
			else if (value == Cell::P2)
				drawStone(i, j, WHITE);
		}
	}
}
void						UserInterface::renderPlayers(Player const &p1,
														 Player const &p2)
{
	size_t					position;

	_text.setCharacterSize(32);
	_text.setStyle(sf::Text::Bold);
	_text.setColor(sf::Color::Black);
	_text.setPosition(64, HEIGHT + 12);
	_text.setString("BLACK");
	_window.draw(_text);
	_text.setColor(sf::Color::Color(95, 200, 160));
	_text.setPosition(190, HEIGHT + 12);
	if (p1.ai())
		_text.setString("AI ON");
	else
		_text.setString("AI OFF");
	_window.draw(_text);
	_text.setColor(sf::Color::White);
	position = WIDTH - 64 - _text.getLocalBounds().width;
	_text.setPosition(position, HEIGHT + 12);
	_text.setString("WHITE");
	_window.draw(_text);
	_text.setColor(sf::Color::Color(95, 200, 160));
	if (p2.ai())
		_text.setString("AI ON");
	else
		_text.setString("AI OFF");
	position -= _text.getLocalBounds().width + 32;
	_text.setPosition(position, HEIGHT + 12);
	_window.draw(_text);
}
