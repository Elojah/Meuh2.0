/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:39:44 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 00:26:40 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameManager.h"
#include <iostream>

template <uint8_t N>
void	GameManager<N>::displayWin(common::eCell winner) const
{
	if (winner == common::eCell::P1)
		std::cout << "P1 win !" << std::endl;
	else if (winner == common::eCell::P2)
		std::cout << "P2 win !" << std::endl;
	else if (winner == common::eCell::NONE)
		std::cout << "Draw !" << std::endl;
}

template <uint8_t N>
void	GameManager<N>::loop(void)
{
	Player			*current_player;
	bool			valid;
	common::vec2	stroke;
	common::eCell	win;

	m_turn = common::eCell::P1;
	while (1)
	{
		if (m_turn == common::eCell::P1)
			current_player = &m_player_1;
		else if (m_turn == common::eCell::P2)
			current_player = &m_player_2;
		else
			std::cerr << "Player is not recognized" << std::endl;
		valid = false;
		while (!valid)
		{
			stroke = current_player->play(m_board, m_rules);
			valid = m_rules.isValid(m_board, stroke);
		}
		std::cout << "Player " << (int)m_turn << " in " << (int)stroke.x << "/" << (int)stroke.y << std::endl;
		m_board.setCell(stroke, m_turn);
		m_board.displayBoard();
		win = m_rules.gameEnded(m_board, m_turn);
		if (win != common::eCell::E_CELL)
			break ;
		m_turn = (m_turn == common::eCell::P1) ? common::eCell::P2 : common::eCell::P1;
	}
	displayWin(win);
}

template class GameManager<common::small>;
template class GameManager<common::medium>;
template class GameManager<common::large>;
