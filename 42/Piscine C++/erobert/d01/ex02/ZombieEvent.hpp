// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 11:48:16 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 13:28:27 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

# include <iostream>
# include <cstdlib>
# include <ctime>  
# include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string			_type;
	time_t				_rand;

public:	
	ZombieEvent(void);
	~ZombieEvent(void);

	void				setZombieType(std::string type);

	Zombie				*newZombie(std::string name);
	void				randomChump(void);
};

#endif
