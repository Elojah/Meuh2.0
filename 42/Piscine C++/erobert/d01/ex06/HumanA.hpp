// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 16:22:15 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 16:50:06 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_A_H
# define HUMAN_A_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon		&_w;
	std::string	_name;

public:
	HumanA(std::string name, Weapon &w);
	~HumanA(void);

	void		attack(void);
};

#endif
