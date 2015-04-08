// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 14:47:08 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 15:57:24 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	std::string	_name;
	int			_ap;
	AWeapon		*_w;

public:
	Character(void);
	Character(Character const &c);
	Character(std::string const &name);
	~Character(void);

	Character			&operator=(Character const &c);

	std::string	const	&getName(void) const;
	int					getAP(void) const;
	AWeapon				*getW(void) const;

	void				recoverAP(void);
	void				equip(AWeapon *w);
	void				attack(Enemy *e);
};

std::ostream	&operator<<(std::ostream &os, Character const &c);

#endif
