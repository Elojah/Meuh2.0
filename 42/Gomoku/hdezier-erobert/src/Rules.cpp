// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Rules.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/05 17:25:46 by hdezier           #+#    #+#             //
//   Updated: 2015/06/08 18:43:53 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Rules.hpp"
#include "Board.hpp"

Cell const					*Rules::_winMove[Cell::E_VALUE];

void						Rules::reset(void)
{
	int						i(-1);

	while (++i < Cell::E_VALUE)
		_winMove[i] = NULL;
}
/*
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
*/
#include <iostream>
Rules::eValidity			Rules::makeMove(Board &b, Player &p1, Player &p2)
{
	Player					&player(p1.attribute().turn ? p1 : p2);
	Player					&opponent(p1.attribute().turn ? p2 : p1);
	Cell::eValue			pValue(p1.attribute().turn ? Cell::P1 : Cell::P2);
	Rules::eValidity		result(INVALID);
	Cell					&c(b.getCell(player.attribute().x,
										 player.attribute().y));
	int						dirWin;

	if (c.getValue() != Cell::EMPTY)
		return (INVALID);
	else
	{
		c.setValue(pValue);
		if (Rules::insertDoubleFreethrees(c))
		{
			c.setValue(Cell::EMPTY);
			return (result);
		}
		result = Rules::captureStone(c, player);
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

int							Rules::win(Cell const &cell)
{
	Cell::eValue const		&value(cell.getValue());
	int						result(0);
	int						align1;
	int						align2;

	if (value == Cell::EMPTY)
		return (result);
	for (int i = 0; i < 4; ++i)
	{
		align1 = cell.countAlign(value, CAST_DIR(i));
		align2 = cell.countAlign(value, CAST_DIR(i + 4));
		if (align1 + align2 > 5)
			result = result | (1 << i);
	}
	return (result);
}
bool						Rules::insertDoubleFreethrees(Cell &cell)
{
	Cell::eValue			value(cell.getValue());
	int						count(0);
	int						align1;
	int						align2;
	int						nPermissive;
	int						i;

	for (i = 0; i < 4; ++i)
	{
		nPermissive = 1;
		align1 = cell.countFreeThrees(value, CAST_DIR(i),
									  Cell::EMPTY, nPermissive) - 1;
		align2 = cell.countFreeThrees(value, CAST_DIR(i + 4),
									  Cell::EMPTY, nPermissive) - 1;
		if ((align1 + align2 > 1 && nPermissive > 0)
			|| (align1 + align2 > 2 && nPermissive == 0))
			++count;
	}
	return (count > 1);
}
bool						Rules::canCaptureFive(Cell const &cell, int dirWin)
{
	Cell::eValue			value(cell.getValue());
	bool					result(false);
	int						i;

	for (i = 0; i < 4; ++i)
	{
		if (!((dirWin >> i) & 1))
			continue ;
		else if (cell.isCapturableDirection(CAST_DIR(i), value)
			|| cell.isCapturableDirection(CAST_DIR(OPPOSITE(i)), value))
		{
			_winMove[value] = &cell;
			result = true;
		}
		else
			return (false);
	}
	return (result);
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
	if (player.attribute().captured > 4)
	{
		player.switchWin();
		return (WIN);
	}
	return (OK);
}
bool						Rules::canCaptureLast(Board const &b, Cell &cell,
												  Player &opponent)
{
	Cell::eValue			oValue(cell.getValue());
	Cell const				*c;
	unsigned int			i;
	unsigned int			j;

	if (opponent.attribute().captured != 4)
		return (false);
	for (i = 0; i < b.size(); ++i)
	{
		for (j = 0; j < b.size(); ++j)
		{
			if (b.getValue(i, j) == oValue
				&& (c = &(b.getCell(i, j)))->isCapturable())
			{
				_winMove[oValue] = &cell;
				return (true);
			}
		}
	}
	return (false);
}
