// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 16:19:34 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 16:41:59 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}
Weapon::~Weapon(void)
{
	return ;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string const   &Weapon::getType(void)
{
	return (this->_type);
}
