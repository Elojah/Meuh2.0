/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:51 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 03:53:20 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.h"

#include <iostream>

bool				Player::ai(void) const
{
	return (m_ai);
}

common::vec2		Player::play(const IBoard &board, const Rules &rules) const
{
	int				x;
	int				y;

	(void)board;
	(void)rules;
	std::cin >> x;
	std::cin >> y;
	return (common::vec2{(uint8_t)(x), (uint8_t)(y)});
}
