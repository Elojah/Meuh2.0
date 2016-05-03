/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:56 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 00:55:29 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "stdint.h"
# include "common.h"

class IBoard;
class Rules;

class Player
{
public:
	Player(void) = default;
	virtual ~Player(void) = default;

	bool				ai(void) const;

	void				setAi(bool ai);
	common::vec2		play(const IBoard &board, const Rules &rules) const;
private:
	bool				m_ai;
};

#endif
