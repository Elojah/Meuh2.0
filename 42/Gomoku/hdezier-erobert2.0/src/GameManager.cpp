/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:39:44 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/02 23:02:26 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameManager.h"
#include <iostream>

template <uint8_t N>
void	GameManager<N>::loop(void)
{
	Player			*current_player;
	bool			valid(false);
	common::vec2	stroke;

	while (1)
	{
		if (m_turn == common::eCell::P1)
			current_player = &m_player_1;
		else if (m_turn == common::eCell::P2)
			current_player = &m_player_2;
		else
			std::cerr << "Player is not recognized" << std::endl;
		while (!valid)
		{
			stroke = current_player->play(m_board, m_rules);
			valid = m_rules.isValid(m_board, stroke);
		}
		m_board.setCell(stroke, m_turn);
	}
}

template class GameManager<common::small>;
template class GameManager<common::medium>;
template class GameManager<common::large>;
