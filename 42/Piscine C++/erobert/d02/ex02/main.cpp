// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 10:48:34 by erobert           #+#    #+#             //
//   Updated: 2015/01/07 15:26:24 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Fixed.hpp"

static void		ftCheckBool(Fixed &a, Fixed &abis)
{
	std::cout << "a > abis: " << (a > abis) << std::endl;
	std::cout << "a < abis: " << (a < abis) << std::endl;
	std::cout << "a >= abis: " << (a >= abis) << std::endl;
	std::cout << "a <= abis: " << (a <= abis) << std::endl;
	std::cout << "a == abis: " << (a == abis) << std::endl;
	std::cout << "a != abis: " << (a != abis) << std::endl;
}

static void		ftCheckOpp(Fixed &a, Fixed &abis)
{
	std::cout << "a + abis " << (a + abis) << std::endl;
	std::cout << "a - abis " << (a - abis) << std::endl;
}

int				main(void)
{
	Fixed		a(5.55f);
	Fixed		abis(a);
	Fixed		b(-3.4546f);
	Fixed const	c(Fixed(5.05f) * Fixed(2));
	Fixed		e(5.05f);
	Fixed		ebis(2);

	std::cout << "a = " << a << ", abis = " << abis << std::endl;
	ftCheckBool(a, abis);
	ftCheckOpp(a, abis);
	std::cout << std::endl;
	abis = b;
	std::cout << "a = " << a << ", abis = " << abis << std::endl;
	ftCheckBool(a, abis);
	std::cout << std::endl;
	ftCheckOpp(a, abis);
	a = Fixed(0);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << c << std::endl;
	e = e / ebis;
	std::cout << e << std::endl;
	std::cout << Fixed::max(a, c) << std::endl;
	std::cout << Fixed::min(a, a) << std::endl;
	return (0);
}
