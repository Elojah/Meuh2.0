#include "State.hpp"

State::State(unsigned int size) : _size(size) {
	unsigned int	i;

	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			_map[i][j] = i % _size + j;
		}
	}
}

State::~State(void) {
}

void			State::move(char const dir)
{
	int				tmp;
	int				inc[2];

	inc[0] = dir < 2 ? 0 : 1;
	inc[1] = dir < 2 ? 1 : 0;
	inc[0] *= dir % 2 ? 1 : -1;
	inc[1] *= dir % 2 ? 1 : -1;
	inc[0] += _empty[0];
	inc[1] += _empty[1];
	if (inc[0] >= 0 && inc[0] < static_cast<int>(_size)
		&& inc[1] >= 0 && inc[1] < static_cast<int>(_size)) {
		tmp = _map[EMPTY];
		_map[EMPTY] = _map[INC];
		_map[INC] = tmp;
	}
}
