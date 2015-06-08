// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/29 18:48:23 by erobert           #+#    #+#             //
//   Updated: 2015/06/08 12:37:55 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "GameManager.hpp"

static bool		exec(unsigned int size)
{
	GameManager	g;

	g.init(size);
	return (g.loop());
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
	{
		while (exec(size))
			;
	}
	else
		std::cerr << "usage: " << av[0] << " [-s | -m | -b]" << std::endl;
	return (0);
}
