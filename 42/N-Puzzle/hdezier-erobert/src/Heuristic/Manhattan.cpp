#include "Manhattan.hpp"
#include "State.hpp"
#include <iostream>

Manhattan::Manhattan(State const &s) {
	_size = s.getSize();
	_finalMap = s.getMap();
}

Manhattan::~Manhattan(void) {
}

int				Manhattan::eval(State const &s) const {
	size_t			i;
	size_t			x;
	bool			modCheck;
	int				result(0);
	tArray			map;

	map = s.getMap();
	for (i = 0; i < _size * _size; ++i) {
		for (x = 0; x < _size * _size; ++x) {
			if (map[i] == _finalMap[x]) {
				modCheck = i % _size > x % _size;
				result += (((i > x) ?
					i / _size - x / _size + (modCheck ? i % _size - x % _size : x % _size - i % _size)
					: x / _size - i / _size + (modCheck ? i % _size - x % _size : x % _size - i % _size)));
				break ;
			}
		}
	}
	return (result);
}
