// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 16:00:49 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 16:41:41 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class Weapon
{
private:
	std::string	_type;

public:
	Weapon(std::string type);
	~Weapon(void);

	void				setType(std::string type);
	std::string const	&getType(void);
};

#endif
