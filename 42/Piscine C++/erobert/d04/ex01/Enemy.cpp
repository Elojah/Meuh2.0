// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 14:11:46 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 14:40:26 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

Enemy::Enemy(void):
	_hp(0),
	_type("?")
{
}
Enemy::Enemy(Enemy const &e)
{
	*this = e;
}
Enemy::Enemy(int hp, std::string const &type):
	_hp(hp),
	_type(type)
{
}
Enemy::~Enemy(void)
{
}

Enemy				&Enemy::operator=(Enemy const &e)
{
	if (this != &e)
	{
		_hp = e.getHP();
		_type = e.getType();
	}
	return (*this);
}

int					Enemy::getHP(void) const
{
	return (_hp);
}
std::string const	&Enemy::getType(void) const
{
	return (_type);
}

void				Enemy::takeDamage(int amount)
{
	_hp -= amount;
}
