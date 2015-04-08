// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperMutant.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 14:26:51 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 14:34:48 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void):
	Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !"
			  << std::endl;
}
SuperMutant::SuperMutant(SuperMutant const &sM):
	Enemy(sM)
{
	std::cout << "Gaaah. Me want smash heads !"
			  << std::endl;
}
SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..."
			  << std::endl;
}

void		SuperMutant::takeDamage(int amount)
{
	_hp -= amount / 3;
}
