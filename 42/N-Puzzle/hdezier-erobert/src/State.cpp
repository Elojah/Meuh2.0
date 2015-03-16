
#include "State.hpp"
#include <iostream>

State::State(size_t size, std::array<int, MAX_CASE> const &map):
	_size(size),
	_value(NONE_SET),
	_previous(NULL)
{
	size_t						i;
	size_t						j;

	for (i = 0; i < _size; ++i)
	{
		for (j = 0; j < _size; ++j)
		{
			_map[i][j] = map[i * _size + j];
			if (_map[i][j] == EMPTY_VALUE)
			{
				_empty[0] = i;
				_empty[1] = j;
			}
		}
	}
	_depth = 0;
}
State::State(State const &s, char dir)
{
	size_t						i;
	size_t						j;
	tMapArray					map;

	map = s.getMap();
	_size = s.getSize();
	_value = NONE_SET;
	_previous = NULL;
	for (i = 0; i < _size; ++i)
	{
		for (j = 0; j < _size; ++j)
		{
			_map[i][j] = map[i][j];
			if (_map[i][j] == EMPTY_VALUE)
			{
				_empty[0] = i;
				_empty[1] = j;
			}
		}
	}
	_depth = s.getDepth() + 1;
	if (dir >= 0)
		move(dir);
}
State::~State(void) {}

void							State::finalFillArray(void)
{
	size_t						i;
	int							j;
	size_t						n(1);

	for (i = 0; i < _size; ++i) {
		for (j = 0; j < static_cast<int>(_size); ++j) {
			_map[i][j] = EMPTY_VALUE;
		}
	}
	i = 0;
	j = -1;
	while (n < _size * _size) {
		while (j < static_cast<int>(_size - 1) && _map[i][j + 1] == EMPTY_VALUE)
			_map[i][++j] = n++;
		while (i < _size - 1 && _map[i + 1][j] == EMPTY_VALUE)
			_map[++i][j] = n++;
		while (j > 0 && _map[i][j - 1] == EMPTY_VALUE)
			_map[i][--j] = n++;
		while (i > 0 && _map[i - 1][j] == EMPTY_VALUE)
			_map[--i][j] = n++;
	}
	if (_size % 2 == 0)
		_map[_size / 2][(_size / 2) - 1] = EMPTY_VALUE;
	i = -1;
	while (++i < _size)
	{
		n = -1;
		while (++n < _size)
		{
			if (_map[i][n] == EMPTY_VALUE)
			{
				_empty[0] = i;
				_empty[1] = n;
				return ;
			}
		}
	}
}

size_t							State::getDepth(void) const
{
	return(_depth);
}
void							State::setDepth(unsigned int depth)
{
	_depth = depth;
}
State::tMapArray				State::getMap(void) const
{
	return (_map);
}
size_t							State::getSize(void) const
{
	return (_size);
}
State							*State::getPrevious(void) const
{
	return (_previous);
}
void							State::setPrevious(State *s)
{
	_previous = s;
	_depth = s->getDepth() + 1;
}
int								State::getValue(void) const
{
	return(_value);
}
void							State::setValue(int val)
{
	_value = val;
}
std::array<size_t, 2>			State::getEmptyPos(void) const
{
	return(std::array<size_t, 2>({{_empty[0], _empty[1]}}));
}

void							State::move(char const dir)
{
	int							tmp;
	int							inc[2];

	inc[0] = dir < 2 ? 0 : 1;
	inc[1] = dir < 2 ? 1 : 0;
	inc[0] *= dir % 2 ? 1 : -1;
	inc[1] *= dir % 2 ? 1 : -1;
	inc[0] += _empty[0];
	inc[1] += _empty[1];
	tmp = _map[EMPTY];
	_map[EMPTY] = _map[INC];
	_map[INC] = tmp;
	_empty[0] = inc[0];
	_empty[1] = inc[1];
}

std::array<State *, 5>			State::expand(void)
{
	std::array<State *, 5>		result;
	unsigned int				current(0);

	if (_empty[1] > 0)
		result[current++] = new State(*this, LEFT);
	if (_empty[1] < _size - 1)
		result[current++] = new State(*this, RIGHT);
	if (_empty[0] > 0)
		result[current++] = new State(*this, UP);
	if (_empty[0] < _size - 1)
		result[current++] = new State(*this, DOWN);
	result[current] = NULL;
	return (result);
}

bool							State::operator==(State const &s) const
{
	size_t						i;
	size_t						j;
	tMapArray					sMap(s.getMap());
	std::array<size_t, 2>		sEmptyPos(s.getEmptyPos());

	if (sEmptyPos[0] != _empty[0] || sEmptyPos[1] != _empty[1]) {
		return (false);
	}
	for (i = 0; i < _size; ++i)
	{
		for (j = 0; j < _size; ++j)
		{
			if (_map[i][j] != sMap[i][j]) {
				return (false);
			}
		}
	}
	return (true);
}

void							State::display(void)
{
	size_t						i;
	size_t						j;

	for (i = 0; i < _size; ++i)
		std::cout << "_________";
	std::cout << std::endl;
	for (i = 0; i < _size; ++i)
	{
		std::cout << '|';
		for (j = 0; j < _size; ++j)
		{
			if (_map[i][j] != 0)
				std::cout << _map[i][j] << '\t';
			else
				std::cout << " \t";
		}
		std::cout << '|' << std::endl;
	}
	for (i = 0; i < _size; ++i)
		std::cout << "_________";
	std::cout << std::endl;
}
