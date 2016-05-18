/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:51 by hdezier           #+#    #+#             */
//   Updated: 2016/05/18 16:58:19 by erobert          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Player.h"
#include "Board.h"

#include <iostream>

common::vec2		Player::play(const IBoard &board, const Rules &rules
								, const common::vec2 &stroke, const common::eCell &player) const
{
	if (m_ai)
		return (calculusAI(board, rules, player));
	return (stroke);
}

common::vec2		Player::calculusAI(const IBoard &board, const Rules &rules, const common::eCell &player) const
{
	sMinMaxResult	result;
	sMinMaxState	minmaxState{MAX_DEPTH, true, player, {ERR_VAL, ERR_VAL}, {0, 0}, {0, ERR_VAL}};
	IBoard			*boardCopy;

	boardCopy = board.getCopy();

	std::cout << "________AI search________" << std::endl;
	std::clock_t c_start = std::clock();
	if (player == common::eCell::P1)
		result = MinMax<sMax>::eval(*boardCopy, rules, minmaxState, m_eval_P1);
	else
		result = MinMax<sMax>::eval(*boardCopy, rules, minmaxState, m_eval_P2);
	std::clock_t c_end = std::clock();
	std::cout << "________AI returned:\t" << (int)result.coord.x << '/' << (int)result.coord.y << std::endl;
	std::cout << "At value:\t" << (int)result.value << std::endl;
	std::cout << "Time elapsed:\t" << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms" << std::endl;
	delete (boardCopy);
	return (result.coord);
}
