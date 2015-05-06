// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 13:07:51 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 15:14:00 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N):
	_n(N)
{
	int			i(0);
	char const	*names[5] = {
		"Coraline",
		"Caroline",
		"Cocaine",
		"Christophe",
		"Cyril"
	};
	int			rand;

	this->_z = new Zombie[N];
	rand = time(0);
	while (i < N)
	{
		std::srand(rand);
		this->_z[i].setName(names[std::rand() % 5]);
		this->_z[i++].setType("type_z1");
		if (rand < 700)
			rand += 39;
		else
			rand %= 31;
	}
	return ;
}
ZombieHorde::~ZombieHorde(void)
{
	delete[] this->_z;
	return ;
}

void			ZombieHorde::announce(void)
{
	int			i(0);

	while (i < this->_n)
		this->_z[i++].announce();
}
