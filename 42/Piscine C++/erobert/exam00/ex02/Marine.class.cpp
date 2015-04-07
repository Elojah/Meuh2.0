// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Marine.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 20:30:50 by exam              #+#    #+#             //
//   Updated: 2015/01/09 21:22:59 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Marine.class.hpp"

Marine::Marine(void):
	Unit("Marine", 0, 0, 6, 40, 40)
{
	std::cout << "Unit #" << _index << ": You want a piece of me, boy ?"
			  << std::endl;
}
Marine::Marine(Marine const &m):
	Unit()
{
	*this = m;
	std::cout << "Unit #" << _index << ": You want a piece of me, boy ?"
			  << std::endl;
}
Marine::Marine(int const x, int const y):
	Unit("Marine", x, y, 6, 40, 40)
{
	std::cout << "Unit #" << _index << ": You want a piece of me, boy ?"
			  << std::endl;
}
Marine::~Marine(void)
{

}

Marine	&Marine::operator=(Marine const &m)
{
	if (this != &m)
	{
		_type = m.getType();
		_x = m.getX();
		_y = m.getY();
		_dam = m.getDam();
		_cHP = m.getCHP();
		_mHP = m.getMHP();
	}
	return (*this);
}

void	Marine::die(void)
{
	std::cout << "Unit #" << _index << " (" << _type
			  << ") died." << std::endl;
	_cHP = 0;
	std::cout << "Unit #" << _index << ": Aaaargh..." << std::endl;
}
void	Marine::move(int x, int y)
{
	std::cout << "Unit #" << _index << " (" << _type
			  << ") is moving from " << _x << "/" << _y
			  << " to " << x << "/" << y << "." << std::endl;
	std::cout << "Unit #" << _index << ": Rock'n'roll !!!" << std::endl;
	_x = x;
	_y = y;
}
void	Marine::stimpack(void)
{
	_dam *= 2;
	if (_cHP < 11 && _cHP > 0)
		_cHP = 1;
	else
		_cHP -= 10;
	std::cout << "Unit #" << _index << ": Ho yeah..." << std::endl;
}
