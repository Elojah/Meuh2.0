// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 14:18:52 by erobert           #+#    #+#             //
//   Updated: 2015/03/05 14:28:30 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Puzzle.hpp"

static void			exec_puzzle(std::ifstream &ifs)
{
	Puzzle			p(ifs);

	ifs.close();
}

int					main(int ac, char **av)
{
	std::ifstream	ifs;

	if (ac == 1)
		std::cerr << av[0] << ": puzzle_file";
	else
	{
		ifs.open(av[1]);
		if (ifds.good())
			exec_puzzle(ifs);
	}
	return (0);
}
