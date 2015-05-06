// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 16:32:03 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 17:28:49 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}
HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon &w)
{
	this->_w = &w;
}

void	HumanB::attack(void)
{
	std::cout << this->_name
			  << " attacks with his "
			  << this->_w->getType()
			  << std::endl;
}
