#include "State.hpp"
#include <iostream>
#include <algorithm>

State::State(size_t size, std::array<int, MAX_CASE> const &map):
	_size(size),
	_value(NONE_SET),
	_previous(NULL)
{
	size_t						i;

	for (i = 0; i < _size * _size; ++i)
	{
		_map[i] = map[i];
		if (_map[i] == EMPTY_VALUE)
			_empty = i;
	}
	_depth = 0;
}
State::State(State const &s, char dir)
{
	size_t						i;
	tArray						map;

	map = s.getMap();
	_value = NONE_SET;
	_size = s.getSize();
	_empty = s.getEmptyPos();
	_depth = s.getDepth() + 1;
	_previous = NULL;
	for (i = 0; i < _size * _size; ++i)
		_map[i] = map[i];
	if (dir >= 0)
		move(dir);
}
State::~State(void) {}

/*TODO*/
void							State::finalFillArray(void)
{
	size_t		i;
	int			j(-1);
	size_t		n(1);

	for (i = 0; i < _size * _size; ++i)
			_map[i] = EMPTY_VALUE;
	i = 0;
	while (n < _size * _size)
	{
			while (j < static_cast<int>(_size - 1) && _map[i * _size + j + 1] == EMPTY_VALUE)
					_map[i * _size + ++j] = n++;
			while (i < _size - 1 && _map[(i + 1) * _size + j] == EMPTY_VALUE)
					_map[++i * _size + j] = n++;
			while (j > 0 && _map[i * _size + j - 1] == EMPTY_VALUE)
					_map[i * _size + --j] = n++;
			while (i > 0 && _map[(i - 1) * _size + j] == EMPTY_VALUE)
					_map[--i * _size + j] = n++;
	}
	if (_size % 2 == 0)
			_map[_size / 2 * _size + _size / 2 - 1] = EMPTY_VALUE;
	i = -1;
	while (++i < _size * _size)
	{
		{
			if (_map[i] == EMPTY_VALUE)
			{
				_empty = i;
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
State::tArray					State::getMap(void) const
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
size_t							State::getEmptyPos(void) const
{
	return (_empty);
}

void							State::move(char const dir)
{
	int							tmp(0);
	int							inc(0);

	inc = dir < 2 ? 1 : _size;
	inc *= dir % 2 ? 1 : -1;
	tmp = _map[_empty];
	_map[_empty] = _map[_empty + inc];
	_map[_empty + inc] = tmp;
	_empty += inc;
}

std::array<State *, 5>			State::expand(void)
{
	std::array<State *, 5>		result;
	unsigned int				current(0);

	if (_empty % _size > 0)
		result[current++] = new State(*this, LEFT);
	if (_empty % _size < _size - 1)
		result[current++] = new State(*this, RIGHT);
	if (_empty /_size > 0)
		result[current++] = new State(*this, UP);
	if (_empty / _size < _size - 1)
		result[current++] = new State(*this, DOWN);
	result[current] = NULL;
	return (result);
}

bool							State::operator==(State const &s) const
{
	size_t	i;
	size_t	sEmptyPos(s.getEmptyPos());
	int64_t	*a;
	int64_t	*b;

	if (sEmptyPos != _empty) {
		return (false);
	}
	a = reinterpret_cast<int64_t *>(s.getMap().data());
	b = reinterpret_cast<int64_t *>(getMap().data());
	for (i = 0; i < (_size * _size); ++i)
	{
		if (a[i] != b[i]) {
			return (false);
		}
	}
	return (s.getMap()[_size * _size - 1] == _map[_size * _size - 1]);
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
			if (_map[i * _size + j] != EMPTY_VALUE)
				std::cout << _map[i * _size + j] << '\t';
			else
				std::cout << " \t";
		}
		std::cout << '|' << std::endl;
	}
	for (i = 0; i < _size; ++i)
		std::cout << "_________";
	std::cout << std::endl;
}
