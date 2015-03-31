// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/27 18:40:55 by erobert           #+#    #+#             //
//   Updated: 2015/03/31 15:22:35 by erobert          ###   ########.fr       //
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
			_map[i] = 1;
		else if (i % _width == 0 || i % _width == _width - 1)
			_map[i] = 1;
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
	int					tmp;

	_dlHandle = dlopen("f1/f1.so", RTLD_LAZY | RTLD_LOCAL);
	if (!_dlHandle)
	{
		std::cerr << "Error: " << dlerror() << "." << std::endl;
		return ;
	}
	_gC = reinterpret_cast<tGUICreator>((dlsym(_dlHandle, "createGUI")));
	IGUINibbler	*gN(_gC());
	gN->buildMap(_map);
	std::srand(clock());
	while (!exit)
	{
		apple = std::rand() % (_height * _width);
		while (_map[apple] == 1)
			apple = std::rand() % (_height * _width);
		tmp = _map[apple];
		_map[apple] = 2;
		printMap();
		_map[apple] = tmp;
		return ;
	}
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
