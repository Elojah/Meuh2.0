#include "Manhattan.hpp"
#include "State.hpp"

Manhattan::Manhattan(State const *s) {
	_finalState = new State(*s, -1);
	_size = _finalState->getSize();
}

Manhattan::~Manhattan(void) {
}

int				Manhattan::eval(State const *s) {
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;
	unsigned int	y;
	mapArray	map;

	map = s->getMap();
	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			for (x = 0; x < _size; ++x) {
				for (y = 0; y < _size; ++y) {
					;
				}
			}
		}
	}
}
