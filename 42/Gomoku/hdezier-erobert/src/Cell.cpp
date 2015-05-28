#include "Cell.hpp"
#include "Board.hpp"
#include <cstddef>

Cell::Cell(void)
{}

Cell::~Cell(void)
{}

const Cell::eValue	&Cell::getValue(void) const
{
	return (_value);
}

void	Cell::init(Cell const **board, int const x, int const y)
{
	static const int	xIndex[] = {0, 1, 1, 1, 0, -1, -1, -1};
	static const int	yIndex[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int					setX;
	int					setY;

	_value = EMPTY;
	for (int i = 0; i < 8; ++i)
	{
		setX = x + xIndex[i];
		setY = y + yIndex[i];
		if (setX >= 0 && setX < BOARD_SIZE
			&& setY >= 0 && setY < BOARD_SIZE)
			_adjacent[i] = &(board[setX][setY]);
		else
			_adjacent[i] = NULL;
	}
}

bool	Cell::checkCapture(void) const
{
	for (int i = 0; i < 8; ++i)
	{
		;
	}
	return (false);
}
