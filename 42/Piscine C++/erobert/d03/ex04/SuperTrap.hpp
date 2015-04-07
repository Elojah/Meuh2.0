// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 15:16:37 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 15:55:48 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap:
	public FragTrap,
	public NinjaTrap
{
public:
	SuperTrap(void);
	SuperTrap(SuperTrap const &sT);
	SuperTrap(std::string const &name);
	~SuperTrap(void);

	SuperTrap		&operator=(SuperTrap const &sT);

	void			ninjaShoebox(SuperTrap &sT);
};

#endif
