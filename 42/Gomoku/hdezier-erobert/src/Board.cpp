#include "Board.hpp"
#include <unistd.h>

Board::Board(void)
{
	for (unsigned int i = 0; i < BOARD_SIZE; ++i)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; ++j)
			_cells[i][j].init(_cells, i, j);
	}
}

Board::~Board(void)
{}

const Cell::eValue	&Board::getValue(int row, int col) const
{
	return (_cells[row][col].getValue());
}

Cell		&Board::getCell(int row, int col)
{
	return (_cells[row][col]);
}

const Cell		&Board::getCell(int row, int col) const
{
	return (_cells[row][col]);
}

void	Board::display(void) const
{
	Cell::eValue	v;

	for (unsigned int i = 0; i < BOARD_SIZE; ++i)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; ++j)
		{
			v = _cells[i][j].getValue();
			if (v == Cell::P1)
				write(1, "1", 1);
			else if (v == Cell::P2)
				write(1, "2", 1);
			if (v == Cell::EMPTY)
				write(1, "_", 1);
		}
		write(1, "\n", 1);
	}
}
