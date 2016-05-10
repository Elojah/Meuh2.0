/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:56 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 05:42:34 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

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

	inline void				switchAI() {m_ai = !m_ai;};
	inline bool				ai(void) const {return (m_ai);};

	common::vec2	play(const IBoard &board, const Rules &rules,
						 common::vec2 stroke) const;
private:
	bool			m_ai = false;
};

#endif
