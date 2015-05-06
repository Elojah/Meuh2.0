// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 11:58:14 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 12:14:15 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Peon.hpp"

Peon::Peon(void):
	Victim()
{
	std::cout << "Zog zog."
			  << std::endl;
}
Peon::Peon(Peon const &p):
	Victim(p.getName())
{
	*this = p;
	std::cout << "Zog zog."
			  << std::endl;
}
Peon::Peon(std::string const name):
	Victim(name)
{
	std::cout << "Zog zog."
			  << std::endl;
}
Peon::~Peon(void)
{
	std::cout << "Bleuark..."
			  << std::endl;
}

Peon		&Peon::operator=(Peon const &p)
{
	if (this != &p)
		_name = p.getName();
	return (*this);
}

void		Peon::getPolymorphed(void) const
{
	std::cout << _name
			  << " has been turned into a pink pony !"
			  << std::endl;
}
