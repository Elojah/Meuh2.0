/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:56 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/07 14:34:34 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define MAX_DEPTH 2

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

	inline void				setAi(bool ai) {m_ai = ai;};
	inline bool				ai(void) const {return (m_ai);};

	common::vec2			play(const IBoard &board, const Rules &rules,
								const common::vec2 &stroke, const common::eCell &player) const;

	struct					sEval : public IEval
	{
		inline virtual uint8_t		eval(const IBoard &board, const Rules &rules, const sMinMaxState &minMaxState) const
		{
			uint8_t			result;

			(void)board;
			(void)rules;
			result = 11;
			result += minMaxState.captures[0] - minMaxState.captures[1];

			return (result);
		}
	};

private:
	bool					m_ai;

	common::vec2			_calculusAI(const IBoard &board, const Rules &rules, const common::eCell &player) const;


};

#endif
