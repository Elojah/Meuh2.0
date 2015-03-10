#include "State.hpp"
#include <iostream>

State::State(unsigned int size, std::array<int, MAX_CASE> const &map) : _size(size) {
	unsigned int	i;
	unsigned int	j;

	_value = NONE_SET;
	_previous = NULL;
	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			_map[i][j] = map[i * _size + j];
			if (_map[i][j] == EMPTY_VALUE) {
				_empty[0] = i;
				_empty[1] = j;
			}
		}
	}
	_depth = 0;
}

State::State(State const &s, char dir) {
	unsigned int	i;
	unsigned int	j;
	mapArray		map;

	map = s.getMap();
	_size = s.getSize();
	_value = NONE_SET;
	_previous = NULL;
	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			_map[i][j] = map[i][j];
			if (_map[i][j] == EMPTY_VALUE) {
				_empty[0] = i;
				_empty[1] = j;
			}
		}
	}
	_depth = s.getDepth() + 1;
	if (dir >= 0) {
		move(dir);
	}
}

State::~State(void) {
}

void											State::finalFillArray(void) {
	unsigned int	i;
	int				j(-1);
	unsigned int	n(1);

	for (i = 0; i < _size; ++i) {
		_map[i].fill(EMPTY_VALUE);
	}
	i = 0;
	while (n < _size * _size) {
		while (j < static_cast<int>(_size - 1)) {
			if (_map[i][j + 1] != EMPTY_VALUE) {
				break ;
			}
			_map[i][++j] = n++;
		}
		while (i < _size - 1) {
			if (_map[i + 1][j] != EMPTY_VALUE) {
				break ;
			}
			_map[++i][j] = n++;
		}
		while (j > 0) {
			if (_map[i][j - 1] != EMPTY_VALUE) {
				break ;
			}
			_map[i][--j] = n++;
		}
		while (i > 0) {
			if (_map[i - 1][j] != EMPTY_VALUE) {
				break ;
			}
			_map[--i][j] = n++;
		}
	}
	if (_size == 2) {
		_map[1][0] = EMPTY_VALUE;
	}
	for (i = 0; i < _size; ++i) {
		for (n = 0; n < _size; ++n) {
			if (_map[i][n] == EMPTY_VALUE) {
				_empty[0] = i;
				_empty[1] = n;
				return ;
			}
		}
	}
}

/*
**GET/SET
*/
unsigned int											State::getDepth(void) const {return(_depth);}
void													State::setDepth(unsigned int depth) {_depth = depth;}

std::array<std::array<int, MAX_SIZE>, MAX_SIZE>			State::getMap(void) const {return (_map);}

unsigned int											State::getSize(void) const {return (_size);}

State													*State::getPrevious(void) const {return (_previous);}
void													State::setPrevious(State *s) {_previous = s;}

int														State::getValue(void) const {return(_value);}
void													State::setValue(int val) {_value = val;}
std::array<unsigned int, 2>								State::getEmptyPos(void) const {return(std::array<unsigned int, 2>({{_empty[0], _empty[1]}}));}

/*
**NOT SAFE !!!
*/
void											State::move(char const dir)
{
	int				tmp;
	int				inc[2];

	inc[0] = dir < 2 ? 0 : 1;
	inc[1] = dir < 2 ? 1 : 0;
	inc[0] *= dir % 2 ? 1 : -1;
	inc[1] *= dir % 2 ? 1 : -1;
	inc[0] += _empty[0];
	inc[1] += _empty[1];
	tmp = _map[EMPTY];
	_map[EMPTY] = _map[INC];
	_map[INC] = tmp;
	_empty[0] = inc[0];
	_empty[1] = inc[1];
}

std::array<State *, 4>							State::expand(void) {
	std::array<State *, 4>					result;
	unsigned int							current(0);

	if (_empty[1] > 0) {
		result[current++] = new State(*this, LEFT);
	}
	if (_empty[1] < _size - 1) {
		result[current++] = new State(*this, RIGHT);
	}
	if (_empty[0] > 0) {
		result[current++] = new State(*this, UP);
	}
	if (_empty[0] < _size - 1) {
		result[current++] = new State(*this, DOWN);
	}
	result[current] = NULL;
	return (result);
}

bool										State::operator==(State const &s) const {
	unsigned int	i;
	unsigned int	j;
	mapArray		sMap;

	sMap = s.getMap();
	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			if (_map[i][j] != sMap[i][j]) {
				return (false);
			}
		}
	}
	return (true);
}

void									State::display(void) {
	unsigned int	i;
	unsigned int	j;

	std::cout << "_________________________________" << std::endl;
	for (i = 0; i < _size; ++i) {
		std::cout << '|';
		for (j = 0; j < _size; ++j) {
			if (_map[i][j] != 0) {
				std::cout << _map[i][j] << '\t';
			} else {
				std::cout << " \t";
			}
		}
		std::cout << '|' << std::endl;
	}
	std::cout << "_________________________________" << std::endl;
}
