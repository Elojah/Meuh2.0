// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 10:16:08 by erobert           #+#    #+#             //
//   Updated: 2015/01/08 16:02:30 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int		main(void)
{
	FragTrap	f1;
	FragTrap	f2("n2");
	FragTrap	f3("n3");
	int			i(0);
	ScavTrap	s1("n4");
	NinjaTrap	n1("n5");
	ClapTrap	c1("n6");
	SuperTrap	s2;

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
	n1.ninjaShoebox(c1);
	n1.ninjaShoebox(s1);
	n1.ninjaShoebox(f1);
	n1.ninjaShoebox(n1);
	s2.vaulthunter_dot_exe(std::string("s2"));
	s2.ninjaShoebox(s2);
	return (0);
}
