#include "LinearConflict.hpp"

LinearConflict::LinearConflict(State const *s) {
	_finalState = new State(*s, -1);
	_size = _finalState->getSize();
}

LinearConflict::~LinearConflict(void) {
}

int				LinearConflict::eval(State const *s) {
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;
	unsigned int	y;
	mapArray		map;
	mapArray		finalMap;
	int				result(0);

	map = s->getMap();
	finalMap = _finalState->getMap();
	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {

			for (y = 0; y < _size; ++y) {
				if (map[i][j] == finalMap[i][y]) {
				}
			}

		}
	}
	return (result);
}
