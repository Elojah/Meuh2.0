// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/21 19:42:24 by erobert           #+#    #+#             //
//   Updated: 2015/03/26 14:10:54 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Polynomial.hpp"

int				main(int ac, char **av)
{
	Lexer		l;
	Parser		p;
	Polynomial	poly;

	if (ac != 2)
		std::cerr << av[0] << " equation" << std::endl;
	else
	{
		l.tokenize(av[1]);
		p.parse(l.tokens());
		if (p.good())
			poly.solve(p.vector());
		else
			std::cerr << av[0] << " equation" << std::endl;
	}
	return (0);
}
