// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Rules.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/05 17:25:46 by hdezier           #+#    #+#             //
//   Updated: 2015/06/29 18:20:58 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Rules.hpp"
#include "Board.hpp"

Board::sCell const			*Rules::_winMove[Cell::E_VALUE];

void						Rules::reset(void)
{
	int						i(-1);

	while (++i < Cell::E_VALUE)
		_winMove[i] = NULL;
}


Rules::eValidity			Rules::captureStone(Cell &cell, Player &player)
{
	int						captures(cell.checkCapture());
	int						i;

	if (captures == 0)
		return (OK);
	for (i = 0; i < 8; ++i)
	{
		if ((captures >> i) & 1)
		{
			cell.setAdjacentsValue(Cell::EMPTY, 2, CAST_DIR(i));
			player.addCapture(1);
		}
	}
	return (OK);
}

int							Rules::simulateMove(Board &b, Player &p1, Player &p2)
{
	Player					&player(p1.attribute().turn ? p1 : p2);
	Player					&opponent(p1.attribute().turn ? p2 : p1);
	Cell::eValue			pValue(p1.attribute().turn ? Cell::P1 : Cell::P2);
	Rules::eValidity		result(INVALID);
	Cell					&c(b.getCell(player.attribute().x,
										 player.attribute().y));
	int						dirWin;

	if (c.getValue() != Cell::EMPTY)
		return (0);
	else
	{
		c.setValue(pValue);
		if (Rules::insertDoubleFreethrees(c))
		{
			c.setValue(Cell::EMPTY);
			return (0);
		}
		result = Rules::simulateStone(c, player);
		if ((dirWin = Rules::win(c))
			&& !Rules::canCaptureLast(b, c, opponent)
			&& !Rules::canCaptureFive(c, dirWin))
		{
			player.switchWin();
			result = WIN;
		}
		b.updateHeuristics(player.attribute().x, player.attribute().y);
		if (_winMove[OPPONENT(pValue)] != NULL
			&& player.attribute().captured < 5
			&& Rules::win(*_winMove[OPPONENT(pValue)]) != 0)
		{
			if (player.attribute().win)
				player.switchWin();
			opponent.switchWin();
			result = LOOSE;
		}
		else
			_winMove[OPPONENT(pValue)] = NULL;
		return (result);
	}
}

Rules::eValidity			Rules::makeMove(Board &b, Player &p1, Player &p2)
{
	Player					&player(p1.attribute().turn ? p1 : p2);
	Player					&opponent(p1.attribute().turn ? p2 : p1);
	Board::eValue			pValue(p1.attribute().turn ? Board::P1 : Board::P2);
	Rules::eValidity		result(INVALID);
	Board::sCell			&c(b.getCell(player.attribute().x,
										 player.attribute().y));
	int						dirWin;

	if (c.value != Board::EMPTY)
		return (INVALID);
	else
	{
		c.value = pValue;
		if (Rules::insertDoubleFreethrees(b, c))
		{
			c.value = Board::EMPTY;
			return (result);
		}
		result = Rules::captureStone(b, c, player);
		if ((dirWin = Rules::win(b, c))
			&& !Rules::canCaptureLast(b, c, opponent)
			&& !Rules::canCaptureFive(b, c, dirWin))
		{
			player.switchWin();
			result = WIN;
		}
		b.updateHeuristics(player.attribute().x, player.attribute().y);
		if (_winMove[OPPONENT(pValue)] != NULL
			&& player.attribute().captured < 5
			&& Rules::win(b, *_winMove[OPPONENT(pValue)]) != 0)
		{
			if (player.attribute().win)
				player.switchWin();
			opponent.switchWin();
			result = LOOSE;
		}
		else
			_winMove[OPPONENT(pValue)] = NULL;
		return (result);
	}
}

int							Rules::win(Board const &b,
													 Board::sCell const &cell)
{
//	Board::eValue const		&value(cell.value);
	int						result(0);
	int						align1;
	int						align2;

	if (cell.value == Board::EMPTY)
		return (result);
	for (int i = 0; i < 4; ++i)
	{
		align1 = b.countAlign(&cell, cell.value, CAST_DIR(i));
		align2 = b.countAlign(&cell, cell.value, CAST_DIR(i + 4));
		if (align1 + align2 > 5)
			result = result | (1 << i);
	}
	return (result);
}
bool						Rules::insertDoubleFreethrees(Board &b,
																							Board::sCell &cell)
{
//	Cell::eValue			value(cell.getValue());
	int						count(0);
	int						align1;
	int						align2;
	int						nPermissive;
	int						i;

	for (i = 0; i < 4; ++i)
	{
		nPermissive = 1;
		align1 = b.countFreeThrees(&cell, cell.value, CAST_DIR(i),
								   Board::EMPTY, nPermissive) - 1;
		align2 = b.countFreeThrees(&cell, cell.value, CAST_DIR(i + 4),
								   Board::EMPTY, nPermissive) - 1;
		if ((align1 + align2 > 1 && nPermissive > 0)
			|| (align1 + align2 > 2 && nPermissive == 0))
			++count;
	}
	return (count > 1);
}

bool						Rules::canCaptureFive(Board &b,
																			Board::sCell const &cell,
																			int dirWin)
{
//	Cell::eValue			value(cell.getValue());
	bool					result(false);
	int						i;

	for (i = 0; i < 4; ++i)
	{
		if (!((dirWin >> i) & 1))
			continue ;
		else if (b.isCapturableDirection(&cell, CAST_DIR(i), cell.value)
				 || b.isCapturableDirection(&cell, CAST_DIR(OPPOSITE(i)),
											cell.value))
		{
			_winMove[cell.value] = &cell;
			result = true;
		}
		else
			return (false);
	}
	return (result);
}

Rules::eValidity			Rules::captureStone(Board &b, Board::sCell &cell,
																					Player &player)
{
	int						captures(b.checkCapture(cell));
	int						i;

	if (captures == 0)
		return (OK);
	for (i = 0; i < 8; ++i)
	{
		if ((captures >> i) & 1)
		{
			b.setAdjacentsValue(&cell, Board::EMPTY, 2, CAST_DIR(i));
			player.addCapture(1);
		}
	}
	if (player.attribute().captured > 4)
	{
		player.switchWin();
		return (WIN);
	}
	return (OK);
}

bool						Rules::canCaptureLast(Board &b, Board::sCell &cell,
																			Player &opponent)
{
//	Board::eValue			oValue(cell-alue());
//	Board::sCell const		*c;
	unsigned int			i;
	unsigned int			j;

	if (opponent.attribute().captured != 4)
		return (false);
	for (i = 0; i < b.size(); ++i)
	{
		for (j = 0; j < b.size(); ++j)
		{
			if (b.getValue(i, j) == cell.value
				&& b.isCapturable(&b.getCell(i, j)))
			{
				_winMove[cell.value] = &cell;
				return (true);
			}
		}
	}
	return (false);
}
