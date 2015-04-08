// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUINCurses.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 14:44:53 by erobert           #+#    #+#             //
//   Updated: 2015/04/03 17:15:18 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GUINCurses.hpp"

GUINCurses::GUINCurses(void):
	_w(initscr())
{
	noecho();
	keypad(_w, 1);
	curs_set(0);
	start_color();
	_input[Game::EXIT] = 'q';
	_input[Game::UP] = 'w';
	_input[Game::LEFT] = 'a';
	_input[Game::DOWN] = 's';
	_input[Game::RIGHT] = 'd';
	_input[Game::F1] = '1';
	_input[Game::F2] = '2';
	_input[Game::F3] = '3';
}
GUINCurses::~GUINCurses(void)
{
	endwin();
}

void				GUINCurses::buildMap(std::vector<int> const &map,
										 int height, int width)
{
	int				i(0);

	_map = map;
	_height = height;
	_width = width;
	while (i < _height * _width)
	{
		if (_map[i])
			mvaddch(i / _width, i % _width, 'X');
		i++;
	}
	wrefresh(stdscr);
}
void							GUINCurses::updateDisplay(tNibbler const &tN,
														  int apple)
{
	tNibbler::const_iterator	it(tN.begin());
	tNibbler::const_iterator	ie(tN.end());
	int							i(0);

	while (i < _height * _width)
	{
		if (_map[i] == 3)
			mvaddch(i / _width, i % _width, ' ');
		i++;
	}
	mvaddch(apple / _width, apple % _width, '*');
	if (it != ie)
		mvaddch(it->y, it->x, 'O');
	it++;
	while (it != ie)
	{
		_map[it->x + it->y * _width] = 3;
		mvaddch(it->y, it->x, 'o');
		it++;
	}
	wrefresh(stdscr);
}
Game::eInput		GUINCurses::eventHandler(void)
{
	struct timeval	tv;
	fd_set			fds;
	int				input;
	int				i(0);

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
	if (FD_ISSET(STDIN_FILENO, &fds))
	{
		input = getch();
		while (i < Game::E_INPUT)
		{
			if (_input[i] == input)
				return (static_cast<Game::eInput>(i));
			i++;
		}
	}
	return (Game::E_INPUT);
}

GUINCurses			*createGUI(void)
{
	return (new GUINCurses);
}
void				deleteGUI(GUINCurses *gN)
{
	delete gN;
}
