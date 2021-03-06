#include "Cell.hpp"
#include "Board.hpp"
#include <cstddef>

const int	Cell::_xIndex[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int	Cell::_yIndex[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

Cell::Cell(void):
	_isPlayable(false)
{}

Cell::~Cell(void)
{}

const Cell::eValue	&Cell::getValue(void) const
{
	return (_value);
}

void				Cell::setValue(Cell::eValue const &e)
{
	_value = e;
}

bool				Cell::isPlayable(void) const
{
	return (_isPlayable);
}

void	Cell::setPlayableDirection(int dist, Cell::eAdjacent const &dir)
{
	if (!dist)
		return ;
	_isPlayable = true;
	if (_adjacent[dir] == NULL)
		return;
	_adjacent[dir]->setPlayableDirection(dist - 1, dir);
}

void	Cell::setAdjacentsValue(Cell::eValue const &e, int n,
								Cell::eAdjacent const &dir)
{
	if (!n || !_adjacent[dir])
		return ;
	_adjacent[dir]->setValue(e);
	_adjacent[dir]->setAdjacentsValue(e, n - 1, dir);
}

void	Cell::init(Cell board[BOARD_SIZE][BOARD_SIZE], int size
	, int const x, int const y)
{
	int					setX;
	int					setY;

	_value = EMPTY;
	for (int i = 0; i < 8; ++i)
	{
		setX = x + _xIndex[i];
		setY = y + _yIndex[i];
		if (setX >= 0 && setX < size
			&& setY >= 0 && setY < size)
			_adjacent[i] = &(board[setX][setY]);
		else
			_adjacent[i] = NULL;
	}
}

bool		Cell::isCapturable(void) const
{
	Cell const	*nextCell;
	eAdjacent	dir;
	eAdjacent	opposite;

	for (int i = 0; i < 8; ++i)
	{
		dir = CAST_DIR(i);
		opposite = CAST_DIR(OPPOSITE(i));
		if (_adjacent[dir] && _adjacent[opposite]
			&& _adjacent[dir]->getValue() == _value)
		{
			nextCell = _adjacent[dir]->getNCellDirection(1, dir);
			if (nextCell
				&& ((nextCell->getValue() == OPPONENT(_value)
					&& _adjacent[opposite]->getValue() == Cell::EMPTY)
				|| (nextCell->getValue() == Cell::EMPTY
					&& _adjacent[opposite]->getValue() == OPPONENT(_value))))
				return (true);
		}
	}
	return (false);
}

bool		Cell::isCapturableDirection(Cell::eAdjacent dir, Cell::eValue const &value) const
{
	if (value != _value)
		return (false);
	else if (isCapturable())
		return (true);
	else if (_adjacent[dir] == NULL)
		return (false);
	else
		return (_adjacent[dir]->isCapturableDirection(dir, value));
}

int			Cell::checkCapture(void) const
{
	int		result(0);
	Cell const	*nextFriend;

	for (int i = 0; i < 8; ++i)
	{
		if (_adjacent[i] != NULL
			&& _adjacent[i]->countAlign(OPPONENT(_value), CAST_DIR(i)) == 2
			&& (nextFriend = getNCellDirection(3, CAST_DIR(i))) != NULL
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

int		Cell::countFreeThrees(eValue const &value, Cell::eAdjacent const &dir,
								eValue const &permissiveValue, int &nPermissive)
{
	int		nextResult;

	if (value == _value)
	{
		if (_adjacent[dir] != NULL)
			return (1 + _adjacent[dir]->countFreeThrees(value, dir,
									permissiveValue, nPermissive));
		else
			return (-BOARD_SIZE - 1);
	}
	else if (_value == permissiveValue && nPermissive > 0)
	{
		if (_adjacent[dir] != NULL)
		{
			--nPermissive;
			nextResult = _adjacent[dir]->countFreeThrees(value, dir,
									permissiveValue, nPermissive);
			if (nextResult > 0)
				return (nextResult + 1);
			else
				++nPermissive;
		}
	}
	else if (_value == OPPONENT(value))
		return (-BOARD_SIZE - 1);
	return (0);
}

int		Cell::countAlign(eValue const &value, Cell::eAdjacent const &dir) const
{
	if (_value == value)
	{
		if (_adjacent[dir] != NULL)
			return (1 + _adjacent[dir]->countAlign(value, dir));
		else
			return (1);
	}
	return (0);
}

Cell	*Cell::operator[](Cell::eAdjacent const &e)
{
	return (_adjacent[e]);
}
