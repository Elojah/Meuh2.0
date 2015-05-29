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

void	Cell::init(Cell board[BOARD_SIZE][BOARD_SIZE], int const x, int const y)
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

// int			Cell::createFreeThrees(void) const
// {
// 	;
// }

int			Cell::checkCapture(void) const
{
	int		result(0);
	Cell const	*nextFriend;

	for (int i = 0; i < 8; ++i)
	{
		if (_adjacent[i] != NULL
			&& _adjacent[i]->countValueAligned(OPPONENT(_value),
				static_cast<Cell::eAdjacent>(i)) == 2
			&& (nextFriend = getNCellDirection(3, static_cast<Cell::eAdjacent>(i))) != NULL
			&& nextFriend->getValue() == _value)
			result |= 1 << i;
	}
	return (result);
}

Cell const	*Cell::getNCellDirection(int n, Cell::eAdjacent const &dir) const
{
	if (!n)
		return (this);
	else if (_adjacent[dir] == NULL)
		return (NULL);
	else
		return (_adjacent[dir]->getNCellDirection(n - 1, dir));
}

int		Cell::countValueAlignedPermissive(eValue const &value, Cell::eAdjacent const &dir ,
	eValue const &permissiveValue, int nPermissive) const
{
	int		nextAlign;

	if (_value == value || (_value == permissiveValue && nPermissive != 0))
	{
		if (_adjacent[dir] != NULL)
		{
			if (_value != value)
				--nPermissive;
			nextAlign = _adjacent[dir]->countValueAlignedPermissive(value, dir, permissiveValue, nPermissive);
			if (!nextAlign && _value != value)
				return (0);
			else if (_value == value)
				return (1 + nextAlign);
			else
				return (nextAlign);
		}
		else if (_value != value)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

int		Cell::countValueAligned(eValue const &value, Cell::eAdjacent const &dir) const
{
	if (_value == value)
	{
		if (_adjacent[dir] != NULL)
			return (1 + _adjacent[dir]->countValueAligned(value, dir));
		else
			return (1);
	}
	else
		return (0);
}
