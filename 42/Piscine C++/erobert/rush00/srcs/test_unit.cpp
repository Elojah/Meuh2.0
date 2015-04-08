// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_unit.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 14:13:10 by erobert           #+#    #+#             //
/*   Updated: 2015/01/12 08:32:41 by rbobillo         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include <ncurses.h>
#include "Game.hpp"
#include "Ship.hpp"
#include "Player.hpp"
#include "AWeapon.hpp"
#include "PlasmaCannon.hpp"
#include "LaserGatling.hpp"
#include "Projectile.hpp"

int				main(void)
{
	int			size[2] = {5, 5};
	int			pos[2] = {1138, 42};
	Ship		s0;
	std::cout << s0 << std::endl;
	Ship		s1(s0);
	std::cout << s1 << std::endl;
	Ship		s2("Destroyer", size, pos, 280, 280);
	std::cout << s2 << std::endl;

	s0 = s2;
	std::cout << s0 << std::endl;

	Player		p0;
	std::cout << p0 << std::endl;
	AWeapon		*w;

	w = new PlasmaCannon;
	s2 = w;
	std::cout << s2 << std::endl;
	p0 = s2;
	std::cout << p0 << std::endl;
//	p0.fire(s1);
	std::cout << s1 << std::endl;
	p0 -= 'x';
	std::cout << p0 << std::endl;
	p0 += 'y';
	std::cout << p0 << std::endl;
	delete w;
	w = new LaserGatling;
	std::cout << p0 << std::endl;

	p0.fire();
	Projectile	p(p0);
	std::cout << p << std::endl;

	p = s1;
//	p = p0.fire(s1);
	std::cout << p << std::endl;
	delete w;

	Game	g0;

//	ft_game_loop();
}
