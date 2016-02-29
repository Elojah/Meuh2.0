// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Board.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 18:17:27 by hdezier           #+#    #+#             //
//   Updated: 2015/06/10 16:10:39 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Board.hpp"
#include <unistd.h>

int const   Board::_xIndex[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int const	Board::_yIndex[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

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
//	unsigned int	i;
//	unsigned int	j;
//	int				iSize;
	int				setX;
	int				setY;

	_size = size;
//	iSize = static_cast<int>(_size);
	for (int i = 0; i < _size * _size; ++i)
	{
		_cells[i].value = EMPTY;
		_cells[i].isPlayable = false;
		for (int j = 0; j < 8; ++j)
		{
			setX = i % _size + _xIndex[j];
			setY = i / _size + _yIndex[j];
			if (setX >= 0 && setX < _size && setY >= 0 && setY < _size)
				_cells[i].adjacent[j] = &(_cells[setX + setY * _size]);
			else
				_cells[i].adjacent[j] = NULL;
		}
//			_cells[i][j].init(_cells, iSize, i, j);
	}
}
Board::eValue		Board::getValue(int row, int col) const
{
	return (_cells[row + col * _size].value);
}
Board::sCell		&Board::getCell(int row, int col)
{
	return (_cells[row + col * _size]);
}

Board::sCell const	&Board::getCell(int row, int col) const
{
	return (_cells[row + col * _size]);
}
/*
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
*/
void	Board::updateHeuristics(int row, int col)
{
	for (int i = 0; i < 8; ++i)
	{
		setPlayableDirection(&(_cells[row + col * _size]), 3, CAST_DIR(i));
//		_cells[row][col].setPlayableDirection(3, CAST_DIR(i));
	}
}

void	Board::setPlayableDirection(sCell *cell, int dist, eAdjacent dir)
{
	if (!dist)
		return ;
	cell->isPlayable = true;
	if (cell->adjacent[dir] == NULL)
		return ;
	setPlayableDirection(cell->adjacent[dir], dir - 1, dir);
}

int		Board::countAlign(sCell const *cell, eValue value, eAdjacent dir) const
{
	if (cell->value == value)
	{
		if (cell->adjacent[dir] != NULL)
			return (1 + countAlign(cell->adjacent[dir], value, dir));
		else
			return (1);
	}
	return (0);
}

int		Board::countFreeThrees(sCell *cell, eValue value, eAdjacent dir,
							   eValue permissiveValue,
							   int &nPermissive)
{
	int	nextResult;

	if (value == cell->value)
	{
		if (cell->adjacent[dir] != NULL)
			return (1 + countFreeThrees(cell->adjacent[dir], value, dir,
										permissiveValue, nPermissive));
		else
			return (-BOARD_SIZE - 1);
	}
	else if (cell->value == permissiveValue && nPermissive > 0)
	{
		if (cell->adjacent[dir] != NULL)
		{
			--nPermissive;
			nextResult = countFreeThrees(cell->adjacent[dir], value, dir,
										 permissiveValue, nPermissive);
			if (nextResult > 0)
				return (nextResult + 1);
			else
				++nPermissive;
		}
	}
	else if (cell->value == OPPONENT(value))
		return (-BOARD_SIZE - 1);
	return (0);
}

bool		Board::isCapturableDirection(sCell const *cell, eAdjacent dir,
										 eValue value) const
{
	if (value != cell->value)
		return (false);
	else if (isCapturable(cell))
		return (true);
	else if (cell->adjacent[dir] == NULL)
		return (false);
	else
		return (isCapturableDirection(cell->adjacent[dir], dir, value));
}

bool		Board::isCapturable(sCell const *cell) const
{
	sCell const      *nextCell;
	eAdjacent       dir;
	eAdjacent       opposite;

	for (int i = 0; i < 8; ++i)
	{
		dir = CAST_DIR(i);
		opposite = CAST_DIR(OPPOSITE(i));
		if (cell->adjacent[dir] && cell->adjacent[opposite]
			&& cell->adjacent[dir]->value == cell->value)
		{
			nextCell = getNCellDirection(cell->adjacent[dir], 1, dir);
			if (nextCell
				&& ((nextCell->value == OPPONENT(cell->value)
					 && cell->adjacent[opposite]->value == EMPTY)
					|| (nextCell->value == EMPTY
						&& cell->adjacent[opposite]->value
						== OPPONENT(cell->value))))
				return (true);
		}
	}
	return (false);
}

Board::sCell const	*Board::getNCellDirection(sCell const *cell, int n,
											  eAdjacent dir) const
{
	if (!n)
		return (cell);
	else if (cell->adjacent[dir] == NULL)
		return (NULL);
	else
		return (getNCellDirection(cell->adjacent[dir], n - 1, dir));
}

int		Board::checkCapture(sCell const &cell) const
{
	int			result(0);
	sCell const	*nextFriend;

	for (int i = 0; i < 8; ++i)
	{
		if (cell.adjacent[i] != NULL
			&& countAlign(cell.adjacent[i], OPPONENT(cell.value), CAST_DIR(i))
			== 2
			&& (nextFriend = getNCellDirection(&cell, 3, CAST_DIR(i))) != NULL
			&& nextFriend->value == cell.value)
			result |= 1 << i;
	}
	return (result);
}
void	Board::setAdjacentsValue(sCell *cell, eValue e, int n,
								 eAdjacent dir)
{
	if (!n || !cell->adjacent[dir])
		return ;
	cell->adjacent[dir]->value = e;
	setAdjacentsValue(cell->adjacent[dir], e, n - 1, dir);
}
