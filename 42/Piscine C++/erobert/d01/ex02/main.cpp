// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 12:09:03 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 12:54:06 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int				main(void)
{
	Zombie		z1("z1", "type_z1");
	ZombieEvent zE;

	z1.announce();
	zE.randomChump();
	zE.setZombieType("type_z2");
	zE.randomChump();
	return (0);
}
