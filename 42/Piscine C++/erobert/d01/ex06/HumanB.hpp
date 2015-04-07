// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 16:28:14 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 17:30:34 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_B_H
# define HUMAN_B_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	Weapon		*_w;
	std::string	_name;

public:
	HumanB(std::string name);
	~HumanB(void);

	void		setWeapon(Weapon &w);

	void		attack(void);
};

#endif
