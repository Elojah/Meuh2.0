// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 13:19:27 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 16:29:02 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
	std::string const	_target;

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &sCF);

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &sCF);
public:
	ShrubberyCreationForm(std::string const &target);
	virtual ~ShrubberyCreationForm(void);

	std::string const		&getTarget(void) const;

	virtual void			action(void) const;
};

#endif
