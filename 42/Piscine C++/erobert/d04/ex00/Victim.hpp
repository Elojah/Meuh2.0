// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 10:27:41 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 12:12:27 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{
protected:
	std::string	_name;

public:
	Victim(void);
	Victim(Victim const &v);
	Victim(std::string const name);
	~Victim(void);

	Victim		&operator=(Victim const &v);

	std::string	getName(void) const;

	virtual void	getPolymorphed(void) const;
};

std::ostream		&operator<<(std::ostream &os, Victim const &v);

#endif
