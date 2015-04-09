// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 11:35:28 by erobert           #+#    #+#             //
//   Updated: 2015/01/15 18:51:38 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Span.hpp"

int			main(void)
{
	Span	sp = Span(200005);
	int		i(0);

	try {std::cout << sp.shortestSpan() << std::endl;}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	sp.addNumber(5);
	try {std::cout << sp.longestSpan() << std::endl;}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << "-----------------" << std::endl;
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "-----------------" << std::endl;
	while (i < 200000)
		sp.addNumber(i++ + 20);
	try {sp.addNumber(11);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}
