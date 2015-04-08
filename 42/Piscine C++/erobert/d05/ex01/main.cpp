// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 10:53:24 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 16:55:00 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "Form.hpp"

int			main(void)
{
	Bureaucrat	a("Jack", 148);
	Bureaucrat	b("Joe", 1);
	std::cout << "------------------------" << std::endl;
	try
	{
		Form		f("Form #0", 0, 150);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Form		g("Form #1", 2, 150);
	try
	{
		Form		h("Form #2", 5, 155);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;
	try
	{
		g.beSigned(a);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << g << std::endl;
	try
	{
		g.beSigned(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << g << std::endl;
	return (0);
}
