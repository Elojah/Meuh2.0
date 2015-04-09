// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 12:07:54 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 16:51:31 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Form.hpp"

Form::Form(std::string const &name, int const sGrade, int const eGrade):
	_name(name),
	_sGrade(sGrade),
	_eGrade(eGrade),
	_signed(false)
{
	if (_sGrade < 1 || _eGrade < 1)
		throw GradeTooHighException();
	else if (_sGrade > 150 || _eGrade > 150)
		throw GradeTooLowException();
}
Form::~Form(void) {}

std::string const		&Form::getName(void) const
{
	return (_name);
}
int						Form::getSGrade(void) const
{
	return (_sGrade);
}

int						Form::getEGrade(void) const
{
	return (_eGrade);
}
bool					Form::getSigned(void) const
{
	return (_signed);
}

void					Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > _sGrade)
		throw GradeTooLowException();
	else
		_signed = true;
	b.signForm(_signed, _name);
}

Form::GradeTooHighException::GradeTooHighException(void) {}
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

char const				*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

Form::GradeTooLowException::GradeTooLowException(void) {}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

char const				*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream			&operator<<(std::ostream &os, Form &f)
{
	os << "Form " << f.getName()
	   << ", sign level " << f.getSGrade()
	   << ", execute level " << f.getEGrade();
	if (f.getSigned())
		os << ", signed.";
	else
		os << ", not signed.";
	return (os);
}
