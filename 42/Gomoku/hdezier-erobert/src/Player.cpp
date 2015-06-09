// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 18:37:06 by hdezier           #+#    #+#             //
//   Updated: 2015/06/09 15:07:20 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "Player.hpp"
#include "Board.hpp"
#include "Rules.hpp"

Player::Player(void)
{
	_attribute.ai = false;
	_attribute.turn = false;
	_attribute.win = false;
	_attribute.x = -1;
	_attribute.y = -1;
	_attribute.captured = 0;
}
Player::~Player(void) {}

Player::sAttribute const	&Player::attribute(void) const
{
	return (_attribute);
}
Player::vec2 const			&Player::calculusMove(void) const
{
	return (_calculusMove);
}

void						Player::switchAI(void)
{
	_attribute.ai = !_attribute.ai;
}
void						Player::switchTurn(void)
{
	_attribute.turn = !_attribute.turn;
}
void						Player::switchWin(void)
{
	_attribute.win = !_attribute.win;
}
void						Player::addCapture(int n)
{
	_attribute.captured += n;
}
bool						Player::play(Board &b, Player::vec2 const &move,
										 Player &opponent)
{
	if (!_attribute.turn)
		return (false);
	else if (_attribute.ai)
	{
		calculus(b, opponent);
		if (_calculusMove.x < 0 || _calculusMove.y < 0)
		{
			std::cout << "IA can't find valid move :(" << std::endl;
			return (false);
		}
		_attribute.x = _calculusMove.x;
		_attribute.y = _calculusMove.y;
		return (true);
	}
	else if (move.x > -1 && move.y > -1)
	{
		_attribute.x = move.x;
		_attribute.y = move.y;
		calculus(b, opponent);
		return (true);
	}
	return (false);
}

void						Player::calculus(Board &b, Player &opponent)
{
	(void)opponent;
	// static vec2			result;
	// Cell const			*c;
	// Rules::eValidity	resultMove;
	// int					size(b.size());

	// tmp.x = -1;
	// tmp.y = -1;
	(void)b;
	_calculusMove.x = rand() % b.size();
	_calculusMove.y = rand() % b.size();
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
//	return (tmp);
}
