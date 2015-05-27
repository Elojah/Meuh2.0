#include "Cell.hpp"

Cell::Cell(void)
{}

Cell::~Cell(void)
{}

void	Cell::init(sCell const **board, int const x, int const y)
{
	static const int	xIndex[] = {0, 1, 1, 1, 0, -1, -1, -1};
	static const int	yIndex[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int					setX;
	int					setY;

	value = EMPTY;
	for (int i = 0; i < 8; ++i)
	{
		setX = x + xIndex[i];
		if (setX >= 0 && setX < SIZE_BOARD
			&& setY >= 0 && setY < SIZE_BOARD)
			adjacent = &(board[setX][setY]);
		else
			adjacent = NULL;
	}
}
