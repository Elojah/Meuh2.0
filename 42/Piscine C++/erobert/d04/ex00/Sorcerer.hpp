// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 10:26:27 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 12:10:20 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer
{
private:
	std::string	_name;
	std::string	_title;

public:
	Sorcerer(void);
	Sorcerer(Sorcerer const &s);
	Sorcerer(std::string const name, std::string const title);
	~Sorcerer(void);

	Sorcerer	&operator=(Sorcerer const &s);

	std::string	getName(void) const;
	std::string	getTitle(void) const;

	void		polymorph(Victim const &v) const;
};

std::ostream	&operator<<(std::ostream &os, Sorcerer const &s);

#endif
