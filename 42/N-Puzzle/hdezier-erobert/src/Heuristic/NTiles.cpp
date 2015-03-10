#include "NTiles.hpp"
#include "State.hpp"

NTiles::NTiles(State const *s) {
	_finalState = new State(*s, -1);
	_size = _finalState->getSize();
}

NTiles::~NTiles(void) {
}

int				NTiles::eval(State const *s) const {
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;
	unsigned int	y;
	int				result(0);
	mapArray		map;
	mapArray		finalMap;

	map = s->getMap();
	finalMap = _finalState->getMap();
	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			result += 2;
			for (x = 0; x < _size; ++x) {
				if (finalMap[x][j] == map[i][j]) {
					result--;
				}
			}
			for (y = 0; y < _size; ++y) {
				if (finalMap[i][y] == map[i][j]) {
					result--;
				}
			}
		}
	}
	return (result);
}
