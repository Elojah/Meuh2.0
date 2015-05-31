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

Rules::eValidity	Rules::captureStone(Cell &cell, Cell::eValue player)
{
	static int			nbCaptures[Cell::E_VALUE];
	int					captures;

	captures = cell.checkCapture();
	if (captures == 0)
		return (OK);
	for (int i = 0; i < 8; ++i)
	{
		if ((captures >> i) & 1)
		{
			cell.setAdjacentsValue(Cell::EMPTY, 2,
				static_cast<Cell::eAdjacent>(i));
			++nbCaptures[player];
		}
	}
	return (nbCaptures[player] > 4 ? WIN : OK);
}

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
			Cell::EMPTY, nPermissive) - 1;
		align2 = cell.countFreeThrees(e, static_cast<Cell::eAdjacent>(i + 4)
			, Cell::EMPTY, nPermissive) - 1;
		if ((align1 + align2 > 1 && nPermissive > 0)
			|| (align1 + align2 > 2 && nPermissive == 0))
			++count;
	}
	return (count > 1);
}

bool						Rules::ensureWin(void)
{
	return (false);
}

Rules::eValidity			Rules::makeMove(Board &b,
	Player::vec2 const &move, Cell::eValue player)
{
	Rules::eValidity	result;
	Cell				&c = b.getCell(move.x, move.y);

	if (c.getValue() != Cell::EMPTY)
		return (INVALID);
	else
	{
		c.setValue(player);

		if (Rules::insertDoubleFreethrees(c))
		{
			result = INVALID;
			c.setValue(Cell::EMPTY);
		}
		else if (Rules::win(c) && !Rules::ensureWin())
			result = WIN;
		else
			result = Rules::captureStone(c, player);
		return (result);
	}
}
