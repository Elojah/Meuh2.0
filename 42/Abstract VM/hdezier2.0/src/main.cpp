/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:46:48 by leeios            #+#    #+#             */
/*   Updated: 2016/05/17 16:16:02 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.h"
#include "Stack.h"

#include <iostream>
#include <fstream>

static void		exec(void)
{
	Stack	stack;
	Lexer	lexer;

	while (1)
	{
		std::string		line;
		std::cin >> line;
		auto lex_op = lexer.read_line(line, stack);
		if (lex_op == Lexer::eResult::QUIT || lex_op == Lexer::eResult::ERR)
			break ;
	}
}

static void		exec(const char *filename)
{
	Stack	stack;
	Lexer	lexer;
	std::ifstream	ifs(filename);
	std::string		line;

	while (std::getline(ifs, line))
	{
		auto lex_op = lexer.read_line(line, stack);
		if (lex_op == Lexer::eResult::QUIT || lex_op == Lexer::eResult::ERR)
			break ;
	}
}

int		main(int ac, char **av)
{
	if (ac == 1)
		exec();
	else if (ac == 2)
		exec(av[1]);
	else
		std::cout << "Usage: ./runner [filename]" << std::endl;
	return (0);
}
