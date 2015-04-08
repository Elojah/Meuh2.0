// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 14:36:34 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 15:45:02 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap: virtual public ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(NinjaTrap const &nT);
	NinjaTrap(std::string const &name);
	~NinjaTrap(void);

	NinjaTrap		&operator=(NinjaTrap const &nT);

	void			ninjaShoebox(ClapTrap &cT);
	void			ninjaShoebox(FragTrap &cT);
	void			ninjaShoebox(ScavTrap &cT);
	void			ninjaShoebox(NinjaTrap &cT);
};

#endif
