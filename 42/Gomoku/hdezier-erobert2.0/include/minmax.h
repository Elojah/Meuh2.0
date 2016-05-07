/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:01:31 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/07 14:32:47 by hdezier          ###   ########.fr       */
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

	inline static sMinMaxResult	&&eval(IBoard &board, const Rules &rules, const sMinMaxState &minmaxState, const IEval &evalFunction)
	{

		if (minmaxState.depth == 0)
			return (std::move((sMinMaxResult){(common::vec2){ERR_VAL, ERR_VAL}
				, evalFunction.eval(board, rules, minmaxState)}));

		uint8_t					nCaptures(0);
		uint16_t				captures(0);
		sMinMaxResult			initialValue = {(common::vec2){ERR_VAL, ERR_VAL}, T::initialValue};

		// Use iterator instead
		uint8_t		size = board.getSize();
		for (uint8_t i = 0; i < size; ++i)
		{
			for (uint8_t j = 0; j < size; ++j)
			{
				if (!rules.isValid(board, {i, j}, minmaxState.currentPlayer))
					continue ;

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

				auto	nextValue = T::search(
					board, rules
					, {(uint8_t)(minmaxState.depth - 1), !minmaxState.maximizing, OPPONENT(minmaxState.currentPlayer)
					, {capture_P1, capture_P2}}
					, evalFunction);

				rules.undoCapture(board, {i, j}, captures, OPPONENT(minmaxState.currentPlayer));
				board.setCell({i, j}, common::eCell::NONE);

				if (T::compareValues(nextValue.value, initialValue.value))
				{
					initialValue.coord = {i, j};
					initialValue.value = nextValue.value;
				}
			}
		}

		initialValue.print();
		board.displayBoard();
		// DBG_BREAK

		return (std::move(initialValue));
	};

private:

};

struct	sMin
{
	inline static bool			compareValues(const uint8_t nextValue, const uint8_t currentValue) {return (nextValue < currentValue);};
	inline static sMinMaxResult	&&search(IBoard &board, const Rules &rules, const sMinMaxState &minmaxState, const IEval &evalFunction) {return (MinMax<sMax>::eval(board, rules, minmaxState, evalFunction));};
	static const uint8_t		initialValue = ERR_VAL;
};

struct	sMax
{
	inline static bool			compareValues(const uint8_t nextValue, const uint8_t currentValue) {return (nextValue > currentValue);};
	inline static sMinMaxResult	&&search(IBoard &board, const Rules &rules, const sMinMaxState &minmaxState, const IEval &evalFunction) {return (MinMax<sMin>::eval(board, rules, minmaxState, evalFunction));};
	static const uint8_t		initialValue = 0;
};

#endif
