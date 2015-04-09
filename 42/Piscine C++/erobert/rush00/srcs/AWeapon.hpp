// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 13:05:49 by erobert           #+#    #+#             //
//   Updated: 2015/01/11 19:21:18 by rbobillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef A_WEAPON_HPP
# define A_WEAPON_HPP

# include <string>
# include <iostream>

class AWeapon
{
protected:
	std::string	_name;
	int			_apcost;
	int			_damage;

public:
	AWeapon(void);
	AWeapon(AWeapon const &aW);
	AWeapon(std::string const &name, int apcost, int damage);
	virtual ~AWeapon(void);

	AWeapon				&operator=(AWeapon const &aW);

	std::string const	&getName(void) const;
	int					getAPCost(void) const;
	int					getDamage(void) const;

	virtual void		attack(void) const = 0;
};

#endif
