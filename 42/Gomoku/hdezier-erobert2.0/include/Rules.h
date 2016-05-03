/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:55:33 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 04:44:13 by hdezier          ###   ########.fr       */
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
	common::eCell			gameEnded(const IBoard &board, const common::vec2 &stroke);

	static bool				isValid(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn);
	static uint8_t			applyCapture(IBoard &board, const common::vec2 &stroke);

private:
	uint8_t		m_capturedStone_P1;
	uint8_t		m_capturedStone_P2;

	static bool				_insertDoubleFreeThree(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn);
};

#endif
