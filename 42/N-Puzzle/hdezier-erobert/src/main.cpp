// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 14:18:52 by erobert           #+#    #+#             //
//   Updated: 2015/03/06 16:35:20 by erobert          ###   ########.fr       //
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

	p.resolve();
}

static void						parse_puzzle(std::ifstream &ifs)
{
	Lexer								l;
	Parser								p;
	std::list<Lexer::tToken>			tokens;
	std::list<Lexer::tToken>::iterator	ib;
	std::list<Lexer::tToken>::iterator	ie;
	std::vector<int>					vector;
	unsigned int						i(0);

	tokens = l.tokenize(ifs);
	ib = tokens.begin();
	ie = tokens.end();
	while (ib != ie--)
		std::cout << ie->first << " " << ie->second << std::endl;
	vector = p.parse(tokens);
	std::cout << vector.size() << std::endl;
	std::cout << p.getSize() << std::endl;
	while (i < vector.size())
	{
		std::cout << vector[i] << "|";
		if (!(++i % p.getSize()))
			std::cout << std::endl;
	}
	ifs.close();
	if (p.isGood()) {
		exec_puzzle(vector, p.getSize());
	}
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
			parse_puzzle(ifs);
	}
	return (0);
}
