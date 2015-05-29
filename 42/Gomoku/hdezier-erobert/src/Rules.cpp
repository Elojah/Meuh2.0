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
		if (cell.countValueAligned(value, static_cast<Cell::eAdjacent>(i))
			+ cell.countValueAligned(value, static_cast<Cell::eAdjacent>(i + 4)) > 5)
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

bool	Rules::insertDoubleFreethrees(Cell &cell)
{
	int	count(0);

	for (int i = 0; i < 4; ++i)
	{
		if (cell.countValueAlignedPermissive(cell.getValue()
			, static_cast<Cell::eAdjacent>(i), Cell::EMPTY, 1)
			+ cell.countValueAlignedPermissive(cell.getValue()
			, static_cast<Cell::eAdjacent>(i + 4), Cell::EMPTY, 1) > 3)
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
		{
			c.setValue(Cell::EMPTY);
			result = INVALID;
		}
		else if (Rules::win(c))
			result = WIN;
		else
			result = OK;
		if (result != INVALID)
			Rules::captureStone(c);
		return (result);
	}
}
