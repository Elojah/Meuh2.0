// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 19:19:53 by erobert           #+#    #+#             //
//   Updated: 2015/03/05 21:04:52 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"

Parser::Parser(void) {}
Parser::~Parser(void) {}

unsigned int				Parser::getSize(void) const
{
	return (_size);
}

int							Parser::checkSize(tToken &token)
{
	std::stringstream		ss;

	ss << token.second;
	ss >> _size;
	if (!_size)
		return (-1);
	return (0);
}
Parser::tTI					Parser::checkValues(tTI it, tTI ie)
{
	std::stringstream		ss;
	int						tmp(0);
	unsigned int			count(0);

	while (it != ie)
	{
		if (it->first == Lexer::END || it->first == Lexer::COMMENT)
		{
			if (count < _size)
				return (ie);
			return (it);
		}
		else if (it->first != Lexer::VALUE)
			return (ie);
		ss << it->second;
		ss >> tmp;
		ss.clear();
		_vector.push_back(tmp);
		count++;
		it++;
	}
	return (it);
}

std::vector<int>			&Parser::parse(std::list<tToken> &tokens)
{
	tTI						it(tokens.begin());
	tTI						ie(tokens.end());
	unsigned int			count(0);

	while (it != ie && (it->first == Lexer::COMMENT || it->first == Lexer::END))
		it++;
	checkSize(*it);
	while (++it != ie)
	{
		if (it->first == Lexer::VALUE)
		{
			it = checkValues(it, ie);
			if (it == ie)
				std::cerr << "Parser: error" << std::endl;
			else
				count++;
		}
		else if (it->first != Lexer::COMMENT && it->first != Lexer::END)
		{
			std::cout << it->first << " " << it->second << std::endl;
			std::cerr << "Parser: error" << std::endl;
		}
	}
	return (_vector);
}
