/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:56 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 07:16:04 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define MAX_DEPTH 2

# include "stdint.h"
# include "common.h"

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
private:
	bool					m_ai;

	struct					sMinMaxState
	{
		const uint8_t		depth;
		const bool			maximizing;
		const common::eCell	currentPlayer;
	};

	struct					sMinMaxResult
	{
		common::vec2		coord;
		uint8_t				value;
	};

	common::vec2			_calculusAI(const IBoard &board, const Rules &rules, const common::eCell &player) const;
	sMinMaxResult			_minmax(IBoard &board, const Rules &rules, const sMinMaxState &minmaxState) const;
	uint8_t					_calculusValue(IBoard &board, const Rules &rules, const common::vec2 &stroke, const common::eCell &player);

};

#endif
