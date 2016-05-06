/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:51 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/06 12:55:22 by hdezier          ###   ########.fr       */
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
	sMinMaxState	minmaxState{MAX_DEPTH, true, player, {0, 0}};
	IBoard			*boardCopy;

	boardCopy = board.getCopy();
	result = _minmax(*boardCopy, rules, minmaxState).coord;
	std::cout << "AI returned:\t" << (int)result.x << '/' << (int)result.y << std::endl;
	return (result);
}

Player::sMinMaxResult		Player::_minmax(IBoard &board, const Rules &rules, const sMinMaxState &minmaxState) const
{
	uint8_t					nCaptures(0);
	uint16_t				captures(0);

	if (minmaxState.depth == 0)
		return ((sMinMaxResult){(common::vec2){ERR_VAL, ERR_VAL}
			, _calculusValue(board, rules, OPPONENT(minmaxState.currentPlayer), minmaxState.captures)});
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

				// std::cout << "_________MAX___________" << std::endl;
				// board.displayBoard();

				board.setCell({i, j}, minmaxState.currentPlayer);
				nCaptures = rules.applyCapture(board, {i, j}, captures);


				uint8_t	capture_P1;
				uint8_t	capture_P2;
				if (minmaxState.currentPlayer == common::eCell::P1)
				{
					capture_P1 = minmaxState.captures[0] + nCaptures;
					capture_P2 = minmaxState.captures[1];
				}
				else
				{
					capture_P1 = minmaxState.captures[0];
					capture_P2 = minmaxState.captures[1] + nCaptures;
				}
				auto	nextValue = _minmax(
					board, rules
					, {(uint8_t)(minmaxState.depth - 1), !minmaxState.maximizing, OPPONENT(minmaxState.currentPlayer)
					, {capture_P1, capture_P2}
					});

				rules.undoCapture(board, {i, j}, captures, OPPONENT(minmaxState.currentPlayer));
				board.setCell({i, j}, common::eCell::NONE);

				if (nextValue.value > maxValue.value)
				{
					maxValue.coord = {i, j};
					maxValue.value = nextValue.value;
				}
			}
		}
		maxValue.print();
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

				// std::cout << "_________Min___________" << std::endl;
				// board.displayBoard();

				board.setCell({i, j}, minmaxState.currentPlayer);
				nCaptures = rules.applyCapture(board, {i, j}, captures);

				uint8_t	capture_P1;
				uint8_t	capture_P2;
				if (minmaxState.currentPlayer == common::eCell::P1)
				{
					capture_P1 = minmaxState.captures[0] + nCaptures;
					capture_P2 = minmaxState.captures[1];
				}
				else
				{
					capture_P1 = minmaxState.captures[0];
					capture_P2 = minmaxState.captures[1] + nCaptures;
				}

				auto	nextValue = _minmax(board, rules
					, {(uint8_t)(minmaxState.depth - 1), !minmaxState.maximizing, OPPONENT(minmaxState.currentPlayer)
					, {capture_P1, capture_P2}
					});

				rules.undoCapture(board, {i, j}, captures, OPPONENT(minmaxState.currentPlayer));
				board.setCell({i, j}, common::eCell::NONE);

				if (nextValue.value < minValue.value)
				{
					minValue.coord = {i, j};
					minValue.value = nextValue.value;
				}
			}
		}
		minValue.print();
		return (minValue);
	}
	return ((sMinMaxResult){(common::vec2){ERR_VAL, ERR_VAL}, 0});
}

uint8_t				Player::_calculusValue(const IBoard &board, const Rules &rules, const common::eCell &player, const uint8_t captures[2])
{
	uint8_t			result;

	(void)rules;
	(void)board;
	result = 1;
	uint8_t			size = board.getSize();
	common::eCell	opponent = OPPONENT(player);

	// Use iterator instead
	for (uint8_t i = 0; i < size; ++i)
	{
		for (uint8_t j = 0; j < size; ++j)
		{
			if (board.getCell({i, j}) == player)
				++result;
			else if (board.getCell({i, j}) == opponent && result > 0)
				--result;
		}
	}
	result += (player == common::eCell::P1) ? captures[0] : captures[1];
	return (result);
}
