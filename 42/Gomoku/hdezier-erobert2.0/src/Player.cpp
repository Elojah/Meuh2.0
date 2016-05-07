/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:51 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/07 15:12:19 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.h"
#include "Board.h"

#include <iostream>

common::vec2		Player::play(const IBoard &board, const Rules &rules
								, const common::vec2 &stroke, const common::eCell &player) const
{
	if (m_ai)
		return (_calculusAI(board, rules, player));
	return (stroke);
}

common::vec2		Player::_calculusAI(const IBoard &board, const Rules &rules, const common::eCell &player) const
{
	common::vec2	result;
	sMinMaxState	minmaxState{MAX_DEPTH, true, player, {ERR_VAL, ERR_VAL}, {0, 0}};
	IBoard			*boardCopy;

	boardCopy = board.getCopy();

	std::cout << "________AI search________" << std::endl;
	if (player == common::eCell::P1)
		result = MinMax<sMax>::eval(*boardCopy, rules, minmaxState, m_eval_P1).coord;
	else
		result = MinMax<sMax>::eval(*boardCopy, rules, minmaxState, m_eval_P2).coord;
	std::cout << "________AI returned:\t" << (int)result.x << '/' << (int)result.y << std::endl;
	delete (boardCopy);
	return (result);
}
