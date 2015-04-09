// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 10:34:39 by erobert           #+#    #+#             //
//   Updated: 2015/01/07 15:25:59 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"

Fixed::Fixed(void):
	_fpv(0),
	_nfb(8)
{
//	std::cout << "Default constructor called"
//			  << std::endl;
}
Fixed::Fixed(Fixed const &obj):
	_nfb(8)
{
//	std::cout << "Copy constructor called"
//			  << std::endl;
	*this = obj;
}
Fixed::Fixed(int const value):
	_nfb(8)
{
//	std::cout << "Int constructor called"
//			  << std::endl;
	_fpv = value << _nfb;
}
Fixed::Fixed(float const value):
	_nfb(8)
{
//	std::cout << "Float constructor called"
//			  << std::endl;
	_fpv = (int )(roundf(value * (1 << _nfb)));
}
Fixed::~Fixed(void)
{
//	std::cout << "Destructor called"
//			  << std::endl;
	return ;
}

Fixed			&Fixed::operator=(Fixed const &obj)
{
	if (this != &obj)
		_fpv = obj.getRawBits();
	return (*this);
}

bool			Fixed::operator>(Fixed const &obj)
{
	if (_fpv > obj.getRawBits())
		return (true);
	return (false);
}
bool			Fixed::operator<(Fixed const &obj)
{
	if (_fpv < obj.getRawBits())
		return (true);
	return (false);
}
bool			Fixed::operator>=(Fixed const &obj)
{
	if (_fpv >= obj.getRawBits())
		return (true);
	return (false);
}
bool			Fixed::operator<=(Fixed const &obj)
{
	if (_fpv <= obj.getRawBits())
		return (true);
	return (false);
}
bool			Fixed::operator==(Fixed const &obj)
{
	if (_fpv == obj.getRawBits())
		return (true);
	return (false);
}
bool			Fixed::operator!=(Fixed const &obj)
{
	if (_fpv != obj.getRawBits())
		return (true);
	return (false);
}

Fixed			Fixed::operator+(Fixed const &obj)
{
	int			fpv;
	Fixed		f;

	fpv = _fpv + obj.getRawBits();
	f.setRawBits(fpv);
	return (f);
}
Fixed			Fixed::operator-(Fixed const &obj)
{
	int			fpv;
	Fixed		f;

	fpv = _fpv - obj.getRawBits();
	f.setRawBits(fpv);
	return (f);
}
Fixed			Fixed::operator*(Fixed const &obj)
{
	int			tmp;
	int			fpv;
	Fixed		f;

	tmp = _fpv * obj.getRawBits();
	fpv = tmp + ((tmp & 1 << (8 - 1)) << 1);
	fpv >>= 8;
	f.setRawBits(fpv);
	return (f);
}
Fixed			Fixed::operator/(Fixed const &obj)
{
	int			fpv;
	Fixed		f;

	if (obj.getRawBits() == 0)
	{
		std::cerr << "Fixed point divide by 0" << std::endl;
		return (obj);
	}
	fpv = (_fpv << 8) / obj.getRawBits();
	f.setRawBits(fpv);
	return (f);
}

Fixed			Fixed::operator++(int)
{
	Fixed		f;

	f.setRawBits(_fpv++);
	return (f);
}
Fixed			&Fixed::operator++(void)
{
	_fpv++;
	return (*this);
}
Fixed			Fixed::operator--(int)
{
	Fixed		f;

	f.setRawBits(_fpv--);
	return (f);
}
Fixed			&Fixed::operator--(void)
{
	_fpv--;
	return (*this);
}

void			Fixed::setRawBits(int const raw)
{
	_fpv = raw;
}
int				Fixed::getRawBits(void) const
{
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

Fixed			&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return ((Fixed &)a);
	return ((Fixed &)b);
}
Fixed			&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return ((Fixed &)a);
	return ((Fixed &)b);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &obj)
{
	os << obj.toFloat();
	return (os);
}
