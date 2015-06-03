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

#include <iostream>
#include "Player.hpp"
#include "Board.hpp"
#include "Rules.hpp"

Player::Player(void):
	_ai(false)
{}
Player::~Player(void) {}

bool					Player::ai(void) const
{
	return (_ai);
}

void					Player::setAI(bool const &ai)
{
	_ai = ai;
}

void					Player::attribPlayer(Cell::eValue e)
{
	_e = e;
}

Player::vec2 const		&Player::calculusMove(void) const
{
	return (_calculusMove);
}

Player::vec2 const		&Player::play(Board &b, Player::vec2 const &event)
{
	if (_ai)
	{
		_calculusMove = calculus(b);
		if (_calculusMove.x < 0 || _calculusMove.y < 0)
			std::cout << "IA can't find valid move :(" << std::endl;
		return (_calculusMove);
	}
	else if (event.x > -1 && event.y > -1)
	{
		_calculusMove = calculus(b);
		return (event);
	}
	return (event);
}

Player::vec2 const		&Player::calculus(Board &b)
{
	// static vec2			result;
	static vec2				tmp;
	// Cell const			*c;
	// Rules::eValidity	resultMove;
	// int					size(b.size());

	// tmp.x = -1;
	// tmp.y = -1;
	(void)b;
	tmp.x = rand() % b.size();
	tmp.y = rand() % b.size();
	// for (int i = 0; i < size; ++i)
	// {
	// 	for (int j = 0; j < size; ++j)
	// 	{
	// 		if (!(c = &b.getCell(i, j))->isPlayable()
	// 			|| c->getValue() != Cell::EMPTY)
	// 			continue ;
	// 		tmp.x = i;
	// 		tmp.y = j;
	// 		resultMove = Rules::makeMove(b, tmp, _e);
	// 		b.getCell(i, j).setValue(Cell::EMPTY);
	// 		if (resultMove == Rules::INVALID)
	// 			continue ;
	// 		else if (resultMove == Rules::WIN)
	// 			return (tmp);
	// 	}
	// }
	return (tmp);
}
