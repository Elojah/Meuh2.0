/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:36:25 by hdezier           #+#    #+#             */
//   Updated: 2016/05/03 01:46:35 by erobert          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "GameManager.h"

static void		exec(eSize size)
{
	if (size == eSize::SMALL)
	{
		GameManager<common::small>	g;
		g.loop();
	}
	else if (size == eSize::MEDIUM)
	{
		GameManager<common::medium>	g;
		g.loop();
	}
	else if (size == eSize::LARGE)
	{
		GameManager<common::large>	g;
		g.loop();
	}
}

int				main(int ac, char **av)
{
	eSize			size;

	size = eSize::ERROR;
	if (ac == 1)
		size = eSize::LARGE;
	else if (ac == 2)
	{
		if (!strcmp("-s", av[1]))
			size = eSize::SMALL;
		else if (!strcmp("-m", av[1]))
			size = eSize::MEDIUM;
		else if (!strcmp("-b", av[1]))
			size = eSize::LARGE;
	}
	if (size != eSize::ERROR)
		exec(size);
	else
		std::cerr << "usage: " << av[0] << " [-s | -m | -b]" << std::endl;
	return (0);
}
