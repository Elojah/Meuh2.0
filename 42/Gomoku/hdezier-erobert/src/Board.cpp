// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Board.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 18:17:27 by hdezier           #+#    #+#             //
//   Updated: 2015/06/01 18:27:56 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Board.hpp"
#include <unistd.h>

Board::Board(void) {}

Board::~Board(void) {}

unsigned int		Board::size(void) const
{
	return (_size);
}

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

void				Board::init(unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				iSize;

	_size = size;
	iSize = static_cast<int>(_size);
	for (i = 0; i < _size; ++i)
	{
		for (j = 0; j < _size; ++j)
			_cells[i][j].init(_cells, iSize, i, j);
	}
}
Cell::eValue const	&Board::getValue(int row, int col) const
{
	return (_cells[row][col].getValue());
}
Cell				&Board::getCell(int row, int col)
{
	return (_cells[row][col]);
}

Cell const			&Board::getCell(int row, int col) const
{
	return (_cells[row][col]);
}

void				Board::display(void) const
{
	// Cell::eValue	v;
	unsigned int	i;
	unsigned int	j;

	for (i = 0; i < _size; ++i)
	{
		for (j = 0; j < _size; ++j)
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
