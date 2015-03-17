#include "NTiles.hpp"
#include "State.hpp"

NTiles::NTiles(State const *s) {
	_size = s->getSize();
	_finalMap = s->getMap();
}

NTiles::~NTiles(void) {
}

int				NTiles::eval(State const *s) const {
	size_t			i;
	size_t			x;
	int				result(0);
	tArray			map;

	map = s->getMap();
	for (i = 0; i < _size * _size; ++i) {
		result += 2;
		for (x = 0; x < _size; ++x) {
			if (_finalMap[i / _size + x] == map[i]) {
				result--;
				break ;
			}
		}
		for (x = 0; x < _size; ++x) {
			if (_finalMap[x * _size + i % _size] == map[i]) {
				result--;
				break ;
			}
		}
	}
	return (result);
}
