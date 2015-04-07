// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 10:34:39 by erobert           #+#    #+#             //
//   Updated: 2015/01/07 12:44:34 by erobert          ###   ########.fr       //
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
Fixed::Fixed(int const value):
	_nfb(8)
{
	std::cout << "Int constructor called"
			  << std::endl;
	_fpv = value << _nfb;
}
Fixed::Fixed(float const value):
	_nfb(8)
{
	std::cout << "Float constructor called"
			  << std::endl;
	_fpv = (int )(roundf(value * (1 << _nfb)));
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called"
			  << std::endl;
	return ;
}

Fixed			&Fixed::operator=(Fixed const &obj)
{
	std::cout << "Assignation operator called"
			  << std::endl;
	if (this != &obj)
		_fpv = obj.getRawBits();
	return (*this);
}

void			Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called"
			  << std::endl;
	_fpv = raw;
}
int				Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called"
			  << std::endl;
	return (_fpv);
}

int				Fixed::toInt(void) const
{
	return ((_fpv) >> _nfb);
}
float			Fixed::toFloat(void) const
{
	return (((float )(_fpv)) / (1 << _nfb));
}

std::ostream	&operator<<(std::ostream &os, Fixed const &obj)
{
	os << obj.toFloat();
	return (os);
}

