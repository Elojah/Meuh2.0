// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 09:42:55 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 15:03:27 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_hitPts(100),
	_hitPtsMax(100),
	_energPts(100),
	_energPtsMax(100),
	_lvl(1),
	_meleeDmg(30),
	_rangedDmg(20),
	_armor(5)
{
	_name = "Dumb";
	std::cout << "CL4P-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &cT)
{
	*this = cT;
	std::cout << "CL4P-TP "
			  << _name
			  << " cloned"
			  << std::endl;
}
ClapTrap::ClapTrap(std::string const &name):
	_name(name),
	_hitPts(100),
	_hitPtsMax(100),
	_energPts(100),
	_energPtsMax(100),
	_lvl(1),
	_meleeDmg(30),
	_rangedDmg(20),
	_armor(5)
{
	std::cout << "CL4P-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
ClapTrap::~ClapTrap(void)
{
	std::cout << "CL4P-TP "
			  << _name
			  << " destructed"
			  << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &cT)
{
	if (this != &cT)
	{
		_name = cT.getName();
		_hitPts = cT.getHitPts();
		_hitPtsMax = cT.getHitPts();
		_energPts = cT.getEnergPts();
		_energPtsMax = cT.getEnergPts();
		_lvl = cT.getLvl();
		_meleeDmg = cT.getMeleeDmg();
		_rangedDmg = cT.getRangedDmg();
		_armor = cT.getArmor();
	}
	return (*this);
}

void		ClapTrap::setName(std::string const &name)
{
	_name = name;
}
std::string	ClapTrap::getName(void) const
{
	return (_name);
}
size_t		ClapTrap::getHitPts(void) const
{
	return (_hitPts);
}
size_t		ClapTrap::getHitPtsMax(void) const
{
	return (_hitPtsMax);
}
size_t		ClapTrap::getEnergPts(void) const
{
	return (_energPts);
}
size_t		ClapTrap::getEnergPtsMax(void) const
{
	return (_energPtsMax);
}
size_t		ClapTrap::getLvl(void) const
{
	return (_lvl);
}
size_t		ClapTrap::getMeleeDmg(void) const
{
	return (_meleeDmg);
}
size_t		ClapTrap::getRangedDmg(void) const
{
	return (_rangedDmg);
}
size_t		ClapTrap::getArmor(void) const
{
	return (_armor);
}

void		ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "CL4P-TP "
			  << _name
			  << " hits "
			  << target
			  << " with his bare hands, causing "
			  << _meleeDmg
			  << " points of damage"
			  << std::endl;
}
void		ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "CL4P-TP "
			  << _name
			  << " hits "
			  << target
			  << " at range, causing "
			  << _rangedDmg
			  << " points of damage"
			  << std::endl;
}
void		ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "CL4P-TP "
			  << _name;
	if (_armor >= amount)
		std::cout << " taked no damage";
	else if (_hitPts + _armor <= amount)
		std::cout << " has been killed";
	else
	{
		_hitPts -= amount - _armor;
		std::cout << " taked "
				  << (amount - _armor)
				  << " points of damage";
	}
	std::cout << std::endl;
}
void		ClapTrap::beRepaired(unsigned int amount)
{
	_hitPts += amount;
	if (_hitPts > _hitPtsMax)
		_hitPts = _hitPtsMax;
	std::cout << "CL4P-TP "
			  << _name
			  << " has been repaired"
			  << std::endl;
}
