// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 11:31:15 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 08:17:38 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void): 
	_fname(""),
	_lname(""),
	_nname(""),
	_login(""),
	_paddr(""),
	_eaddr(""),
	_pnumb(""),
	_bdate(""),
	_favoriteMeal(""),
	_underwearsColors(""),
	_darkestSecret("")
{
	return ;
}
Contact::~Contact(void)
{
	return ;
}

void		Contact::setFname(std::string& str)
{
	this->_fname = str;
}
std::string	Contact::getFname(void)
{
	return (this->_fname);
}

void		Contact::setLname(std::string& str)
{
	this->_lname = str;
}
std::string	Contact::getLname(void)
{
	return (this->_lname);
}

void		Contact::setNname(std::string& str)
{
	this->_nname = str;
}
std::string	Contact::getNname(void)
{
	return (this->_nname);
}

void		Contact::setLogin(std::string& str)
{
	this->_login = str;
}
std::string	Contact::getLogin(void)
{
	return (this->_login);
}

void		Contact::setPaddr(std::string& str)
{
	this->_paddr = str;
}
std::string	Contact::getPaddr(void)
{
	return (this->_paddr);
}

void		Contact::setEaddr(std::string& str)
{
	this->_eaddr = str;
}
std::string	Contact::getEaddr(void)
{
	return (this->_eaddr);
}

void		Contact::setPnumb(std::string& str)
{
	this->_pnumb = str;
}
std::string	Contact::getPnumb(void)
{
	return (this->_pnumb);
}

void		Contact::setBdate(std::string& str)
{
	this->_bdate = str;
}
std::string	Contact::getBdate(void)
{
	return (this->_bdate);
}

void		Contact::setFavoriteMeal(std::string& str)
{
	this->_favoriteMeal = str;
}
std::string	Contact::getFavoriteMeal(void)
{
	return (this->_favoriteMeal);
}

void		Contact::setUnderwearsColors(std::string& str)
{
	this->_underwearsColors = str;
}
std::string	Contact::getUnderwearsColors(void)
{
	return (this->_underwearsColors);
}

void		Contact::setDarkestSecret(std::string& str)
{
	this->_darkestSecret = str;
}
std::string	Contact::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}
