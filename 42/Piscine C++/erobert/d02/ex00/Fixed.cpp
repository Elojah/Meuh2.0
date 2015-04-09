// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 10:34:39 by erobert           #+#    #+#             //
//   Updated: 2015/01/07 11:24:32 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"

Fixed::Fixed(void):
	_fpv(0),
	_nfb(8)
{
	std::cout << "Default constructor called"
			  << std::endl;
}
Fixed::Fixed(Fixed const &obj):
	_nfb(8)
{
	std::cout << "Copy constructor called"
			  << std::endl;
	*this = obj;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called"
			  << std::endl;
	return ;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called"
			  << std::endl;
	_fpv = raw;
}
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called"
			  << std::endl;
	return (_fpv);
}

Fixed	&Fixed::operator=(Fixed const &obj)
{
	std::cout << "Assignation operator called"
			  << std::endl;
	if (this != &obj)
		_fpv = obj.getRawBits();
	return (*this);
}
