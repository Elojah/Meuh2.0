// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 15:30:08 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 17:25:26 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
}
Intern::~Intern(void) {}

Form			*Intern::makeForm(std::string const &fN, std::string const &t)
{
	Form		*f;

	if (fN.compare("Robotomy Request") == 0)
		f = new RobotomyRequestForm(t);
	else if (fN.compare("Shrubbery Creation") == 0)
		f = new ShrubberyCreationForm(t);
	else if (fN.compare("Presidential Pardon") == 0)
		f = new PresidentialPardonForm(t);
	else
	{
		std::cout << "Intern couldn't find " << fN << "." << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << fN << "." << std::endl;
	return (f);
}
