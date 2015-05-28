#include "Rules.hpp"
#include "Cell.hpp"

Rules::Rules(void)
{}

Rules::~Rules(void)
{}

bool		Rules::makeMove(Board &b
	, Player::vec2 const &move, GameManager::eTurn const &player)
{
	Cell &c = b.getCell(move.x, move.y);

	if (c.getValue() != Cell::EMPTY)
		return (false);
	else
		return (true);
}
