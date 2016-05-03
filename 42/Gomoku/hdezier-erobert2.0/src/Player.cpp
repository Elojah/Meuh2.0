/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:51 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 07:52:42 by hdezier          ###   ########.fr       */
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
	sMinMaxState	minmaxState{MAX_DEPTH, true, player};
	IBoard			*boardCopy;

	boardCopy = board.getCopy();
	result = _minmax(*boardCopy, rules, minmaxState).coord;
	std::cout << "AI returned:\t" << (int)result.x << '/' << (int)result.y << std::endl;
	return (result);
}

Player::sMinMaxResult		Player::_minmax(IBoard &board, const Rules &rules, const sMinMaxState &minmaxState) const
{
	uint16_t				captures(0);

	if (minmaxState.depth == 0)
		return ((sMinMaxResult){(common::vec2){ERR_VAL, ERR_VAL}, 0});
	// Max
	if (minmaxState.maximizing)
	{
		sMinMaxResult		maxValue = {(common::vec2){ERR_VAL, ERR_VAL}, 0};
		// Use iterator instead
		uint8_t		size = board.getSize();
		for (uint8_t i = 0; i < size; ++i)
		{
			for (uint8_t j = 0; j < size; ++j)
			{
				if (!rules.isValid(board, {i, j}, minmaxState.currentPlayer))
					continue ;
				std::cout << "Valid coord in:\t" << (int)i << "/" << j << std::endl;

				board.setCell({i, j}, minmaxState.currentPlayer);
				rules.applyCapture(board, {i, j}, captures);
				auto	nextValue = _minmax(board, rules
					, {(uint8_t)(minmaxState.depth - 1), !minmaxState.maximizing, OPPONENT(minmaxState.currentPlayer)});

				std::cout << "Value=\t" << (int)nextValue.value << std::endl;

				rules.undoCapture(board, {i, j}, captures, OPPONENT(minmaxState.currentPlayer));
				board.setCell({i, j}, common::eCell::NONE);

				if (nextValue.value > maxValue.value)
				{
					maxValue.coord = nextValue.coord;
					maxValue.value = nextValue.value;
				}
			}
		}
		return (maxValue);
	}
	else // Min
	{
		sMinMaxResult		minValue = {(common::vec2){ERR_VAL, ERR_VAL}, ERR_VAL};
		// Use iterator instead
		uint8_t		size = board.getSize();
		for (uint8_t i = 0; i < size; ++i)
		{
			for (uint8_t j = 0; j < size; ++j)
			{
				if (!rules.isValid(board, {i, j}, minmaxState.currentPlayer))
					continue ;

				board.setCell({i, j}, minmaxState.currentPlayer);
				rules.applyCapture(board, {i, j}, captures);

				auto	nextValue = _minmax(board, rules
					, {(uint8_t)(minmaxState.depth - 1), !minmaxState.maximizing, OPPONENT(minmaxState.currentPlayer)});

				rules.undoCapture(board, {i, j}, captures, OPPONENT(minmaxState.currentPlayer));
				board.setCell({i, j}, common::eCell::NONE);

				if (nextValue.value < minValue.value)
				{
					minValue.coord = nextValue.coord;
					minValue.value = nextValue.value;
				}
			}
		}
		return (minValue);
	}
	return ((sMinMaxResult){(common::vec2){ERR_VAL, ERR_VAL}, 0});
}

uint8_t				Player::_calculusValue(IBoard &board, const Rules &rules, const common::vec2 &stroke, const common::eCell &player)
{
	uint8_t			result;

	board.setCell(stroke, player);
	(void)rules;
	result = std::abs(stroke.x - stroke.y);
	board.setCell(stroke, common::eCell::NONE);
	return (0);
}
