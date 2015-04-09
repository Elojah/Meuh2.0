// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 13:48:21 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 14:10:29 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class ClapTrap
{
protected:
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
    ClapTrap(void);
    ClapTrap(ClapTrap const &cT);
    ClapTrap(std::string const &name);
    ~ClapTrap(void);

    ClapTrap		&operator=(ClapTrap const &cT);

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
        void		(ClapTrap::*atk)(std::string const &target);
    }				t_atk;

    void			meleeAttack(std::string const &target);
    void			rangedAttack(std::string const &target);
    void			takeDamage(unsigned int amount);
    void			beRepaired(unsigned int amount);
};

#endif
