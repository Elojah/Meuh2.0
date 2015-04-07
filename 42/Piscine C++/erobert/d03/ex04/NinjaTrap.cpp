// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 14:37:49 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 15:45:26 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void):
	ClapTrap()
{
	_name = "Loser";
	_hitPts = 60;
	_hitPtsMax = 60;
	_energPts = 120;
	_energPtsMax = 120;
	_lvl = 1;
	_meleeDmg = 60;
	_rangedDmg = 5;
	_armor = 0;
	std::cout << "NINJ4-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
NinjaTrap::NinjaTrap(NinjaTrap const &nT):
	ClapTrap()
{
	*this = nT;
	std::cout << "NINJ4-TP "
			  << _name
			  << " cloned"
			  << std::endl;
}
NinjaTrap::NinjaTrap(std::string const &name):
	ClapTrap()
{
	_name = name;
	_hitPts = 60;
	_hitPtsMax = 60;
	_energPts = 120;
	_energPtsMax = 120;
	_lvl = 1;
	_meleeDmg = 60;
	_rangedDmg = 5;
	_armor = 0;
	std::cout << "NINJ4-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
NinjaTrap::~NinjaTrap(void)
{
	std::cout << "<"
			  << _name
			  << "> Noooooooo.."
			  << std::endl;
	std::cout << "NINJ4-TP "
			  << _name
			  << " destructed"
			  << std::endl;
}

NinjaTrap	&NinjaTrap::operator=(NinjaTrap const &nT)
{
	if (this != &nT)
	{
		_name = nT.getName();
		_hitPts = nT.getHitPts();
		_hitPtsMax = nT.getHitPts();
		_energPts = nT.getEnergPts();
		_energPtsMax = nT.getEnergPts();
		_lvl = nT.getLvl();
		_meleeDmg = nT.getMeleeDmg();
		_rangedDmg = nT.getRangedDmg();
		_armor = nT.getArmor();
	}
	return (*this);
}

void		NinjaTrap::ninjaShoebox(ClapTrap &cT)
{
	std::cout << "<"
			  << _name
			  << "> "
			  << "I don't wanna kill anybody."
			  << " But if I gotta get out that door,"
			  << " and you're standing in my way,"
			  << " one way or the other, you're gettin' outta my way."
			  << std::endl;
	cT.takeDamage(5);
}
void		NinjaTrap::ninjaShoebox(FragTrap &fT)
{
	std::cout << "<"
			  << _name
			  << "> "
			  << "This is your life and it's ending one minute at a time."
			  << std::endl;
	fT.takeDamage(100);
}
void		NinjaTrap::ninjaShoebox(ScavTrap &sT)
{
	std::cout << "<"
			  << _name
			  << "> "
			  << "Hello. My name is Inigo Montoya."
			  << " You killed my father. Prepare to die."
			  << std::endl;
	sT.takeDamage(1138 + 3);
}
void		NinjaTrap::ninjaShoebox(NinjaTrap &nT)
{
	nT.takeDamage(1000);
	std::cout << "<"
			  << _name
			  << "> "
			  << "Aah… Monde de merde."
			  << std::endl;
}
