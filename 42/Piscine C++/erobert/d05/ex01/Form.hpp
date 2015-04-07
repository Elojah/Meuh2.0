// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 11:53:49 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 13:21:41 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form
{
private:
	std::string	const			_name;
	int const					_sGrade;
	int const					_eGrade;
	bool						_signed;
	
	Form(void);
	Form(Form const &f);
	
	Form				&operator=(Form const &f);
public:
	Form(std::string const &name, int const sGrade, int const eGrade);
	~Form(void);
	
	std::string const			&getName(void) const;
	int							getSGrade(void) const;
	int							getEGrade(void) const;
	bool						getSigned(void) const;
	
	void						beSigned(Bureaucrat const &b);
	
	class GradeTooHighException: public std::exception
	{
	private:
		GradeTooHighException	&operator=(GradeTooHighException const &gTHE);
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const &gTHE);
		virtual ~GradeTooHighException(void) throw();
		
		virtual char const		*what(void) const throw();
	};
	class GradeTooLowException: public std::exception
	{
	private:
		GradeTooLowException	&operator=(GradeTooLowException const &gTLE);
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const &gTLE);
		virtual ~GradeTooLowException(void) throw();
		
		virtual char const		*what(void) const throw();
	};
};

std::ostream					&operator<<(std::ostream &os, Form &f);	

#endif
