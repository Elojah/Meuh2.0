// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 10:26:15 by erobert           #+#    #+#             //
//   Updated: 2015/01/07 15:08:16 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &obj);
	Fixed(int const value);
	Fixed(float const value);
	~Fixed(void);

	Fixed			&operator=(Fixed const &obj);

	bool			operator>(Fixed const &obj);
	bool			operator<(Fixed const &obj);
	bool			operator>=(Fixed const &obj);
	bool			operator<=(Fixed const &obj);
	bool			operator==(Fixed const &obj);
	bool			operator!=(Fixed const &obj);

	Fixed			operator+(Fixed const &obj);
	Fixed			operator-(Fixed const &obj);
	Fixed			operator*(Fixed const &obj);
	Fixed			operator/(Fixed const &obj);

	Fixed			operator++(int);
	Fixed			&operator++(void);
	Fixed			operator--(int);
	Fixed			&operator--(void);

	void			setRawBits(int const raw);
	int				getRawBits(void) const;

	int				toInt(void) const;
	float			toFloat(void) const;

	static Fixed	&min(Fixed const &a, Fixed const &b);
	static Fixed	&max(Fixed const &a, Fixed const &b);

private:
	int			_fpv;
	int const	_nfb;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &obj);

#endif
