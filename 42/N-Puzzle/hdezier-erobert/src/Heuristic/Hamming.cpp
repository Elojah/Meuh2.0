#include "Hamming.hpp"
#include "State.hpp"

Hamming::Hamming(State const &s)
{
	_size = s.getSize();
	_finalMap = s.getMap();
}
Hamming::~Hamming(void) {}

int			Hamming::eval(State const &s) const
{
	size_t	i;
	int		result(0);

	for (i = 0; i < _size * _size; ++i)
	{
		if (s.getMap()[i] != _finalMap[i])
			result++;
	}
	return (result);
}
