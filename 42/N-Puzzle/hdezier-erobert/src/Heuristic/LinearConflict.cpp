#include "LinearConflict.hpp"
#include "State.hpp"

LinearConflict::LinearConflict(State const *s) {
	_finalState = new State(*s, -1);
	_size = _finalState->getSize();
}

LinearConflict::~LinearConflict(void) {
}

int				LinearConflict::isInLine(std::array<int, MAX_SIZE> line, int n) const {
	unsigned int	i;

	for (i = 0; i < _size; ++i) {
		if (n == line[i]) {
			return (i);
		}
	}
	return (-1);
}

int				LinearConflict::eval(State const *s) const {
	unsigned int	i;
	unsigned int	j;
	unsigned int	y;
	int				foundJ;
	int				foundY;
	int				result(0);
	mapArray		map;
	mapArray		finalMap;

	map = s->getMap();
	finalMap = _finalState->getMap();
	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			if ((foundJ = isInLine(finalMap[i], map[i][j])) >= 0) {
				for (y = 0; y < _size; ++y) {
					if (j != y
						&& (foundY = isInLine(finalMap[i], map[i][y])) >= 0
						&& ((j > y && foundJ < foundY) || (y > j && foundY < foundJ))) {
							result += 2;
					}
				}
			}
		}
	}
	return (result);
}
