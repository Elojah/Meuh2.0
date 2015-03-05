#include "Puzzle.hpp"

Puzzle::Puzzle(void) {
}

Puzzle::Puzzle(std::istream &is) {
	(void)is;
}

Puzzle::~Puzzle(void) {
}

void			Puzzle::parse(std::istream &is) {
	(void)is;
}

void			Puzzle::move(char dir) {
	tCase			tmp;
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

void			Puzzle::resolve(void) {
	;
}

