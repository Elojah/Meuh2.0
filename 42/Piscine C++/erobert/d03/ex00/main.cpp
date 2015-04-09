// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 10:16:08 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 14:47:42 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	f1;
	FragTrap	f2("n2");
	FragTrap	f3("n3");
	int			i(0);

	f1 = f3;
	std::cout << std::endl
			  << "Enter battle field"
			  << std::endl;
	while (i++ < 10)
		f2.vaulthunter_dot_exe(std::string("n3"));
	f3.beRepaired(150);
	f3.takeDamage(150);
	std::cout << std::endl
			  << "Leave battle field"
			  << std::endl;
	return (0);
}
