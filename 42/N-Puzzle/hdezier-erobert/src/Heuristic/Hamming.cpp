#include "Hamming.hpp"
#include "State.hpp"

Hamming::Hamming(State const *s) {
	_finalState = new State(*s, -1);
	_size = _finalState->getSize();
}

Hamming::~Hamming(void) {
}

int				Hamming::eval(State const *s) {
	unsigned int	i;
	unsigned int	j;
	mapArray		map;
	mapArray		finalMap;
	int				result(0);

	map = s->getMap();
	finalMap = _finalState->getMap();
	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			if (map[i][j] != finalMap[i][j]) {
				result++;
			}
		}
	}
	return (result);
}
