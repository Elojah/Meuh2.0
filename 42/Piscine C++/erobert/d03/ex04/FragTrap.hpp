// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 09:23:47 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 15:52:41 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(FragTrap const &fT);
	FragTrap(std::string const &name);
	~FragTrap(void);

	FragTrap		&operator=(FragTrap const &fT);

    typedef struct	s_atk
	{
		std::string	name;
		std::string	quote;
		void		(ClapTrap::*atk)(std::string const &target);
	}				t_atk;

	void			vaulthunter_dot_exe(std::string const &target);
};

#endif
