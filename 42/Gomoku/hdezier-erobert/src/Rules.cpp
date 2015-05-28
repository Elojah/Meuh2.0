#include "Rules.hpp"
#include "Board.hpp"

Rules::Rules(void)
{}

Rules::~Rules(void)
{}

#include <iostream>
void		Rules::captureStone(Cell &cell)
{
	char	captures;

	captures = cell.checkCapture();
	std::cout << "Capture:\t" << captures << std::endl;
	if (captures == 0)
		return ;
	for (int i = 0; i < 8; ++i)
	{
		if (captures & (1 << i))
			;
			// cell.setAdjacentsValue(Cell::EMPTY, 2,
			// 	static_cast<Cell::eAdjacent>(i));
	}
}

bool		Rules::makeMove(Board &b,
	Player::vec2 const &move, Cell::eValue const &player)
{
	Cell	&c = b.getCell(move.x, move.y);

	if (c.getValue() != Cell::EMPTY)
		return (false);
	else
	{
		captureStone(c);
		c.setValue(player);
		return (true);
	}
}
