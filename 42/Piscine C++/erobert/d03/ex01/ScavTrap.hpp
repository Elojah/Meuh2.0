// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 13:29:39 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 14:03:55 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class ScavTrap
{
private:
	std::string		_name;

	size_t			_hitPts;
	size_t			_hitPtsMax;
	size_t			_energPts;
	size_t			_energPtsMax;
	int				_lvl;
	int				_meleeDmg;
	int				_rangedDmg;
	size_t			_armor;

public:
	ScavTrap(void);
	ScavTrap(ScavTrap const &sT);
	ScavTrap(std::string const &name);
	~ScavTrap(void);

	ScavTrap		&operator=(ScavTrap const &sT);

	void			setName(std::string const &name);
	std::string		getName(void) const;
	size_t			getHitPts(void) const;
	size_t			getHitPtsMax(void) const;
	size_t			getEnergPts(void) const;
	size_t			getEnergPtsMax(void) const;
	size_t			getLvl(void) const;
	size_t			getMeleeDmg(void) const;
	size_t			getRangedDmg(void) const;
	size_t			getArmor(void) const;

	typedef struct	s_atk
	{
		std::string	name;
		std::string	quote;
		void		(ScavTrap::*atk)(std::string const &target);
	}				t_atk;

	void			meleeAttack(std::string const &target);
	void			rangedAttack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	void			challengeNewcomer(void);
};

#endif
