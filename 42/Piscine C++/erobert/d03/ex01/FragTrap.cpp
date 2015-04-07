// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 09:42:55 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 14:39:53 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"

FragTrap::FragTrap(void):
	_hitPts(100),
	_hitPtsMax(100),
	_energPts(100),
	_energPtsMax(100),
	_lvl(1),
	_meleeDmg(30),
	_rangedDmg(20),
	_armor(5)
{
	_name = "Stupid";
	std::cout << "FR4G-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
FragTrap::FragTrap(FragTrap const &fT)
{
	*this = fT;
	std::cout << "FR4G-TP "
			  << _name
			  << " cloned"
			  << std::endl;
}
FragTrap::FragTrap(std::string const &name):
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
	std::cout << "FR4G-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
FragTrap::~FragTrap(void)
{
	std::cout << "<"
			  << _name
			  << "> Noooooooo.."
			  << std::endl;
	std::cout << "FR4G-TP "
			  << _name
			  << " destructed"
			  << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &fT)
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

void		FragTrap::setName(std::string const &name)
{
	_name = name;
}
std::string	FragTrap::getName(void) const
{
	return (_name);
}
size_t		FragTrap::getHitPts(void) const
{
	return (_hitPts);
}
size_t		FragTrap::getHitPtsMax(void) const
{
	return (_hitPtsMax);
}
size_t		FragTrap::getEnergPts(void) const
{
	return (_energPts);
}
size_t		FragTrap::getEnergPtsMax(void) const
{
	return (_energPtsMax);
}
size_t		FragTrap::getLvl(void) const
{
	return (_lvl);
}
size_t		FragTrap::getMeleeDmg(void) const
{
	return (_meleeDmg);
}
size_t		FragTrap::getRangedDmg(void) const
{
	return (_rangedDmg);
}
size_t		FragTrap::getArmor(void) const
{
	return (_armor);
}

void		FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP "
			  << _name
			  << " hits "
			  << target
			  << " with his bare hands, causing "
			  << _meleeDmg 
			  << " points of damage"
			  << std::endl;
}
void		FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP "
			  << _name
			  << " hits "
			  << target
			  << " at range, causing "
			  << _rangedDmg 
			  << " points of damage"
			  << std::endl;
}
void		FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP "
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
void		FragTrap::beRepaired(unsigned int amount)
{
	_hitPts += amount;
	if (_hitPts > _hitPtsMax)
		_hitPts = _hitPtsMax;
	std::cout << "FR4G-TP "
			  << _name
			  << " has been repaired"
			  << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	static int	rand(time(0));
	int			i(0);
	t_atk		tab[5] = {
		{
			"melee0",
			"Die mother fucker, die!",
			&FragTrap::meleeAttack
		},
		{
			"melee1",
			"Bitch, be cool!",
			&FragTrap::meleeAttack
		},
		{
			"ranged0",
			"I love the smell of napalm in the morning.",
			&FragTrap::rangedAttack
		},
		{
			"ranged1",
			"Seven-six-two millimeter. Full metal jacket.",
			&FragTrap::rangedAttack
		},
		{
			"ranged2",
			"Any time of the day is a good time for pie.",
			&FragTrap::rangedAttack
		},
	};
	void		(FragTrap::*atk)(std::string const &target);

	if (_energPts < 25)
	{
		std::cout << "FR4G-TP "
				  << _name
				  << " is tired"
				  << std::endl;
		return ;
	}
	_energPts -= 25;
	std::srand(rand);
	i = std::rand() % 5;
	std::cout << "<"
			  << _name
			  << "> "
			  << tab[i].quote
			  << std::endl;
	if (rand < 700)
		rand += 39;
	else
		rand %= 31;
	atk = tab[i].atk;
	(this->*atk)(target);
}
