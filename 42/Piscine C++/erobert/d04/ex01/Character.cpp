// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 14:51:06 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 16:23:22 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

Character::Character(void):
	_name("?"),
	_ap(40),
	_w(NULL)
{
}
Character::Character(Character const &c)
{
	*this = c;
}
Character::Character(std::string const &name):
	_name(name),
	_ap(40),
	_w(NULL)
{
}
Character::~Character(void)
{
}

Character			&Character::operator=(Character const &c)
{
	if (this != &c)
	{
		_name = c.getName();
		_ap = c.getAP();
		_w = c.getW();
	}
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (_name);
}
int					Character::getAP(void) const
{
	return (_ap);
}
AWeapon				*Character::getW(void) const
{
	return (_w);
}

void				Character::recoverAP(void)
{
	if (_ap > 30)
		_ap = 40;
	else
		_ap += 10;
}
void				Character::equip(AWeapon *w)
{
	_w = w;
}
void				Character::attack(Enemy *e)
{
	if (!_w || !e)
		return ;
	std::cout << _name
			  << " attacks "
			  << e->getType()
			  << " with a "
			  << _w->getName()
			  << std::endl;
	if (_w->getAPCost() > _ap)
		return ;
	_w->attack();
	_ap -= _w->getAPCost();
	e->takeDamage(_w->getDamage());
	if (e->getHP() <= 0)
		delete e;
}

std::ostream			&operator<<(std::ostream &os, Character const &c)
{
	os << c.getName()
	   << " has "
	   << c.getAP()
	   << " and ";
	if (c.getW())
	{
		os << "wields a "
		   << c.getW()->getName();
	}
	else
		os << "is unarmed";
	os << std::endl;
	return (os);
}
