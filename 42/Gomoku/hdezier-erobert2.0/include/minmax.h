/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:01:31 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/07 16:10:17 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINMAX_H
# define MINMAX_H

# include "common.h"
# include "Board.h"
# include "Rules.h"

# include <iostream>

struct	sMin;
struct	sMax;

// Helper struct
struct					sMinMaxState
{
	const uint8_t		depth;
	const bool			maximizing;
	const common::eCell	currentPlayer;
	const common::vec2	lastStroke;
	uint8_t				captures[2];
};

struct					sMinMaxResult
{
	common::vec2		coord;
	uint8_t				value;
	inline void			print(void) const {std::cout << "Coord:" << (int)coord.x << "/" << (int)coord.y << "=" << (int)value << std::endl;};
};

struct					IEval
{
	virtual uint8_t		eval(const IBoard &board, const Rules &rules, const sMinMaxState &minMaxState) const = 0;
};

// Extern class
template<typename T>
class		MinMax
{

public:
	inline static sMinMaxResult	&&eval(IBoard &board, const Rules &rules, const sMinMaxState &minMaxState, const IEval &evalFunction)
	{

		if (minMaxState.depth == 0
			|| rules.gameEnded(board, minMaxState.lastStroke, minMaxState.captures[0], minMaxState.captures[1]) != common::eCell::E_CELL)
			return (std::move((sMinMaxResult){(common::vec2){ERR_VAL, ERR_VAL}
				, evalFunction.eval(board, rules, minMaxState)}));

		uint8_t					nCaptures(0);
		uint16_t				captures(0);
		sMinMaxResult			initialValue = {(common::vec2){ERR_VAL, ERR_VAL}, T::initialValue};

		// Use iterator instead
		uint8_t		size = board.getSize();
		for (uint8_t i = 0; i < size; ++i)
		{
			for (uint8_t j = 0; j < size; ++j)
			{
				if (!rules.isValid(board, {i, j}, minMaxState.currentPlayer))
					continue ;

				board.setCell({i, j}, minMaxState.currentPlayer);
				nCaptures = rules.applyCapture(board, {i, j}, captures);

				auto	nextValue = T::search(
					board, rules
					, {(uint8_t)(minMaxState.depth - 1), !minMaxState.maximizing, OPPONENT(minMaxState.currentPlayer)
					, {i, j}
					, {(uint8_t)(minMaxState.currentPlayer == common::eCell::P1 ? minMaxState.captures[0] + nCaptures : minMaxState.captures[0])
						, (uint8_t)(minMaxState.currentPlayer == common::eCell::P1 ? minMaxState.captures[1]: minMaxState.captures[1] + nCaptures)}}
					, evalFunction);

				rules.undoCapture(board, {i, j}, captures, OPPONENT(minMaxState.currentPlayer));
				board.setCell({i, j}, common::eCell::NONE);

				if (T::compareValues(nextValue.value, initialValue.value))
				{
					initialValue.coord = {i, j};
					initialValue.value = nextValue.value;
				}
			}
		}

		// initialValue.print();
		// board.displayBoard();
		// DBG_BREAK

		return (std::move(initialValue));
	};

private:
};

struct	sMin
{
	inline static bool			compareValues(const uint8_t nextValue, const uint8_t currentValue) {return (nextValue < currentValue);};
	inline static sMinMaxResult	&&search(IBoard &board, const Rules &rules, const sMinMaxState &minMaxState, const IEval &evalFunction) {return (MinMax<sMax>::eval(board, rules, minMaxState, evalFunction));};
	static const uint8_t		initialValue = ERR_VAL;
};

struct	sMax
{
	inline static bool			compareValues(const uint8_t nextValue, const uint8_t currentValue) {return (nextValue > currentValue);};
	inline static sMinMaxResult	&&search(IBoard &board, const Rules &rules, const sMinMaxState &minMaxState, const IEval &evalFunction) {return (MinMax<sMin>::eval(board, rules, minMaxState, evalFunction));};
	static const uint8_t		initialValue = 0;
};

#endif
