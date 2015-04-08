// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ship.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 13:52:24 by erobert           #+#    #+#             //
/*   Updated: 2015/01/12 08:32:31 by rbobillo         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Ship.hpp"

Ship::Ship(void):
	_type("Ship"),
	_cHP(100),
	_mHP(100),
	_weapon(0)
{
	_size[0] = 1;
	_size[1] = 1;
	_pos[0] = 0;
	_pos[1] = 1;
//	std::cout << "Ship created" << std::endl;
}
Ship::Ship(Ship const &s)
{
	*this = s;
//	std::cout << "Ship created" << std::endl;
}
Ship::Ship(std::string const &type, int const size[2],
		   int const pos[2], int cHP, int mHP):
	_type(type),
	_cHP(cHP),
	_mHP(mHP),
	_weapon(0)
{
	_size[0] = size[0];
	_size[1] = size[1];
	_pos[0] = pos[0];
	_pos[1] = pos[1];
//	std::cout << "Ship created" << std::endl;
}
Ship::~Ship(void)
{
//	std::cout << "Ship destroyed" << std::endl;
}

Ship				&Ship::operator=(Ship const &s)
{
	if (this != &s)
	{
		_type = s.getType();
		_size[0] = s.getSize()[1];
		_size[1] = s.getSize()[1];
		_pos[0] = s.getPos()[0];
		_pos[1] = s.getPos()[1];
		_cHP = s.getCHP();
		_mHP = s.getMHP();
		_weapon = s.getWeapon();
	}
	return (*this);
}
Ship				&Ship::operator=(AWeapon *w)
{
	_weapon = w;
	return (*this);
}
Ship				&Ship::operator+=(int const &i)
{
	_cHP += i;
	if (_cHP > _mHP)
		_cHP = _mHP;
	return (*this);
}
Ship				&Ship::operator-=(int const &i)
{
	_cHP -= i;
	if (_cHP < 0)
	{
		_cHP = 0;
//		std::cout << _type << " exploded" << std::endl;
	}
	return (*this);
}
Ship				&Ship::operator+=(char const xy)
{
	if (xy == 'x')
		_pos[0]++;
	else
		_pos[1]++;
	return (*this);
}
Ship				&Ship::operator-=(char const xy)
{
	if (xy == 'x')
		_pos[0]--;
	else
		_pos[1]--;
	return (*this);
}

std::string const	&Ship::getType(void) const
{
	return (_type);
}
int const			*Ship::getSize(void) const
{
	return (_size);
}
int const			*Ship::getPos(void) const
{
	return (_pos);
}
int					Ship::getCHP(void) const
{
	return (_cHP);
}
int					Ship::getMHP(void) const
{
	return (_mHP);
}
AWeapon				*Ship::getWeapon(void) const
{
	return (_weapon);
}

bool				Ship::fire(void) const
{
//	static int		i(0);

	if (!_weapon)
		return (false);
/*	if (i)
	{
		i--;
		return (false);
		}*/
//	i = _weapon->getAPCost();
	_weapon->attack();
	return (true);
}
void				Ship::retriveSpaceObject(t_spaceObject &sO) const
{
	sO.type = NPC;
	sO.size[0] = _size[0];
	sO.size[1] = _size[1];
	sO.pos[0] = _pos[0];
	sO.pos[1] = _pos[1];
}

std::ostream		&operator<<(std::ostream &os, Ship const &s)
{
	os << s.getType() << " "
	   << s.getSize()[0] << "x"<< s.getSize()[1]
	   << " in " << s.getPos()[0] << ":" << s.getPos()[1]
	   << ", status " << s.getCHP() << "/" << s.getMHP();
	if (s.getWeapon() != 0)
		os << " armed with a " << s.getWeapon()->getName();
	return (os);
}
