// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 10:26:15 by erobert           #+#    #+#             //
//   Updated: 2015/01/07 11:17:14 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &obj);
	~Fixed(void);

	void		setRawBits(int const raw);
	int			getRawBits(void) const;

	Fixed		&operator=(Fixed const &obj);

private:
	int			_fpv;
	int const	_nfb;
};

#endif
