// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInterface.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:13:37 by erobert           #+#    #+#             //
//   Updated: 2015/06/05 19:41:31 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "UserInterface.hpp"

UserInterface::UserInterface(void):
	_help(false)
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
	_window.clear(sf::Color(255, 212, 112));
	renderBoard(b);
	renderText(p1, p2);
	if (_help)
	{
		if (!p1.attribute().ai)
			drawStone(p1.calculusMove().x, p1.calculusMove().y, P1_HELP);
		if (!p2.attribute().ai)
			drawStone(p2.calculusMove().x, p2.calculusMove().y, P2_HELP);
	}
	_window.display();
}

UserInterface::sEvent const	&UserInterface::getEvent(void)
{
	sf::Event				event;
	float					position[2];

	_event.e = E_EVENT;
	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed
			|| (event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::Escape))
			_event.e = EXIT;
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			position[0] = sf::Mouse::getPosition(_window).x;
			position[1] = sf::Mouse::getPosition(_window).y;
			if (position[1] < HEIGHT + 64 && position[1] > 64)
			{
				_event.e = MOUSE;
				_event.x = position[0] / ((10 + 52.05 * 19.) / _size);
				_event.y = (position[1] - 64) / ((10 + 52.05 * 19.) / _size);
			}
			else if (position[1] > HEIGHT + 64 && position[1] < HEIGHT + 116)
			{
				if (position[0] > 190 && position[0] < 290)
					_event.e = P1_AI;
				else if (position[0] < 810 && position[0] > 710)
					_event.e = P2_AI;
				else if (position[0] < 600 && position[0] > 430)
					_help = !_help;
			}
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::P)
				_event.e = PLAY;
			else if (event.key.code == sf::Keyboard::N)
				_event.e = NEXT;
			else if (event.key.code == sf::Keyboard::S)
				_event.e = STOP;
		}
	}
	return (_event);
}

void						UserInterface::initWindow(void)
{
	float					scale[0];

	if (!_window.isOpen())
		_window.create(sf::VideoMode(WIDTH, HEIGHT + 128), "Gomoku");
	_window.setFramerateLimit(60);
	scale[0] = WIDTH;
	scale[0] /= _tBoard.getSize().x;
	scale[1] = HEIGHT;
	scale[1] /= _tBoard.getSize().y;
	_sBoard.scale(scale[0], scale[1]);
	_sBoard.setTexture(_tBoard);
	_sBoard.setPosition(0, 64);
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
	_stone[P1_HELP].setFillColor(sf::Color::Color(5, 250, 5, 150));
	_stone[P1_HELP].setOutlineColor(sf::Color::Black);
	_stone[P2_HELP].setFillColor(sf::Color::Color(5, 250, 5, 150));
	_stone[P2_HELP].setOutlineColor(sf::Color::White);
}
void						UserInterface::drawStone(int x, int y,
													 eStone stone)
{
	_stone[stone].setPosition((10 + 52.05 * x) * 19. / _size,
							  (10 + 52.05 * y) * 19. / _size + 64);
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
void						UserInterface::renderText(Player const &p1,
													  Player const &p2)
{
	_text.setCharacterSize(32);
	_text.setStyle(sf::Text::Bold);
	renderPlayers(p1, p2);
	renderSwitch(p1, p2);
}
void						UserInterface::renderPlayers(Player const &p1,
														 Player const &p2)
{
	_text.setColor(sf::Color::Black);
	_text.setPosition(64, 12);
	if (p1.attribute().win)
	{
		if (p1.attribute().captured > 4)
			_text.setString("BLACK WIN BY CAPTURE");
		else
			_text.setString("BLACK WIN");
		_window.draw(_text);
	}
	else if (!p2.attribute().win && p1.attribute().turn)
	{
		_text.setString("BLACK TURN");
		_window.draw(_text);
	}
	_text.setPosition(64, HEIGHT + 76);
	_text.setString("BLACK");
	_window.draw(_text);
	_text.setColor(sf::Color::White);
	_text.setPosition(64, 12);
	if (p2.attribute().win)
	{
		if (p2.attribute().captured > 4)
			_text.setString("WHITE WIN BY CAPTURE");
		else
			_text.setString("WHITE WIN");
		_window.draw(_text);
	}
	else if (!p1.attribute().win && p2.attribute().turn)
	{
		_text.setString("WHITE TURN");
		_window.draw(_text);
	}		
	_text.setString("WHITE");
	_text.setPosition(WIDTH - 162, HEIGHT + 76);
	_window.draw(_text);
}
void						UserInterface::renderSwitch(Player const &p1,
														Player const &p2)
{
	_text.setColor(sf::Color::Color(205, 92, 92));
	_text.setPosition(190, HEIGHT + 76);
	if (p1.attribute().ai)
		_text.setString("AI ON");
	else
		_text.setString("AI OFF");
	_window.draw(_text);
	if (p2.attribute().ai)
		_text.setString("AI ON");
	else
		_text.setString("AI OFF");
	_text.setPosition(WIDTH - 291, HEIGHT + 76);
	_window.draw(_text);
	_text.setColor(sf::Color::Color(95, 200, 160));
	if (_help)
		_text.setString("HELP ON");
	else
		_text.setString("HELP OFF");
	_text.setPosition(435, HEIGHT + 76);
	_window.draw(_text);
}
