// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 10:26:15 by erobert           #+#    #+#             //
//   Updated: 2015/01/07 13:03:42 by erobert          ###   ########.fr       //
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

	Fixed		&operator=(Fixed const &obj);

	void		setRawBits(int const raw);
	int			getRawBits(void) const;

	int			toInt(void) const;
	float		toFloat(void) const;

private:
	int			_fpv;
	int const	_nfb;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &obj);

#endif
