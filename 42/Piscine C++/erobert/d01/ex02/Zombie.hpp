// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 11:31:15 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 12:27:08 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string		_name;
	std::string		_type;

public:
	Zombie(std::string name, std::string type);
	~Zombie(void);

	void			announce(void);
};

#endif
