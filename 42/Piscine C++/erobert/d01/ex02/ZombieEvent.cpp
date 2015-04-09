// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 12:03:35 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 13:32:32 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void):
	_type("?")
{
	this->_rand = time(0);
	return ;
}
ZombieEvent::~ZombieEvent(void)
{
	return ;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	std::string	type;

	type = this->_type;
	return (new Zombie(name, type));
}
void	ZombieEvent::randomChump(void)
{
	char const	*names[5] = {
		"Coraline",
		"Caroline",
		"Cocaine",
		"Christophe",
		"Cyril"
	};
	Zombie		*z;

	std::srand(this->_rand);
	z = this->newZombie(names[std::rand() % 5]);
	this->_rand %= 39;
	z->announce();
	delete z;
}
