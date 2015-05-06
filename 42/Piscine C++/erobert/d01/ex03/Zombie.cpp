// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 11:35:02 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 13:36:46 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

Zombie::Zombie(void):
	_name("default"),
	_type("?")
{
	std::cout << "Zombie born"
			  << std::endl;
	return ;
}
Zombie::~Zombie(void)
{
	std::cout << "Zombie dead"
			  << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::setType(std::string type)
{
	this->_type = type;
}

void	Zombie::announce(void)
{
	std::cout << "<"
			  << this->_name
			  << " ("
			  << this->_type
			  << ")> Vodkaaaaa..."
			  << std::endl;
}
