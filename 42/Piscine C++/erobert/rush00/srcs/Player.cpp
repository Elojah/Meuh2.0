// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:47:33 by erobert           #+#    #+#             //
/*   Updated: 2015/01/12 08:31:44 by rbobillo         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"

Player::Player(void):
	Game(),
	Ship()
{
	//	std::cout << "Player enter" << std::endl;
}
Player::Player(Player const &p):
	Game(),
	Ship()
{
	*this = p;
	//	std::cout << "Player enter" << std::endl;
}
Player::Player(std::string const &name):
	Game(),
	Ship(),
	_name(name)
{
	//	std::cout << "Player enter" << std::endl;
}
Player::~Player(void)
{
	//	std::cout << "Player leave" << std::endl;
}

Player				&Player::operator=(Player const &p)
{
	if (this != &p)
	{
		_name = p.getName();
		_cLives = p.getCLives();
		_mLives = p.getMLives();
		_type = p.getType();
		_size[0] = p.getSize()[0];
		_size[1] = p.getSize()[1];
		_pos[0] = p.getPos()[0];
		_pos[1] = p.getPos()[1];
		_cHP = p.getCHP();
		_mHP = p.getMHP();
		_weapon = p.getWeapon();
	}
	return (*this);
}
Player				&Player::operator=(Ship const &s)
{
	_type = s.getType();
	_size[0] = s.getSize()[0];
	_size[1] = s.getSize()[1];
	_pos[0] = s.getPos()[0];
	_pos[1] = s.getPos()[1];
	_cHP = s.getCHP();
	_mHP = s.getMHP();
	_weapon = s.getWeapon();
	return (*this);
}

std::string const	&Player::getName(void) const
{
	return (_name);
}
int					Player::getCLives(void) const
{
	return (_cLives);
}
int					Player::getMLives(void) const
{
	return (_mLives);
}

void				Player::retriveSpaceObject(t_spaceObject &sO) const
{
	sO.type = PLAYER;
	sO.size[0] = _size[0];
	sO.size[1] = _size[1];
	sO.pos[0] = _pos[0];
	sO.pos[1] = _pos[1];
}
