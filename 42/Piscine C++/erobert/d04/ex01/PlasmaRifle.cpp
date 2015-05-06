// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 13:47:11 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 15:40:04 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void):
	AWeapon("Plasma Rifle", 5, 21)
{
}
PlasmaRifle::PlasmaRifle(PlasmaRifle const &pR):
	AWeapon(pR)
{
}
PlasmaRifle::~PlasmaRifle(void)
{
}

PlasmaRifle			&PlasmaRifle::operator=(PlasmaRifle const &pR)
{
	if (this != &pR)
	{
		_name = pR.getName();
		_apcost = pR.getAPCost();
		_damage = pR.getDamage();
	}
	return (*this);
}

void				PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *"
			  << std::endl;
}
