// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 15:25:06 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 16:08:44 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void):
	ClapTrap(),
	FragTrap(),
	NinjaTrap()
{
	_name = "T-1000";
	_hitPts = 100;
	_hitPtsMax = 100;
	_energPts = 120;
	_energPtsMax = 120;
	_lvl = 1;
	_meleeDmg = 60;
	_rangedDmg = 20;
	_armor = 5;
	std::cout << "SUP3R-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
SuperTrap::SuperTrap(SuperTrap const &sT):
	ClapTrap(),
	FragTrap(),
	NinjaTrap()
{
	*this = sT;
	std::cout << "SUP3R-TP "
			  << _name
			  << " cloned"
			  << std::endl;
}
SuperTrap::SuperTrap(std::string const &name):
	FragTrap(),
	NinjaTrap()
{
	_name = name;
	_hitPts = 100;
	_hitPtsMax = 100;
	_energPts = 120;
	_energPtsMax = 120;
	_lvl = 1;
	_meleeDmg = 60;
	_rangedDmg = 20;
	_armor = 5;
	std::cout << "SUP3R-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
SuperTrap::~SuperTrap(void)
{
	std::cout << "<"
			  << _name
			  << "> I'll be back."
			  << std::endl;
	std::cout << "SUP3R-TP "
			  << _name
			  << " destructed"
			  << std::endl;
}

SuperTrap	&SuperTrap::operator=(SuperTrap const &fT)
{
	if (this != &fT)
	{
		_name = fT.getName();
		_hitPts = fT.getHitPts();
		_hitPtsMax = fT.getHitPts();
		_energPts = fT.getEnergPts();
		_energPtsMax = fT.getEnergPts();
		_lvl = fT.getLvl();
		_meleeDmg = fT.getMeleeDmg();
		_rangedDmg = fT.getRangedDmg();
		_armor = fT.getArmor();
	}
	return (*this);
}

void		SuperTrap::ninjaShoebox(SuperTrap &sT)
{
	sT.takeDamage(1000);
	std::cout << "<"
			  << _name
			  << "> "
			  << "Aah… Monde de merde."
			  << std::endl;
}
