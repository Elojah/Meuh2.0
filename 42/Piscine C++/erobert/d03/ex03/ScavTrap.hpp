// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 13:29:39 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 14:06:17 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(ScavTrap const &sT);
	ScavTrap(std::string const &name);
	~ScavTrap(void);

	ScavTrap		&operator=(ScavTrap const &sT);

	void			challengeNewcomer(void);
};

#endif
