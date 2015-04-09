// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PresidentialPardonForm.cpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 14:36:27 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 16:29:24 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
	Form("Presidential Pardon", 25, 5),
	_target(target)
{
}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

std::string const		&PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void					PresidentialPardonForm::action(void) const
{
	std::cout << _target 
			  << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
