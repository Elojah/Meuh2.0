// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 10:48:34 by erobert           #+#    #+#             //
//   Updated: 2015/01/07 18:39:31 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"

static Fixed	doOpp(Fixed &a, Fixed &b, char opp)	
{
	a = getFixed(expr.data());
	opp = str.find("+");
	b = getFixed(expr.data() + opp);
	std::cout << doOpp(a, b, '+') << std::endl;

	if (opp == '+')
		return (a + b);
	else if (opp == '-')
		return (a + b);
	else if (opp == '*')
		return (a + b);
	else
		return (a + b);
}

static Fixed	getFixed(char const *str)
{
	Fixed	a((float )std::atof(str));

	return (a);
}

static int		ftEval(char *av)
{
	std::string	str(av);
	size_t		first, last, opp;
	std::string	expr;
	Fixed		a, b;

	first = str.find("(") + 1;
	if (
	last = str.find(")");
	expr = str.substr(first, last - first);

	return (0);
}

int				main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (ftEval(av[1]))
		std::cout << "Expression non valide" << std::endl;
	return (0);
}
