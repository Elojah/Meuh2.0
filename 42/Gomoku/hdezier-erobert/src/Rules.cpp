#include "Rules.hpp"
#include "Board.hpp"

Rules::Rules(void)
{}

Rules::~Rules(void)
{}

bool		Rules::win(Cell &cell)
{
	const Cell::eValue	&value = cell.getValue();

	for (int i = 0; i < 4; ++i)
	{
		if (cell.countAlign(value, static_cast<Cell::eAdjacent>(i))
			+ cell.countAlign(value, static_cast<Cell::eAdjacent>(i + 4)) > 5)
			return (true);
	}
	return (false);
}

void		Rules::captureStone(Cell &cell)
{
	int		captures;

	captures = cell.checkCapture();
	if (captures == 0)
		return ;
	for (int i = 0; i < 8; ++i)
	{
		if ((captures >> i) & 1)
			cell.setAdjacentsValue(Cell::EMPTY, 2,
				static_cast<Cell::eAdjacent>(i));
	}
}

// #include <iostream>
bool	Rules::insertDoubleFreethrees(Cell &cell)
{
	int				count(0);
	int				align1;
	int				align2;
	int				nPermissive;
	Cell::eValue	e;

	e = cell.getValue();
	for (int i = 0; i < 4; ++i)
	{
		nPermissive = 1;
		align1 = cell.countFreeThrees(e, static_cast<Cell::eAdjacent>(i),
			Cell::EMPTY, nPermissive);
		// std::cout << "nPermissive:\t" << nPermissive << std::endl;
		align2 = cell.countFreeThrees(e, static_cast<Cell::eAdjacent>(i + 4)
			, Cell::EMPTY, nPermissive);
		// std::cout << "Alignments in " << i << ":\t" << align1 << "\t" << align2 << std::endl;
		if (align1 + align2 > 3
			&& cell.getNCellDirection(align1, static_cast<Cell::eAdjacent>(i))->getValue() == Cell::EMPTY
			&& cell.getNCellDirection(align2, static_cast<Cell::eAdjacent>(i + 4))->getValue() == Cell::EMPTY)
			++count;
	}
	return (count > 1);
}

Rules::eValidity			Rules::makeMove(Board &b,
	Player::vec2 const &move, Cell::eValue const &player)
{
	Rules::eValidity	result;
	Cell				&c = b.getCell(move.x, move.y);

	if (c.getValue() != Cell::EMPTY)
		return (INVALID);
	else
	{
		c.setValue(player);
		if (Rules::insertDoubleFreethrees(c))
			result = INVALID;
		else if (Rules::win(c))
			result = WIN;
		else
			result = OK;
		if (result == INVALID)
			c.setValue(Cell::EMPTY);
		else
			Rules::captureStone(c);
		return (result);
	}
}
