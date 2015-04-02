// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/27 18:40:55 by erobert           #+#    #+#             //
//   Updated: 2015/04/02 16:33:18 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"
#include "IGUINibbler.hpp"

Game::Game(void):
	_height(MAX_SIZE),
	_width(MAX_SIZE),
	_map(MAX_SIZE * MAX_SIZE)
{}
Game::~Game(void) {}

bool					Game::buildMap(char *height, char *width)
{
	std::stringstream	ss;
	int					i(0);
	
	ss << height;
	ss >> _height;
	ss.clear();
	ss << width;
	ss >> _width;
	if (_height < MIN_SIZE || _height > MAX_SIZE)
		return (printError());
	if (_width < MIN_SIZE || _width > MAX_SIZE)
		return (printError());
	while (i < _height * _width)
	{
		if (i /_width == 0 || i / _width == _height - 1)
			_map[i] = WALL;
		else if (i % _width == 0 || i % _width == _width - 1)
			_map[i] = WALL;
		i++;
	}
	std::cout << "Map " << _height << "x" << _width 
			  << " build." << std::endl;
	return (true);
}

void					Game::gameLoop(void)
{
	int					exit(false);
	int					apple;
	sNibbler			head;

	_dlHandle[0] = dlopen("f1/f1.so", RTLD_LAZY | RTLD_LOCAL);
	if (!_dlHandle[0])
	{
		std::cerr << "Error: " << dlerror() << "." << std::endl;
		return ;
	}
	_gC = reinterpret_cast<tGUICreator>((dlsym(_dlHandle[0], "createGUI")));
	IGUINibbler	*gN(_gC());
	gN->buildMap(_map, _height, _width);
	initNibbler();
	std::srand(clock());
	apple = newApple();
	_map[apple] = APPLE;
	while (!exit)
	{
		gN->updateDisplay(_nibbler, apple);
		head = _nibbler.front();
		if (gN->eventHandler() == ESC)
			exit = true;
		head.y++;
		_nibbler.push_front(head);
		if (eatApple(apple))
		{
			_map[apple] = HEAD;
			apple = newApple();
		}
		else if (isDead())
			exit = true;
		else
		{
			_map[_nibbler.back().x + _nibbler.back().y * _width] = EMPTY;
			_nibbler.pop_back();
		}
		usleep(500000);
	}
	_gD = reinterpret_cast<tGUIDestructor>((dlsym(_dlHandle[0], "deleteGUI")));
	_gD(gN);
	dlclose(_dlHandle[0]);
}

void					Game::initNibbler(void)
{
	sNibbler			nibbler;

	nibbler.state = ALIVE;
	nibbler.dir = DOWN;
	nibbler.x = _width / 2;
	nibbler.y = _height / 2;
	_map[nibbler.x + nibbler.y * _width] = BODY;
	_nibbler.push_back(nibbler);
	nibbler.y--;
	_map[nibbler.x + nibbler.y * _width] = BODY;
	_nibbler.push_back(nibbler);
	nibbler.y += 2;
	_map[nibbler.x + nibbler.y * _width] = HEAD;
	_nibbler.push_front(nibbler);
}
int						Game::newApple(void)
{
	int					apple;

	apple = std::rand() % (_height * _width);
	while (_map[apple] != EMPTY)
		apple = std::rand() % (_height * _width);
	return (apple);
}
bool					Game::eatApple(int apple)
{
	sNibbler			&head(_nibbler.front());

	if (apple == head.x + head.y * _width)
		return (true);
	return (false);
}
bool					Game::isDead(void)
{
	sNibbler			&head(_nibbler.front());

	if (_map[head.x + head.y * _width] != EMPTY)
	{
		head.state = DEAD;
		return (true);
	}
	return (false);
}
bool					Game::printError(void) const
{
	std::cerr << "Size must be between "
			  << MIN_SIZE << " and " << MAX_SIZE
			  << "." << std::endl;
	return (false);
}
void					Game::printMap(void) const
{
	int					i(0);

	while (i < _height * _width)
	{
		if (i % _width == 0 && i)
			std::cout << std::endl;
		std::cout << _map[i];
		i++;
	}
	std::cout << std::endl;
}
