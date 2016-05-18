/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rules.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:55:29 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/18 16:50:54 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rules.h"
#include "Board.h"

#include <iostream>

Rules::Rules(void)
{
	m_capturedStones[0] = 0;
	m_capturedStones[1] = 0;
}

void		Rules::addCapturedStones(const uint8_t &n, const common::eCell &player)
{
	if (player == common::eCell::P1)
		m_capturedStones[0] += n;
	else if (player == common::eCell::P2)
		m_capturedStones[1] += n;
}

bool			Rules::_alignFive(const IBoard &board, const common::vec2 &stroke)
{
	const common::eCell	player(board.getCell(stroke));

	for (uint8_t i = 1; i < 5; ++i)
	{
		if (board.countAlign(stroke, (common::eDirection)i, player)
			+ board.countAlign(stroke, common::opposite((common::eDirection)i), player) > 3)
			return (true);
	}
	return (false);
}

common::eCell	Rules::gameEnded(const IBoard &board, const common::vec2 &stroke, uint8_t capture_P1, uint8_t capture_P2) const
{
	if (m_capturedStones[0] + capture_P1 > 9)
		return (common::eCell::P1);
	else if (m_capturedStones[1] + capture_P2 > 9)
		return (common::eCell::P2);
	if (_alignFive(board, stroke))
		return (board.getCell(stroke));
	return (common::eCell::E_CELL);
}

bool		Rules::isValid(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn)
{
	return (board.getCell(stroke) == common::eCell::NONE
		&& !_insertDoubleFreeThree(board, stroke, turn));
}

bool		Rules::_insertDoubleFreeThree(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn)
{
	uint8_t		nFreeThree(0);

	for (uint8_t i = 1; i < 5; ++i)
	{
		int8_t		align = board.countAlignFree(stroke, (common::eDirection)i, turn);

		if (align >= 2)
		{
			++nFreeThree;
			if (nFreeThree == 2)
				return (true);
		}
	}
	return (false);
}

uint8_t			Rules::applyCapture(IBoard &board, const common::vec2 &stroke, uint16_t &saveState)
{
	const common::eCell	player(board.getCell(stroke));
	const common::eCell	opponent(OPPONENT(player));
	uint8_t				result(0);

	saveState = 0;
	for (int8_t i = -4; i < 5; ++i)
	{
		if (i == 0)
			continue ;
		if (board.getCell(stroke, (common::eDirection)i, 1) == opponent
			&& board.getCell(stroke, (common::eDirection)i, 2) == opponent
			&& board.getCell(stroke, (common::eDirection)i, 3) == player)
		{
			board.setCell(stroke, (common::eDirection)i, 1, common::eCell::NONE);
			board.setCell(stroke, (common::eDirection)i, 2, common::eCell::NONE);
			result += 2;
			saveState |= 1 << (i + 4);
		}
	}
	return (result);
}

void			Rules::undoCapture(IBoard &board, const common::vec2 &stroke, uint16_t &saveState, const common::eCell &player)
{
	for (int8_t i = -4; i < 5; ++i)
	{
		if (i == 0)
			continue ;
		if ((saveState >> (i + 4)) & 1)
		{
			board.setCell(stroke, (common::eDirection)i, 1, player);
			board.setCell(stroke, (common::eDirection)i, 2, player);
		}
	}
}
