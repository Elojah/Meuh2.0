/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:39:50 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 03:02:53 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MANAGER_H
# define GAME_MANAGER_H

# include "stdint.h"
# include <string>

# include "Board.h"
# include "Rules.h"
# include "Player.h"

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

	void	displayWin(common::eCell winner) const;
	void	_loadMap(const std::string &file);
};

#endif
