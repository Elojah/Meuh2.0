#include "Cell.hpp"
#include "Board.hpp"
#include <cstddef>

const int	Cell::_xIndex[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int	Cell::_yIndex[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

Cell::Cell(void)
{}

Cell::~Cell(void)
{}

const Cell::eValue	&Cell::getValue(void) const
{
	return (_value);
}

void	Cell::setValue(Cell::eValue const &e)
{
	_value = e;
}

void	Cell::setAdjacentsValue(Cell::eValue const &e, int n,
								Cell::eAdjacent const &dir)
{
	if (!n || !_adjacent[dir])
		return ;
	_adjacent[dir]->setValue(e);
	_adjacent[dir]->setAdjacentsValue(e, n - 1, dir);
}

void	Cell::init(Cell **board, int const x, int const y)
{
	int					setX;
	int					setY;

	_value = EMPTY;
	for (int i = 0; i < 8; ++i)
	{
		setX = x + _xIndex[i];
		setY = y + _yIndex[i];
		if (setX >= 0 && setX < BOARD_SIZE
			&& setY >= 0 && setY < BOARD_SIZE)
			_adjacent[i] = &(board[setX][setY]);
		else
			_adjacent[i] = NULL;
	}
}

char		Cell::checkCapture(void) const
{
	char		result(0);
	Cell const	*nextFriend;

	for (int i = 0; i < 8; ++i)
	{
		if (_adjacent[i]
			&& _adjacent[i]->countValueAligned(OPPONENT(_value),
				static_cast<Cell::eAdjacent>(i)) == 2
			&& (nextFriend = getNCellDirection(3, static_cast<Cell::eAdjacent>(i)))
			&& nextFriend->getValue() == _value)
			result = result & (1 << i);
	}
	return (result);
}

Cell const	*Cell::getNCellDirection(int n, Cell::eAdjacent const &dir) const
{
	if (!n)
		return (this);
	else if (!_adjacent[dir])
		return (NULL);
	else
		return (_adjacent[dir]->getNCellDirection(n - 1, dir));
}

int		Cell::countValueAligned(eValue const &value, Cell::eAdjacent const &dir)
{
	if (_value == value)
	{
		if (_adjacent[dir])
			return (1 + _adjacent[dir]->countValueAligned(value, dir));
		else
			return (1);
	}
	else
		return (0);
}
