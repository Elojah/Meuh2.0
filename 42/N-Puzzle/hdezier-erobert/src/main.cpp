// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 14:18:52 by erobert           #+#    #+#             //
//   Updated: 2015/03/10 14:37:27 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Puzzle.hpp"

static void						exec_puzzle(std::vector<int> &v, size_t size) {
	Puzzle						p(v, size);

	std::cout << "Exec puzzle..." << std::endl;
	if (p.isSolvable()) {
		p.solve();
	} else {
		std::cout << "Puzzle is not solvable" << std::endl;
	}
}

static void						parse_puzzle(std::ifstream &ifs)
{
	Lexer								l;
	Parser								p;

	p.parse(l.tokenize(ifs));
	if (p.good())
		exec_puzzle(p.getVector(), p.getSize());
}

int								main(int ac, char **av)
{
	std::ifstream				ifs;

	if (ac == 1)
		std::cerr << av[0] << ": puzzle_file" << std::endl;
	else
	{
		ifs.open(av[1]);
		if (ifs.good())
		{
			parse_puzzle(ifs);
			ifs.close();
		}
	}
	return (0);
}
