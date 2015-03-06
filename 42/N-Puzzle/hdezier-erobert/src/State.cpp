#include "State.hpp"
#include <iostream>

State::State(unsigned int size, std::array<int, MAX_CASE> const &map) : _size(size) {
	unsigned int	i;
	unsigned int	j;

	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			_map[i][j] = map[i * _size + j];
			if (_map[i][j] == EMPTY_VALUE) {
				_empty[0] = i;
				_empty[1] = j;
			}
		}
	}
}

State::State(State const &s, char dir) {
	unsigned int	i;
	unsigned int	j;
	mapArray		map;

	map = s.getMap();
	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			_map[i][j] = map[i][j];
			if (_map[i][j] == EMPTY_VALUE) {
				_empty[0] = i;
				_empty[1] = j;
			}
		}
	}
	move(dir);
}

State::~State(void) {
}

void											State::finalFillArray(void) {
	unsigned int	i;
	unsigned int	j;

	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			_map[i][j] = (i * _size) + j + 1;
		}
	}
	_map[_size - 1][_size - 1] = 0;
	_empty[0] = _size - 1;
	_empty[1] = _size - 1;
}

std::array<std::array<int, MAX_SIZE>, MAX_SIZE>	State::getMap(void) const {
	return (_map);
}

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

	if (_empty[0] > 0) {
		result[current++] = new State(*this, LEFT);
	}
	if (_empty[0] < _size - 1) {
		result[current++] = new State(*this, RIGHT);
	}
	if (_empty[1] > 0) {
		result[current++] = new State(*this, DOWN);
	}
	if (_empty[1] < _size - 1) {
		result[current++] = new State(*this, UP);
	}
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

	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			std::cout << _map[i][j] << '\t';
		}
		std::cout << '\n';
	}
}
