/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:39:44 by hdezier           #+#    #+#             */
//   Updated: 2016/05/03 04:32:03 by erobert          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "GameManager.h"
#include <iostream>
#include <fstream>

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
	common::eCell	turn;

	_loadMap("util/test.map");
	turn = common::eCell::P1;
	m_uI.init(N);
	m_uI.render(m_board, m_player_1, m_player_2);
	while (1)
	{
		if (turn == common::eCell::P1)
			current_player = &m_player_1;
		else if (turn == common::eCell::P2)
			current_player = &m_player_2;
		else
			std::cerr << "Player is not recognized" << std::endl;
		valid = false;
		while (!valid)
		{
			stroke = current_player->play(m_board, m_rules, eventHandler());
			valid = m_rules.isValid(m_board, stroke, turn);
			if (!valid)
				std::cout << "Unvalid stroke" << std::endl;
		}
		std::cout << "Player " << (int)turn << " in " << (int)stroke.x << "/" << (int)stroke.y << std::endl;
		m_board.setCell(stroke, turn);
		m_board.displayBoard();
		m_uI.getEvent();
		m_uI.render(m_board, m_player_1, m_player_2);
		win = m_rules.gameEnded(m_board, stroke);
		if (win != common::eCell::E_CELL)
			break ;
		turn = (turn == common::eCell::P1) ? common::eCell::P2 : common::eCell::P1;
	}
	displayWin(win);
}

template <uint8_t N>
void	GameManager<N>::_loadMap(const std::string &file)
{
	std::ifstream		ifs(file.c_str());
	std::string			line;
	uint8_t				x;
	uint8_t				y;

	x = 0;
	while (std::getline(ifs, line))
	{
		for (y = 0; y < line.size(); ++y)
		{
			const auto c = line[y];
			if (c == '1')
				m_board.setCell({x, y}, common::eCell::P1);
			else if (c == '2')
				m_board.setCell({x, y}, common::eCell::P2);
		}
		++x;
	}
}

template <uint8_t N>
common::vec2 const					&GameManager<N>::eventHandler(void)
{
	static common::vec2				stroke;
	static UserInterface::sEvent	event;

	stroke.x = -1;
	stroke.y = -1;
	event = m_uI.getEvent();
/*	if (event.e == UserInterface::EXIT)
		_exit = true;
	else if (event.e == UserInterface::RESTART)
	{
		_restart = true;
		_exit = true;
	}
*/	if (event.e == UserInterface::MOUSE)
	{
		stroke.x = event.x;
		stroke.y = event.y;
	}
/*	else if (event.e == UserInterface::P1_AI)
		_p1.switchAI();
	else if (event.e == UserInterface::P2_AI)
		_p2.switchAI();
	else if (event.e == UserInterface::PLAY)
		_audio.playMusic(AudioManager::HYMNE_A_LA_KRO);
	else if (event.e == UserInterface::NEXT)
		_audio.nextMusic();
	else if (event.e == UserInterface::STOP)
		_audio.stopMusic();
*/	return (stroke);
}



template class GameManager<common::small>;
template class GameManager<common::medium>;
template class GameManager<common::large>;
