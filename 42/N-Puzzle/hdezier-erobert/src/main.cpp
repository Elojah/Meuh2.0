// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 14:18:52 by erobert           #+#    #+#             //
//   Updated: 2015/03/05 20:59:58 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <fstream> 
#include <iostream>
#include <list>
#include <vector>
#include "Lexer.hpp"
#include "Parser.hpp"

static void						exec_puzzle(std::ifstream &ifs)
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
	while (i < vector.size())
	{
		std::cout << vector[i] << "|";
		if (!(++i % p.getSize()))
			std::cout << std::endl;
	}
	ifs.close();
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
			exec_puzzle(ifs);
	}
	return (0);
}
