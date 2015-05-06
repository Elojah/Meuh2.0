// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaCannon.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:22:55 by erobert           #+#    #+#             //
/*   Updated: 2015/01/12 08:31:22 by rbobillo         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "PlasmaCannon.hpp"

PlasmaCannon::PlasmaCannon(void):
	AWeapon("big fat twin Plasma Cannon", 5, 21)
{
}
PlasmaCannon::PlasmaCannon(PlasmaCannon const &pC):
	AWeapon(pC)
{
}
PlasmaCannon::~PlasmaCannon(void)
{
}

PlasmaCannon		&PlasmaCannon::operator=(PlasmaCannon const &pC)
{
	if (this != &pC)
	{
		_name = pC.getName();
		_apcost = pC.getAPCost();
		_damage = pC.getDamage();
	}
	return (*this);
}

void				PlasmaCannon::attack(void) const
{
//	std::cout << "* zooooohm *"
//			  << std::endl;
}
