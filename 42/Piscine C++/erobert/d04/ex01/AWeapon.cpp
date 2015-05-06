// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 13:25:40 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 15:39:29 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AWeapon.hpp"

AWeapon::AWeapon(void):
	_name("?"),
	_apcost(0),
	_damage(0)
{
}
AWeapon::AWeapon(AWeapon const &aW)
{
	*this = aW;
}
AWeapon::AWeapon(std::string const &name, int apcost, int damage):
	_name(name),
	_apcost(apcost),
	_damage(damage)
{
}
AWeapon::~AWeapon(void)
{
}

AWeapon				&AWeapon::operator=(AWeapon const &aW)
{
	if (this != &aW)
	{
		_name = aW.getName();
		_apcost = aW.getAPCost();
		_damage = aW.getDamage();
	}
	return (*this);
}

std::string const	&AWeapon::getName(void) const
{
	return (_name);
}
int					AWeapon::getAPCost(void) const
{
	return (_apcost);
}
int					AWeapon::getDamage(void) const
{
	return (_damage);
}
