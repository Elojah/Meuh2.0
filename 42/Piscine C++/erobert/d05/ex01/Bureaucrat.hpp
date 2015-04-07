// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 10:39:03 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 13:07:31 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
private:
	std::string const			_name;
	int							_grade;

	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &b);

	Bureaucrat					&operator=(Bureaucrat const &b);
public:
	Bureaucrat(std::string const &name, int const grade);
	~Bureaucrat(void);

	Bureaucrat					&operator++(void);
	Bureaucrat					&operator--(void);

	std::string const			&getName(void) const;
	int							getGrade(void) const;

	void						signForm(bool s, std::string const &fName) const;

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

		virtual char const 		*what(void) const throw();
	};
};

std::ostream		&operator<<(std::ostream &os, Bureaucrat &b);

#endif 
