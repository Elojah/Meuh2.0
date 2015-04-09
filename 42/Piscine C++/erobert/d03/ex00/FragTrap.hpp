// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 09:23:47 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 12:38:52 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class FragTrap
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
	FragTrap(void);
	FragTrap(FragTrap const &fT);
	FragTrap(std::string const &name);
	~FragTrap(void);

	FragTrap		&operator=(FragTrap const &fT);

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
		void		(FragTrap::*atk)(std::string const &target);
	}				t_atk;

	void			meleeAttack(std::string const &target);
	void			rangedAttack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	void			vaulthunter_dot_exe(std::string const &target);
};

#endif
