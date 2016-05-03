/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rules.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:55:29 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 03:15:33 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rules.h"
#include "Board.h"

#include <iostream>

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

common::eCell	Rules::gameEnded(const IBoard &board, const common::vec2 &stroke)
{
	(void)board;
	(void)stroke;
	return (common::eCell::E_CELL);
}
