/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:36:25 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/02 20:39:35 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gomoku.h"

static void		exec(unsigned int size)
{
	GameManager	g;

	g.init(size);
	g.loop();
}

int				main(int ac, char **av)
{
	int			size(0);

	if (ac == 1)
		size = 19;
	else if (ac == 2)
	{
		if (!strcmp("-s", av[1]))
			size = 9;
		else if (!strcmp("-m", av[1]))
			size = 13;
		else if (!strcmp("-b", av[1]))
			size = 19;
	}
	if (size)
		exec(size);
	else
		std::cerr << "usage: " << av[0] << " [-s | -m | -b]" << std::endl;
	return (0);
}
