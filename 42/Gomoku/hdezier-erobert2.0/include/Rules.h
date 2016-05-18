/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:55:33 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/07 15:17:22 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "common.h"

class IBoard;

class Rules
{
public:

	Rules(void);
	virtual ~Rules(void) = default;

	void					addCapturedStones(const uint8_t &n, const common::eCell &player);
	common::eCell			gameEnded(const IBoard &board, const common::vec2 &stroke, uint8_t capture_P1 = 0, uint8_t capture_P2 = 0) const;

	static bool				isValid(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn);
	static uint8_t			applyCapture(IBoard &board, const common::vec2 &stroke, uint16_t &saveState);
	static void				undoCapture(IBoard &board, const common::vec2 &stroke, uint16_t &saveState, const common::eCell &player);

	inline uint8_t			getCapturedStone(const common::eCell &player) const
	{
		if (player == common::eCell::P1)
			return (m_capturedStone_P1);
		else if (player == common::eCell::P2)
			return (m_capturedStone_P2);
		return (0);
	};

private:
	uint8_t		m_capturedStone_P1;
	uint8_t		m_capturedStone_P2;

	static bool				_insertDoubleFreeThree(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn);
	static bool				_alignFive(const IBoard &board, const common::vec2 &stroke);
};

#endif
