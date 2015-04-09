// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PresidentialPardonForm.hpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 14:33:16 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 16:29:18 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	std::string const	_target;

	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &pPF);

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &pPF);
public:
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm(void);

	std::string const	&getTarget(void) const;

	virtual void		action(void) const;
};

#endif
