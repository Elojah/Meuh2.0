// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 13:30:51 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 13:52:29 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):
	_hitPts(100),
	_hitPtsMax(100),
	_energPts(100),
	_energPtsMax(100),
	_lvl(1),
	_meleeDmg(30),
	_rangedDmg(20),
	_armor(5)
{
	_name = "Idiot";
	std::cout << "SC4V-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const &sT)
{
	*this = sT;
	std::cout << "SC4V-TP "
			  << _name
			  << " cloned"
			  << std::endl;
}
ScavTrap::ScavTrap(std::string const &name):
	_name(name),
	_hitPts(100),
	_hitPtsMax(100),
	_energPts(50),
	_energPtsMax(50),
	_lvl(1),
	_meleeDmg(20),
	_rangedDmg(15),
	_armor(3)
{
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

void		ScavTrap::setName(std::string const &name)
{
	_name = name;
}
std::string	ScavTrap::getName(void) const
{
	return (_name);
}
size_t		ScavTrap::getHitPts(void) const
{
	return (_hitPts);
}
size_t		ScavTrap::getHitPtsMax(void) const
{
	return (_hitPtsMax);
}
size_t		ScavTrap::getEnergPts(void) const
{
	return (_energPts);
}
size_t		ScavTrap::getEnergPtsMax(void) const
{
	return (_energPtsMax);
}
size_t		ScavTrap::getLvl(void) const
{
	return (_lvl);
}
size_t		ScavTrap::getMeleeDmg(void) const
{
	return (_meleeDmg);
}
size_t		ScavTrap::getRangedDmg(void) const
{
	return (_rangedDmg);
}
size_t		ScavTrap::getArmor(void) const
{
	return (_armor);
}

void		ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "SC4V-TP "
			  << _name
			  << " hits "
			  << target
			  << " with his bare hands, causing "
			  << _meleeDmg 
			  << " points of damage"
			  << std::endl;
}
void		ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "SC4V-TP "
			  << _name
			  << " hits "
			  << target
			  << " at range, causing "
			  << _rangedDmg 
			  << " points of damage"
			  << std::endl;
}
void		ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "SC4V-TP "
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
void		ScavTrap::beRepaired(unsigned int amount)
{
	_hitPts += amount;
	if (_hitPts > _hitPtsMax)
		_hitPts = _hitPtsMax;
	std::cout << "SC4V-TP "
			  << _name
			  << " has been repaired"
			  << std::endl;
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
	std::cout << "<"
			  << _name
			  << "> "
			  << tab[std::rand() % 3]
			  << std::endl;
	if (rand < 700)
		rand += 39;
	else
		rand %= 31;
}
