// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.cpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 14:44:34 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 16:28:53 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
	Form("Robotomy Request", 72, 45),
	_target(target)
{
}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

std::string const		&RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void					RobotomyRequestForm::action(void) const
{
	std::cout << "* drrrrrrrrrrrrrrr *" << std::endl;
	std::srand(clock());
	if (std::rand() % 2)
	{
		std::cout << _target 
				  << " has been robotomized successfully."
				  << std::endl;
	}
}
