// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 10:44:43 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 13:01:35 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)
{
	std::cout << "You forget my name and title !"
			  << std::endl
			  << "Name me : ";
	std::cin >> _name;
	std::cout << "And my title : ";
	std::cin >> _title;
	std::cout << _name
			  << ", "
			  << _title
			  << ", is born !"
			  << std::endl;
}
Sorcerer::Sorcerer(Sorcerer const &s)
{
	*this = s;
	std::cout << _name
			  << ", "
			  << _title
			  << ", is born !"
			  << std::endl;
}
Sorcerer::Sorcerer(std::string const name, std::string const title):
	_name(name),
	_title(title)
{
	std::cout << _name
			  << ", "
			  << _title
			  << ", is born !"
			  << std::endl;
}
Sorcerer::~Sorcerer(void)
{
	std::cout << _name
			  << ", "
			  << _title
			  << ", is dead. Consequences will never be the same !"
			  << std::endl;
}

Sorcerer		&Sorcerer::operator=(Sorcerer const &s)
{
	if (this != &s)
	{
		_name = s.getName();
		_title = s.getTitle();
	}
	return (*this);
}

std::string		Sorcerer::getName(void) const
{
	return (_name);
}
std::string		Sorcerer::getTitle(void) const
{
	return (_title);
}

void			Sorcerer::polymorph(Victim const &v) const
{
	v.getPolymorphed();
}

std::ostream	&operator<<(std::ostream &os, Sorcerer const &s)
{
	os << "I am "
	   << s.getName()
	   << ", "
	   << s.getTitle()
	   << ", and I like ponies !"
	   << std::endl;
	return (os);
}
