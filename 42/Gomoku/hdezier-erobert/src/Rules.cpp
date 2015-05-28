#include "Rules.hpp"
#include "Board.hpp"

Rules::Rules(void)
{}

Rules::~Rules(void)
{}

bool		Rules::makeMove(Board &b,
	Player::vec2 const &move, Cell::eValue const &player)
{
	Cell	&c = b.getCell(move.x, move.y);

	if (c.getValue() != Cell::EMPTY)
		return (false);
	else
	{
		c.setValue(player);
		return (true);
	}
}
