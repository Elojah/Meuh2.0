#include "MaxSwap.hpp"
#include "State.hpp"

MaxSwap::MaxSwap(State const *s) {
	_finalVec = transformToArray(s);
	_size = s->getSize();
	_size *= _size;
}

MaxSwap::~MaxSwap(void) {
}

std::array<int, MAX_CASE>			MaxSwap::transformToArray(State const *s) {
	unsigned int				i;
	unsigned int				j;
	unsigned int				n(0);
	unsigned int				currentSize;
	mapArray					map;
	std::array<int, MAX_CASE>	result;

	map = s->getMap();
	currentSize = s->getSize();
	for (i = 0; i < currentSize; ++i) {
		for (j = 0; j < currentSize; ++j) {
			result[n++] = map[i][j];
		}
	}
	return(result);
}

int								MaxSwap::eval(State const *s) {
	unsigned int				i;
	unsigned int				j;
	int							tmp;
	int							result(0);
	std::array<int, MAX_CASE>	vec;

	vec = transformToArray(s);
	for (i = 0; i < _size; ++i) {
		if (vec[i] != _finalVec[i]) {
			for (j = 0; j < _size; ++j) {
				if (vec[j] == _finalVec[i]) {
					tmp = vec[i];
					vec[i] = vec[j];
					vec[j] = tmp;
					result++;
					break ;
				}
			}
		}
	}
	return (result);
}
