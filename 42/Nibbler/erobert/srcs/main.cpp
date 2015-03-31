// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/03 16:38:39 by erobert           #+#    #+#             //
//   Updated: 2015/03/31 15:10:04 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sstream>
#include "Game.hpp"

int			main(int ac, char **av)
{
	Game	g;

	if (ac != 3)
		std::cerr << av[0] << " height width" << std::endl;
	else if (g.buildMap(av[1], av[2]))
	{
		g.gameLoop();
	}
	return (0);
}
