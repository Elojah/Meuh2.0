#include "Rules.hpp"
#include "Board.hpp"

/*NOT SAFE if E_VALUE is different*/
int				Rules::_nbCaptures[Cell::E_VALUE] = {0, 0, 0};

Rules::Rules(void)
{}

Rules::~Rules(void)
{}

int							Rules::win(Cell &cell)
{
	Cell::eValue const		&value(cell.getValue());
	int						result(0);
	int a;
	int b;

	for (int i = 0; i < 4; ++i)
	{
		a = cell.countAlign(value, CAST_DIR(i));
		b = cell.countAlign(value, CAST_DIR(i + 4));
		if (a + b > 5)
			result = result | (1 << i);
	}
	return (result);
}

Rules::eValidity			Rules::captureStone(Cell &cell,
												Cell::eValue player)
{
	int						captures;

	captures = cell.checkCapture();
	if (captures == 0)
		return (OK);
	for (int i = 0; i < 8; ++i)
	{
		if ((captures >> i) & 1)
		{
			cell.setAdjacentsValue(Cell::EMPTY, 2,
				CAST_DIR(i));
			++_nbCaptures[player];
		}
	}
	return (_nbCaptures[player] > 4 ? WIN : OK);
}

bool						Rules::insertDoubleFreethrees(Cell &cell)
{
	int						count(0);
	int						align1;
	int						align2;
	int						nPermissive;
	Cell::eValue			e;

	e = cell.getValue();
	for (int i = 0; i < 4; ++i)
	{
		nPermissive = 1;
		align1 = cell.countFreeThrees(e, CAST_DIR(i),
			Cell::EMPTY, nPermissive) - 1;
		align2 = cell.countFreeThrees(e, CAST_DIR(i + 4)
			, Cell::EMPTY, nPermissive) - 1;
		if ((align1 + align2 > 1 && nPermissive > 0)
			|| (align1 + align2 > 2 && nPermissive == 0))
			++count;
	}
	return (count > 1);
}

bool						Rules::canCaptureLast(Board const &b,
													Cell &cell)
{
	Cell const				*c;
	Cell::eValue			opponent;
	unsigned int			i;
	unsigned int			j;

	opponent = cell.getValue();
	if (_nbCaptures[OPPONENT(opponent)] != 4)
		return (false);
	for (i = 0; i < b.size(); ++i)
	{
		for (j = 0; j < b.size(); ++j)
		{
			if (b.getValue(i, j) == opponent
				&& (c = &(b.getCell(i, j)))->isCapturable())
			{
				// _winP1 = &c;
				return (true);
			}
		}
	}
	return (false);
}

bool						Rules::canCaptureFive(Cell const &cell, int dirWin)
{
	Cell::eValue			e;
	bool					result;

	e = cell.getValue();
	for (int i = 0; i < 4; ++i)
	{
		if (!((dirWin >> i) & 1))
			continue ;
		else if (cell.isCapturableDirection(CAST_DIR(i), e)
			|| cell.isCapturableDirection(CAST_DIR(OPPOSITE(i)), e))
		{
			// _winP1 = &c;
			result = true;
		}
		else
			return (false);
	}
	return (result);
}

Rules::eValidity			Rules::simulateMove(Board &b, Player::vec2 const &move,
											Cell::eValue player)
{
	Rules::eValidity		result;
	Cell					&c(b.getCell(move.x, move.y));
	int						dirWin;

	if (c.getValue() != Cell::EMPTY)
		return (INVALID);
	else
	{
		c.setValue(player);
		if (Rules::insertDoubleFreethrees(c))
			result = INVALID;
		else
		{
			if ((dirWin = Rules::win(c))
				&& !Rules::canCaptureLast(b, c)
				&& !Rules::canCaptureFive(c, dirWin))
				result = WIN;
			result = Rules::captureStone(c, player);
			b.updateHeuristics(move);
		}
		c.setValue(Cell::EMPTY);
		return (result);
	}
}

Rules::eValidity			Rules::makeMove(Board &b, Player::vec2 const &move,
											Cell::eValue player)
{
	Rules::eValidity		result;
	Cell					&c(b.getCell(move.x, move.y));
	int						dirWin;

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
		else if ((dirWin = Rules::win(c))
			&& !Rules::canCaptureLast(b, c)
			&& !Rules::canCaptureFive(c, dirWin))
			result = WIN;
		else
			result = Rules::captureStone(c, player);
		if (result != INVALID)
			b.updateHeuristics(move);
		// if (_winP1 != NULL
		// 	&& _nbCaptures[player] < 5
		// 	&& Rules::win(_winP1) != 0)
		// 	result = LOOSE;
		return (result);
	}
}
