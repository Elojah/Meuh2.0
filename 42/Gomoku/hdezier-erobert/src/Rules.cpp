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

Rules::eValidity			Rules::makeMove(Board &b,
	Player::vec2 const &move, Cell::eValue const &player)
{
	Cell	&c = b.getCell(move.x, move.y);

	if (c.getValue() != Cell::EMPTY)
		return (INVALID);
	else
	{
		c.setValue(player);
		Rules::captureStone(c);
		return (Rules::win(c) ? WIN : OK);
	}
}
