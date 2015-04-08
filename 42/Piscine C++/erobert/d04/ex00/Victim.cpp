// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 11:28:19 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 13:01:49 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Victim.hpp"

Victim::Victim(void)
{
	std::cout << "Hey whats my name?"
			  << std::endl;
	std::cin >> _name;
	std::cout << "Some random victim called "
			  << _name
			  << " just popped !"
			  << std::endl;
}
Victim::Victim(Victim const &v)
{
	*this = v;
	std::cout << "Some random victim called "
			  << _name
			  << " just popped !"
			  << std::endl;
}
Victim::Victim(std::string const name):
	_name(name)
{
	std::cout << "Some random victim called "
			  << _name
			  << " just popped !"
			  << std::endl;
}
Victim::~Victim(void)
{
	std::cout << "Victim "
			  << _name
			  << " just died for no apparent reason !"
			  << std::endl;
}

Victim			&Victim::operator=(Victim const &v)
{
	if (this != &v)
		_name = v.getName();
	return (*this);
}

std::string		Victim::getName(void) const
{
	return (_name);
}

void			Victim::getPolymorphed(void) const
{
	std::cout << _name
			  << " has been turned into a cute little sheep !"
			  << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Victim const &v)
{
	std::cout << "I'm "
			  << v.getName()
			  << " and i like otters !"
			  << std::endl;
	return (os);
}
