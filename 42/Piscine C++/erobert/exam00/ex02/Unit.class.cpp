// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Unit.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 18:52:57 by exam              #+#    #+#             //
//   Updated: 2015/01/09 20:22:46 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Unit.class.hpp"

int					Unit::_nb = 0;

Unit::Unit(void):
	_index(_nb),
	_type("Unit"),
	_x(0),
	_y(0),
	_dam(0),
	_cHP(0),
	_mHP(0)
{
	std::cout << "[CREATED] Unit #" << _index << ": " << _type
			  << " in " << _x << "/" << _y << " with " << _cHP << "/" << _mHP
			  << "HP damaging at " << _dam << "." << std::endl;
	_nb++;
}
Unit::Unit(std::string const &type, int const x, int const y, 
		   int const dam, int const cHP, int const mHP):
	_index(_nb),
	_type(type),
	_x(x),
	_y(y),
	_dam(dam),
	_cHP(cHP),
	_mHP(mHP)
{
	std::cout << "[CREATED] Unit #" << _index << ": " << _type
			  << " in " << _x << "/" << _y << " with " << _cHP << "/" << _mHP
			  << "HP damaging at " << _dam << "." << std::endl;
	_nb++;
}
Unit::Unit(Unit const &u):
	_index(_nb)
{
	*this = u;
	std::cout << "[CREATED] Unit #" << _index << ": " << _type
			  << " in " << _x << "/" << _y << " with " << _cHP << "/" << _mHP
			  << "HP damaging at " << _dam << "." << std::endl;
	_nb++;
}
Unit::~Unit(void)
{
	std::cout << "[DESTRUCTED] Unit #" << _index << ": " << _type
			  << " in " << _x << "/" << _y << " with " << _cHP << "/" << _mHP
			  << "HP damaging at " << _dam << "." << std::endl;
}

Unit		&Unit::operator=(Unit const &u)
{
	if (this != &u)
	{
		_type = u.getType();
		_x = u.getX();
		_y = u.getY();
		_dam = u.getDam();
		_cHP = u.getCHP();
		_mHP = u.getMHP();
	}
	return (*this);
}
Unit		&Unit::operator+=(int const i)
{
	_cHP += i;
	if (_cHP > _mHP)
		_cHP = _mHP;
	return (*this);
}
Unit		&Unit::operator-=(int const i)
{
	if (_cHP <= i)
		die();
	else
		_cHP -= i;
	return (*this);
}

int					Unit::getIndex(void) const
{
	return (_index);
}
std::string	const	&Unit::getType(void) const
{
	return (_type);
}
int					Unit::getX(void) const
{
	return (_x);
}
int					Unit::getY(void) const
{
	return (_y);
}
int					Unit::getDam(void) const
{
	return (_dam);
}
int					Unit::getCHP(void) const
{
	return (_cHP);
}
int					Unit::getMHP(void) const
{
	return (_mHP);
}

void				Unit::die(void)
{
	_cHP = 0;
	std::cout << "Unit #" << _index << " (" << _type
			  << ") died." << std::endl;
}
void				Unit::move(int x, int y)
{
	std::cout << "Unit #" << _index << " (" << _type
			  << ") is moving from " << _x << "/" << _y
			  << " to " << x << "/" << y << "." << std::endl;
	_x = x;
	_y = y;
}
void				Unit::attack(Unit &target) const
{
	if (_cHP <= 0)
		return ;
	std::cout << "Unit #" << _index << " (" << _type
			  << ") damaged unit #" << target.getIndex() << " ("
			  << target.getType() << ")." << std::endl;
	target -= _dam;
}
std::ostream		&operator<<(std::ostream &os, Unit const &u)
{
	os << "Unit #" << u.getIndex() << ": " << u.getType()
	   << " in " << u.getX() << "/" << u.getY() << " with "
	   << u.getCHP() << "/" << u.getMHP()
	   << "HP damaging at " << u.getDam() << ".";
	return (os);
}
