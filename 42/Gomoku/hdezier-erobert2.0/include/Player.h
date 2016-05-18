/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:56 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/18 15:34:35 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define MAX_DEPTH 3

# include "stdint.h"
# include "common.h"
# include "minmax.h"

# include <iostream>

class IBoard;
class Rules;
class UserInterface;

class Player
{
public:
	Player(void) = default;
	virtual ~Player(void) = default;

	inline void				switchAI() {m_ai = !m_ai;};
	inline bool				ai(void) const {return (m_ai);};

	common::vec2			play(const IBoard &board, const Rules &rules,
								const common::vec2 &stroke, const common::eCell &player) const;

	struct					sEval_P1 : public IEval
	{
		inline virtual uint8_t		eval(const IBoard &board, const Rules &rules, const sMinMaxState &minMaxState) const
		{
			uint8_t					result(112);

			const common::eCell win = rules.gameEnded(board, minMaxState.lastStroke, minMaxState.captures[0], minMaxState.captures[1]);
			if (win == common::eCell::P2)
				return (1 + (MAX_DEPTH - minMaxState.depth));
			else if (win == common::eCell::P1)
				return (255 - (MAX_DEPTH - minMaxState.depth));
			int8_t align = board.countAllAlign(common::eCell::P1);
			result += align;
			result += (minMaxState.captures[0] - minMaxState.captures[1]);
			return (result);
		}
	};

	struct					sEval_P2 : public IEval
	{
		inline virtual uint8_t		eval(const IBoard &board, const Rules &rules, const sMinMaxState &minMaxState) const
		{
			uint8_t			result(112);

			const common::eCell win = rules.gameEnded(board, minMaxState.lastStroke, minMaxState.captures[0], minMaxState.captures[1]);
			if (win == common::eCell::P1)
				return (1 + (MAX_DEPTH - minMaxState.depth));
			else if (win == common::eCell::P2)
				return (255 - (MAX_DEPTH - minMaxState.depth));
			int8_t align = board.countAllAlign(common::eCell::P2);
			result += align;
			result += (minMaxState.captures[1] - minMaxState.captures[0]);
			return (result);
		}
	};

private:
	bool					m_ai = false;
	common::vec2			_calculusAI(const IBoard &board, const Rules &rules, const common::eCell &player) const;

	sEval_P1		m_eval_P1;
	sEval_P2		m_eval_P2;
};

#endif
