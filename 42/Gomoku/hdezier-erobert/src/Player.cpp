// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 18:37:06 by hdezier           #+#    #+#             //
//   Updated: 2015/06/01 18:38:04 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"
#include "Board.hpp"

Player::Player(void):
	_ai(false)
{}
Player::~Player(void) {}

bool					Player::ai(void) const
{
	return (_ai);
}
Player::vec2 const		&Player::calculusMove(void) const
{
	return (_calculusMove);
}

void					Player::setAI(bool const &ai)
{
	_ai = ai;
}
Player::vec2 const		&Player::play(Board const &b, Player::vec2 const &event)
{
	if (_ai)
	{
		_calculusMove = calculus(b);
		return (_calculusMove);
	}
	else if (event.x > -1 && event.y > -1)
	{
		_calculusMove = calculus(b);
		return (event);
	}
	return (event);
}

Player::vec2 const		&Player::calculus(Board const &b)
{
	static vec2			result;

	result.x = rand() % b.size();
	result.y = rand() % b.size();
	return (result);
}
