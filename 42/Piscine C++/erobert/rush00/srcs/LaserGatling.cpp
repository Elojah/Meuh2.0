// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   LaserGatling.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:25:35 by erobert           #+#    #+#             //
/*   Updated: 2015/01/12 08:31:10 by rbobillo         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "LaserGatling.hpp"

LaserGatling::LaserGatling(void):
	AWeapon("fucking Laser Gatling", 1, 7)
{
}
LaserGatling::LaserGatling(LaserGatling const &lG):
	AWeapon(lG)
{
}
LaserGatling::~LaserGatling(void)
{
}

LaserGatling		&LaserGatling::operator=(LaserGatling const &lG)
{
	if (this != &lG)
	{
		_name = lG.getName();
		_apcost = lG.getAPCost();
		_damage = lG.getDamage();
	}
	return (*this);
}

void				LaserGatling::attack(void) const
{
//	std::cout << "* ttrrrrrr *"
//			  << std::endl;
}
