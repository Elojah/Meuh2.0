// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/18 10:50:29 by erobert           #+#    #+#             //
//   Updated: 2015/05/18 11:54:00 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <string>
#include "GameManager.hpp"

static int		getSize(char **av)
{
	std::string	size[GameManager::E_SIZE];
	int			i(-1);

	size[GameManager::SMALL] = "small";
	size[GameManager::MEDIUM] = "medium";
	size[GameManager::BIG] = "big";
	while (++i < 3)
	{
		if (!size[i].compare(av[1]))
			return (i);
	}
	return (-1);	
}

int				main(int ac, char **av)
{
	GameManager	gM;

	if (ac == 1)
		gM.initBoard(GameManager::BIG);
	else if (ac == 2 && getSize(av) != -1)
		gM.initBoard(static_cast<GameManager::eSize>(getSize(av)));
	else
	{
		std::cerr << "Error: " << av[0] << " [small/medium/big]." << std::endl;
		return (-1);
	}
	gM.gameLoop();
	return (0);
}
