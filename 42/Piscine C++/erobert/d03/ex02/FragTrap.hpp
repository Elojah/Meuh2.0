// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 09:23:47 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 14:06:50 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(FragTrap const &fT);
	FragTrap(std::string const &name);
	~FragTrap(void);

	FragTrap		&operator=(FragTrap const &fT);

	void			vaulthunter_dot_exe(std::string const &target);
};

#endif
