// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 10:53:24 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 18:22:10 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "Officeblock.hpp"

int				main(void)
{
	OfficeBlock	o;
//	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	Intern		idiotOne;
	Bureaucrat	hermes("Hermes Conrad", 37);
	Bureaucrat	bob("Bobby Bobson", 123);
	OfficeBlock	ob(&bob, &hermes, &idiotOne);

	o.setIntern(&idiotOne);
	o.doBureaucracy("Help", "Help");
	o.setSigner(&bob);
	o.setExecutor(&hermes);
	o.doBureaucracy("Help", "Help");
	o.doBureaucracy("Shrubbery Creation", "help");
	ob.doBureaucracy("Presidential Pardon", "help");
	return (0);
}
