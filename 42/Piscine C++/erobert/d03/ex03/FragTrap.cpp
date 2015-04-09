// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 09:42:55 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 14:41:02 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"

FragTrap::FragTrap(void):
	ClapTrap()
{
	_name = "Stupid";
	_hitPts = 100;
	_hitPtsMax = 100;
	_energPts = 100;
	_energPtsMax = 100;
	_lvl = 1;
	_meleeDmg = 30;
	_rangedDmg = 20;
	_armor = 5;
	std::cout << "FR4G-TP "
			  << _name
			  << " constructed"
			  << std::endl;
}
FragTrap::FragTrap(FragTrap const &fT):
	ClapTrap()
{
	*this = fT;
	std::cout << "FR4G-TP "
			  << _name
			  << " cloned"
			  << std::endl;
}
FragTrap::FragTrap(std::string const &name):
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
