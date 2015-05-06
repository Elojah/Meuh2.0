// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 13:30:51 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 14:26:23 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):
	ClapTrap()
{
	_name = "Idiot";
	_hitPts = 100;
	_hitPtsMax = 100;
	_energPts = 100;
	_energPtsMax = 100;
	_lvl = 1;
	_meleeDmg = 30;
	_rangedDmg = 20;
	_armor = 5;
	std::cout << "SC4V-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const &sT):
	ClapTrap()
{
	*this = sT;
	std::cout << "SC4V-TP "
			  << _name
			  << " cloned"
			  << std::endl;
}
ScavTrap::ScavTrap(std::string const &name):
	ClapTrap()
{
	_name = name;
	_hitPts = 100;
	_hitPtsMax = 100;
	_energPts = 100;
	_energPtsMax = 100;
	_lvl = 1;
	_meleeDmg = 30;
	_rangedDmg = 20;
	_armor = 5;
	std::cout << "SC4V-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
ScavTrap::~ScavTrap(void)
{
	std::cout << "<"
			  << _name
			  << "> Noooooooo.."
			  << std::endl;
	std::cout << "SC4V-TP "
			  << _name
			  << " destructed"
			  << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &sT)
{
	if (this != &sT)
	{
		_name = sT.getName();
		_hitPts = sT.getHitPts();
		_hitPtsMax = sT.getHitPts();
		_energPts = sT.getEnergPts();
		_energPtsMax = sT.getEnergPts();
		_lvl = sT.getLvl();
		_meleeDmg = sT.getMeleeDmg();
		_rangedDmg = sT.getRangedDmg();
		_armor = sT.getArmor();
	}
	return (*this);
}

void		ScavTrap::challengeNewcomer(void)
{
	static int	rand(time(0));
	std::string	tab[3] = {
		"Can you jump?",
		"Can you run?",
		"Can you die?",
	};
	std::srand(rand);
	std::cout << tab[std::rand() % 3]
			  << std::endl;
	if (rand < 700)
		rand += 39;
	else
		rand %= 31;
}
