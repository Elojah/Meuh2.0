// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ship.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 13:51:38 by erobert           #+#    #+#             //
//   Updated: 2015/01/11 19:17:15 by rbobillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHIP_HPP
# define SHIP_HPP

# include <string>
# include <iostream>
# include "ft_retro.h"
# include "ISpaceObject.hpp"
# include "AWeapon.hpp"

class Ship: public ISpaceObject
{
public:
	Ship(void);
	Ship(Ship const &s);
	Ship(std::string const &type, int const size[2],
		 int const pos[2], int cHP, int mHP);
	virtual ~Ship(void);
	
	Ship				&operator=(Ship const &s);
	Ship				&operator=(AWeapon *s);
	Ship				&operator+=(int const &i);
	Ship				&operator-=(int const &i);
	Ship				&operator+=(char const xy);
	Ship				&operator-=(char const xy);

	std::string const	&getType(void) const;
	int const			*getSize(void) const;
	int const			*getPos(void) const;
	int					getCHP(void) const;
	int					getMHP(void) const;
	AWeapon				*getWeapon(void) const;

	bool				fire(void) const;
	virtual void		retriveSpaceObject(t_spaceObject &sO) const;

protected:
	std::string			_type;
	int					_size[2];
	int					_pos[2];
	int					_cHP;
	int					_mHP;
	AWeapon				*_weapon;
};

std::ostream		&operator<<(std::ostream &os, Ship const &s);

#endif
