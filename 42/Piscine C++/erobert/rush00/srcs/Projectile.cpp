// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Projectile.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 11:51:17 by erobert           #+#    #+#             //
/*   Updated: 2015/01/12 08:32:06 by rbobillo         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Projectile.hpp"

Projectile::Projectile(void):
	_dir(0)
{
	_pos[0] = 0;
	_pos[1] = 0;
//	std::cout << "Projectile void created" << std::endl;
}
Projectile::Projectile(Projectile const &p)
{
	*this = p;
//	std::cout << "Projectile clone" << std::endl;
}
Projectile::Projectile(Ship const &s):
	_dir(-1)
{
	_pos[0] = 0;
	_pos[1] = 0;
	if (s.getWeapon())
	{
		_pos[0] = s.getPos()[0];
		_pos[1] = s.getPos()[1];
	}
//	std::cout << "Projectile Ship created" << std::endl;
}
Projectile::Projectile(Player const &p):
	_dir(1)
{
	_pos[0] = 0;
	_pos[1] = 0;
	if (p.getWeapon())
	{
		_pos[0] = p.getPos()[0];
		_pos[1] = p.getPos()[1];
	}
//	std::cout << "Projectile Player created" << std::endl;
}
Projectile::~Projectile(void)
{
//	std::cout << "Projectile destroyed" << std::endl;
}

Projectile		&Projectile::operator=(Projectile const &p)
{
	if (this != &p)
	{
		_dir = p.getDir();
		_pos[0] = p.getPos()[0];
		_pos[1] = p.getPos()[1];
	}
	return (*this);
}

int				Projectile::getDir(void) const
{
	return (_dir);
}
int				*Projectile::getPos(void) const
{
	return ((int *)_pos);
}

void			Projectile::retriveSpaceObject(t_spaceObject &sO) const
{
	sO.type = PROJECTILE;
	sO.size[0] = 1;
	sO.size[1] = 1;
	sO.pos[0] = _pos[0];
	sO.pos[1] = _pos[1];
}

std::ostream	&operator<<(std::ostream &os, Projectile const &p)
{
	os << "dir: " << p.getDir()
	   << ", pos: " << p.getPos()[0] << ":" << p.getPos()[1];
	return (os);
}
