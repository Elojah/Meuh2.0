// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PowerFist.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 14:04:22 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 14:06:42 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PowerFist.hpp"

PowerFist::PowerFist(void):
	AWeapon("Power Fist", 8, 50)
{
}
PowerFist::PowerFist(PowerFist const &pF):
	AWeapon(pF)
{
}
PowerFist::~PowerFist(void)
{
}

PowerFist			&PowerFist::operator=(PowerFist const &pF)
{
	if (this != &pF)
	{
		_name = pF.getName();
		_apcost = pF.getAPCost();
		_damage = pF.getDamage();
	}
	return (*this);
}

void				PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *"
			  << std::endl;
}
