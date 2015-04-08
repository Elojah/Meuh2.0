// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 13:04:19 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 13:51:21 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

# include <cstdlib>
# include <ctime>
# include "Zombie.hpp"

class ZombieHorde
{
private:
	int		_n;
	Zombie	*_z;

public:
	ZombieHorde(int N);
	~ZombieHorde(void);

	void	announce(void);
};

#endif
