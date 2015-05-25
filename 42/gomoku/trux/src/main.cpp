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
#include "GameManager.hpp"

static void		exec(GameManager::eSize size)
{
	GameManager	gM;

	gM.initBoard(size);
	gM.gameLoop();
}

int				main(int ac, char **av)
{
	if (ac != 1)
	{
		std::cerr << "Error: " << av[0] << " [no args]." << std::endl;
		return (-1);
	}
	exec(GameManager::BIG);
	return (0);
}
