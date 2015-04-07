// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_game_loop.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 16:18:50 by erobert           #+#    #+#             //
/*   Updated: 2015/01/12 08:25:12 by rbobillo         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "ft_retro.h"
#include "Ship.hpp"
#include "Player.hpp"
#include "PlasmaCannon.hpp"
#include "Projectile.hpp"

void				ft_render(Player &player, Projectile *p)
{
	clock_t			prev = clock();
	clock_t			delay = CLOCKS_PER_SEC / 60;
	clock_t			tmp;
	unsigned int	slep;
	int				i(1);

	while (++i < 64)
	{
		if (p[i].getDir())
		{
			p[i].getPos()[0] += 2 * p[i].getDir();
			mvprintw(p[i].getPos()[1], p[i].getPos()[0], "-");
		}
	}
	mvprintw(player.getPos()[1], player.getPos()[0], ">");
	refresh();
	tmp = clock() - prev;
	if (tmp < delay)
	{
		tmp = (delay - tmp);
		slep = tmp * CLOCKS_PER_SEC / 1000000;
		usleep(slep);
	}
}

void				ft_game_loop(int const *dim, WINDOW *game_win)
{
	int				c;
	int				pos[2] = {
		(dim[0] / 2) + (dim[0] % 2),
		(dim[1] / 2) + (dim[1] % 2)
	};
	int				size[2] = {1, 1};
	Ship			playerShip("Destructor", size, pos, 100, 100);
	Player			player;
	PlasmaCannon	plasma;
	playerShip = &plasma;
	pos[0] = 1;
	pos[1] = 1;
	Ship			enemyShip("GunsNRoses", size, pos, 100, 100);
	Projectile		*p = new Projectile[64];
	//	playerShip = &plasma;
	player = playerShip;
	Projectile		pr;
	int				i(0);

	while (1138)
	{
		clear();
		switch (c = wgetch(game_win))
		{
			case KEY_UP:
				if (player.getPos()[1] > 0)
					player -= 'y';
				break ;
			case KEY_DOWN:
				if (player.getPos()[1] < dim[1] - 1)
					player += 'y';
				break ;
			case KEY_LEFT:
				if (player.getPos()[0] > 0)
					player -= 'x';
				break ;
			case KEY_RIGHT:
				if (player.getPos()[0] < dim[0] - 1)
					player += 'x';
				break ;
			case KEY_SPACE:
				if (player.fire())
					p[i++ % 64] = Projectile(player);
				break;
			case ESC:
				clear();
				return;
				break;
			case QUIT:
				clear();
				return;
				break;
			case PAUSE:
				nodelay(stdscr,FALSE);
				mvprintw(0, 0, "Paused...");
				getch();
				nodelay(stdscr,TRUE);
				break;
			default:
				break;
		}
		ft_render(player, p);
	}
}
