// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/23 18:04:08 by erobert           #+#    #+#             //
//   Updated: 2015/02/06 16:35:13 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <fstream>
#include <iostream>
#include <string>
#include "Parser.hpp"
#include "Exec.hpp"

static size_t		count(1);

static void			ft_stdin(Parser &p, Exec &e)
{
	std::string		line;

	while (std::getline(std::cin, line))
	{
		if (!line.compare(";;"))
		{
			if (p.gotExit())
			{
				e.execCommand(p.getCmd());
				return ;
			}
			else
				throw Parser::NoExit();
		}
		else
		{
			p.parseLine(line);
			count++;
		}
	}
}

static void			ft_file(Parser &p, Exec &e, char const *file)
{
	std::ifstream	ifs(file);
	std::string		line;

	while (std::getline(ifs, line))
	{
		p.parseLine(line);
		count++;
	}
	if (p.gotExit())
		e.execCommand(p.getCmd());
	else
		throw Parser::NoExit();
	ifs.close();
}

int					main(int ac, char **av)
{
	Parser			p;
	Exec			e;

	if (ac == 1)
	{
		try
		{
			ft_stdin(p, e);
		}
		catch (std::exception &e)
		{
			std::cerr << "Line " << count << ". " << e.what() << std::endl;
			return (1);
		}
	}
	else
	{
		try
		{
			ft_file(p, e, av[1]);
		}
		catch (std::exception &e)
		{
			std::cerr << "Line " << count << ". " << e.what() << std::endl;
			return (1);
		}
	}
	return (0);
}




IOperand *a = (new int8(55));
IOperand *b = (new int8(55));
IOperand *c = *a + *b;

std::cout << c.toString() << std::endl;












