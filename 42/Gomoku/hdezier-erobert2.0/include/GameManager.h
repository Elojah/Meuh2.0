/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:39:50 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 01:17:56 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MANAGER_H
# define GAME_MANAGER_H

# include "stdint.h"

# include "Board.h"
# include "Rules.h"
# include "Player.h"
# include "UserInterface.hpp"

enum class eSize
{
	SMALL,
	MEDIUM,
	LARGE,
	ERROR
};

template <uint8_t N>
class GameManager
{
public:
	GameManager(void) = default;
	virtual ~GameManager(void) = default;

	void	loop(void);
private:
	Board<N>		m_board;
	Rules			m_rules;
	Player			m_player_1;
	Player			m_player_2;
	common::eCell	m_turn;
	UserInterface	m_uI;

	void	displayWin(common::eCell winner) const;
};

#endif
