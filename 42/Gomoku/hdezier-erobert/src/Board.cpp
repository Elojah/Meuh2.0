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

Board::Board(Board const &rhs)
{
	*this = rhs;
}

Board		&Board::operator=(Board const &rhs)
{
	if (this == &rhs)
	{
		;
	}
	return (*this);
}

const Cell::eValue	&Board::getValue(int row, int col) const
{
	return (_cells[row][col].getValue());
}

Cell		&Board::getCell(int row, int col)
{
	return (_cells[row][col]);
}

const Cell			&Board::getCell(int row, int col) const
{
	return (_cells[row][col]);
}

void	Board::display(void) const
{
	for (unsigned int i = 0; i < BOARD_SIZE; ++i)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; ++j)
		{
			if (_cells[i][j].isPlayable())
				write(1, "O", 1);
			else
				write(1, "_", 1);
			// if (v == Cell::P1)
			// else if (v == Cell::P2)
			// 	write(1, "2", 1);
			// if (v == Cell::EMPTY)
		}
		write(1, "\n", 1);
	}
}

void	Board::updateHeuristics(Player::vec2 const &move)
{
	for (int i = 0; i < 8; ++i)
		_cells[move.x][move.y].setPlayableDirection(3, CAST_DIR(i));
}
