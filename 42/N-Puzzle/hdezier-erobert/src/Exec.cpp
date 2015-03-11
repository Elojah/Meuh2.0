// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exec.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/11 13:57:46 by erobert           #+#    #+#             //
//   Updated: 2015/03/11 14:29:36 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Exec.hpp"

Exec::Exec(void):
	_good(true),
	_name(""),
	_size(0)
{
	_arg[0] = "-f";
	_arg[1] = "-h";
}
Exec::~Exec(void) {}

void				Exec::errorAv(void)
{
	std::cerr << _name << ": [-f file_name] [-h heuristic]" << std::endl;
}
void				Exec::parsePuzzle(char *file)
{
	std::ifstream	ifs(file);
	Lexer			l;
	Parser			p;

	if (ifs.good())
	{
		p.parse(l.tokenize(ifs));
		if (p.good())
		{
			_vector = p.getVector();
			_size = p.getSize();
			ifs.close();
		}
		else
			_good = false;
	}
	else
	{
		std::cerr << _name << ": " << file << ": no such file" << std::endl;
		_good = false;
	}
}
void				Exec::parseHeuristic(char *heuristic)
{
	(void)heuristic;
}

void				Exec::parseAv(int ac, char **av)
{
	int				i(0);

	_name = av[0];
	while (++i < ac)
	{
		if (_arg[0].compare(av[i]) && i + 1 < ac)
			parsePuzzle(av[++i]);
		else if (_arg[1].compare(av[i]) && i + 1 < ac)
			parseHeuristic(av[++i]);
		else
			_good = false;
	}
}

void				Exec::solvePuzzle(void)
{
	Puzzle			*p;

	if (!_good)
		return (errorAv());
	p = new Puzzle(_vector, _size);
	std::cout << "Exec puzzle..." << std::endl;
	if (p->isSolvable())
		p->solve();
	else
		std::cout << "Puzzle is not solvable" << std::endl;
	delete p;
}
