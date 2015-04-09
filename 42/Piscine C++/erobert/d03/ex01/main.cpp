// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 10:16:08 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 13:52:55 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap	f1;
	FragTrap	f2("n2");
	FragTrap	f3("n3");
	int			i(0);
	ScavTrap	s1("n4");

	f1 = f3;
	std::cout << std::endl
			  << "Enter battle field"
			  << std::endl;
	while (i++ < 10)
		f2.vaulthunter_dot_exe(std::string("n3"));
	std::cout << std::endl
			  << "Leave battle field"
			  << std::endl;
	s1.challengeNewcomer();
	s1.challengeNewcomer();
	s1.challengeNewcomer();
	return (0);
}
