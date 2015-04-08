// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.hpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 14:41:40 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 16:28:46 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
	std::string const	_target;

	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &rRF);

	RobotomyRequestForm	&operator=(RobotomyRequestForm const &rRF);
public:
	RobotomyRequestForm(std::string const &target);
	virtual ~RobotomyRequestForm(void);

	std::string const	&getTarget(void) const;

	virtual void		action(void) const;
};

#endif
