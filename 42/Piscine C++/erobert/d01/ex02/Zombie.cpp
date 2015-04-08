// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 11:35:02 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 12:53:54 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type):
	_name(name),
	_type(type)
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

void	Zombie::announce(void)
{
	std::cout << "<"
			  << this->_name
			  << " ("
			  << this->_type
			  << ")> Vodkaaaaa..."
			  << std::endl;
}
