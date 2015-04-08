// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 10:58:23 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 16:56:54 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int const grade):
	_name(name),
	_grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}
Bureaucrat::~Bureaucrat(void) {}

Bureaucrat			&Bureaucrat::operator++(void)
{
	if (_grade < 2)
		throw GradeTooHighException();
	else
		_grade--;
	return (*this);
}
Bureaucrat			&Bureaucrat::operator--(void)
{
	if (_grade > 149)
		throw GradeTooLowException();
	else
		_grade++;
	return (*this);
}

std::string	const	&Bureaucrat::getName(void) const
{
	return (_name);
}
int					Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void				Bureaucrat::signForm(bool s, std::string const &fN) const
{
	if (s)
		std::cout << _name << " signs " << fN << std::endl;
	else
		std::cout << _name << " cannot sign " << fN << std::endl;
}
void				Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executes "
				  << form.getName() << "." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " can't execute "
				  << form.getName() << "." << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

char const			*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

char const			*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream			&operator<<(std::ostream &os, Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " 
	   << b.getGrade() << ".";
	return (os);
}
