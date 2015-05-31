// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/29 18:48:23 by erobert           #+#    #+#             //
//   Updated: 2015/05/29 18:48:25 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameManager.hpp"

static void	exec(void)
{
	GameManager		g;

	g.init();
	g.loop();
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	exec();
	return (0);
}
