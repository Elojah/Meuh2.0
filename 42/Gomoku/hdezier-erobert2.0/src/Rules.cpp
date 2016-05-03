/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rules.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:55:29 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 04:44:41 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rules.h"
#include "Board.h"

#include <iostream>

Rules::Rules(void)
	: m_capturedStone_P1(0)
	,m_capturedStone_P2(0)
{
	;
}

void		Rules::addCapturedStones(const uint8_t &n, const common::eCell &player)
{
	if (player == common::eCell::P1)
		m_capturedStone_P1 += n;
	else if (player == common::eCell::P2)
		m_capturedStone_P2 += n;
}

common::eCell	Rules::gameEnded(const IBoard &board, const common::vec2 &stroke)
{
	(void)board;
	(void)stroke;
	if (m_capturedStone_P1 > 9)
		return (common::eCell::P1);
	else if (m_capturedStone_P2 > 9)
		return (common::eCell::P2);
	return (common::eCell::E_CELL);
}

bool		Rules::isValid(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn)
{
	(void)board;
	(void)stroke;
	return (board.getCell(stroke) == common::eCell::NONE
		&& !_insertDoubleFreeThree(board, stroke, turn));
}

bool		Rules::_insertDoubleFreeThree(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn)
{
	uint8_t		nFreeThree(0);

	for (uint8_t i = 1; i < 5; ++i)
	{
		int8_t		align = board.countAlign(stroke, (common::eDirection)i, turn);

		std::cout << "Alignment\t" << (int)i << "=\t" << (int)align << std::endl;
		if (align >= 2)
		{
			++nFreeThree;
			if (nFreeThree == 2)
				return (true);
		}
	}
	return (false);
}

uint8_t			Rules::applyCapture(IBoard &board, const common::vec2 &stroke)
{
	common::eCell	player(board.getCell(stroke));
	common::eCell	opponent(OPPONENT(player));
	uint8_t			result(0);

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
		}
	}
	return (result);
}
