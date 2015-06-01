// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/29 18:48:23 by erobert           #+#    #+#             //
//   Updated: 2015/06/01 18:49:27 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "GameManager.hpp"

static void		exec(unsigned int size)
{
	GameManager	g;

	g.init(size);
	g.loop();
}

int				main(int ac, char **av)
{
	if (ac == 1)
		exec(19);
	else if (ac == 2)
	{
		if (!strcmp("small", av[1]))
			exec(9);
		else if (!strcmp("medium", av[1]))
			exec(13);
		else if (!strcmp("big", av[1]))
			exec(19);
		else
			std::cerr << av[0] << " [small/medium/big]" << std::endl;
	}
	else
		std::cerr << av[0] << " [small/medium/big]" << std::endl;
	return (0);
}
