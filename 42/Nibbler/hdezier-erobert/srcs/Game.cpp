// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/27 18:40:55 by erobert           #+#    #+#             //
//   Updated: 2015/04/07 19:32:34 by erobert          ###   ########.fr       //
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
	return (true);
}

void					Game::gameLoop(void)
{
	bool				pause(false);
	bool				alive(true);
	int					apple;
	int					gui(0);
	eInput				input(E_INPUT);

	if (initDL())
		return ;
	initNibbler();
	createGUI(gui);
	std::srand(clock());
	apple = newApple();
	while (input != EXIT)
	{
		input = _gN[gui]->eventHandler();
		if (input == PAUSE)
			pause = !pause;
		else if (input >= F1 && input <= F3)
		{
			_gN[gui]->updateDisplay(_nibbler, apple);
			destroyGUI(gui);
			pause = true;
			gui = input;
			createGUI(gui);
			_gN[gui]->updateDisplay(_nibbler, apple);
		}
		else if (input == RESTART)
		{
			alive = true;
			initNibbler();
			_gN[gui]->buildMap(_map, _height, _width);
		}
		if (alive && !pause)
		{
			_gN[gui]->updateDisplay(_nibbler, apple);
			moveNibbler(input);
			if (eatApple(apple))
				apple = newApple();
			else if (isDead())
				alive = false;
			else
			{
				_map[_nibbler.back().x + _nibbler.back().y * _width] = EMPTY;
				_nibbler.pop_back();
			}
			_map[_nibbler.front().x + _nibbler.front().y * _width] = HEAD;
		}
		usleep(100000);
	}
	destroyGUI(gui);
	closeDL();
}

void					Game::initNibbler(void)
{
	sNibbler			nibbler;
	tNibbler::iterator	it(_nibbler.begin());
	tNibbler::iterator	ie(_nibbler.end());

	while (it != ie)
	{
		_map[it->x + it->y * _width] = EMPTY;
		it++;
	}
	_nibbler.clear();
	nibbler.state = ALIVE;
	nibbler.dir = DOWN;
	nibbler.x = _width / 2;
	nibbler.y = _height / 2;
	_map[nibbler.x + nibbler.y * _width] = BODY;
	_nibbler.push_back(nibbler);
	nibbler.y--;
	_map[nibbler.x + nibbler.y * _width] = BODY;
	_nibbler.push_back(nibbler);
	nibbler.y--;
	_map[nibbler.x + nibbler.y * _width] = BODY;
	_nibbler.push_back(nibbler);
	nibbler.y += 3;
	_map[nibbler.x + nibbler.y * _width] = HEAD;
	_nibbler.push_front(nibbler);
}
int						Game::initDL(void)
{
	int					i(0);
	int					j(0);

	_dlHandle[0] = dlopen("f1/f1.so", RTLD_LAZY | RTLD_LOCAL);
	if (_dlHandle[0])
	{
		_dlHandle[1] = dlopen("f2/f2.so", RTLD_LAZY | RTLD_LOCAL);
		if (_dlHandle[1])
			_dlHandle[2] = dlopen("f3/f3.so", RTLD_LAZY | RTLD_LOCAL);
	}
	while (i < 3)
	{
		if (!_dlHandle[i])
		{
			std::cerr << "Error: " << dlerror() << "." << std::endl;
			while (j < i)
				dlclose(_dlHandle[j++]);
			return (-1);
		}
		i++;
	}
	return (0);
}
void					Game::closeDL(void)
{
	dlclose(_dlHandle[0]);
	dlclose(_dlHandle[1]);
	dlclose(_dlHandle[2]);
}
void					Game::createGUI(int gui)
{
	tGUICreator			gC;

	gC = reinterpret_cast<tGUICreator>((dlsym(_dlHandle[gui],
											  "createGUI")));
	_gN[gui] = gC();
	_gN[gui]->buildMap(_map, _height, _width);
}
void					Game::destroyGUI(int gui)
{
	tGUIDestructor		gD;

	gD = reinterpret_cast<tGUIDestructor>((dlsym(_dlHandle[gui],
												 "deleteGUI")));
	gD(_gN[gui]);
}

int						Game::newApple(void)
{
	int					apple;

	apple = std::rand() % (_height * _width);
	while (_map[apple] != EMPTY)
		apple = std::rand() % (_height * _width);
	return (apple);
}
void					Game::moveNibbler(eInput input)
{
	sNibbler			head(_nibbler.front());

	_map[head.x + head.y * _width] = BODY;
	if (input == UP && head.dir != DOWN)
		head.dir = UP;
	else if (input == LEFT && head.dir != RIGHT)
		head.dir = LEFT;
	else if (input == DOWN && head.dir != UP)
		head.dir = DOWN;
	else if (input == RIGHT && head.dir != LEFT)
		head.dir = RIGHT;
	if (head.dir == UP)
		head.y--;
	else if (head.dir == LEFT)
		head.x--;
	else if (head.dir == DOWN)
		head.y++;
	else if (head.dir == RIGHT)
		head.x++;
	head.x = (head.x > -1 ? head.x % _width : _width - 1);
	head.y = (head.y > -1 ? head.y % _height : _height - 1);
	_nibbler.push_front(head);

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
