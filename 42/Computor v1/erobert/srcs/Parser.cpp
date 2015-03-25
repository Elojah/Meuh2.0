// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 19:19:53 by erobert           #+#    #+#             //
//   Updated: 2015/03/25 19:08:24 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"

Parser::Parser(void):
	_good(true),
	_vector(MAX_DEGREE + 1, 0)
{}
Parser::~Parser(void) {}

bool						Parser::good(void) const
{
	return (_good);
}
std::vector<float> const	&Parser::vector(void) const
{
	return (_vector);
}

void						Parser::setError(void)
{
	_good = false;
	std::cerr << "Parser: error";
}
float						Parser::getValue(tTI &it)
{
	std::stringstream		ss;
	float					value;

	if (it->first != Lexer::VALUE)
		return (1);
	ss << it->second;
	ss >> value;
	return (value);
}
size_t						Parser::getDegree(tTI &it, tTI &ie)
{
	std::stringstream		ss;
	size_t					degree;

	if (!it->second.compare("*"))
	{
		it++;
		if (it == ie)
		{
			setError();
			std::cerr << ": no variable after *." << std::endl;
			return (MAX_DEGREE);
		}
	}
	if (it->first != Lexer::VARIABLE && it->first != Lexer::POWER)
		return (0);
	if (++it == ie)
		return (1);
	if (it->first != Lexer::POWER)
		return (1);
	if (++it == ie)
	{
		setError();
		std::cerr << ": no value after ^." << std::endl;
		return (MAX_DEGREE);
	}
	if (it->first != Lexer::VALUE)
	{
		setError();
		std::cerr << ": no value after ^." << std::endl;
		return (MAX_DEGREE);
	}
	ss << it->second;
	ss >> degree;
	return (degree);
}
void						Parser::checkItem(tTI &it, tTI &ie,
											  bool right, bool first)
{
	float					value;
	size_t					degree;

	if (it->first != Lexer::OPERATOR && !first)
	{
		setError();
		std::cerr << ": no operator." << std::endl;
		return ;
	}
	if (first)
	{
		value = getValue(it);
		if (right)
			value *= -1;
	}
	else if (!it->second.compare("-"))
	{
		it++;
		value = getValue(it);
		if (!right)
			value *= -1;
	}
	else
	{
		it++;
		value = getValue(it);
		if (right)
			value *= -1;
	}
	it++;
	degree = getDegree(it, ie);
	if (degree < MAX_DEGREE)
		_vector[degree] += value;
}
void						Parser::parse(std::list<tToken> const &tokens)
{
	tTI						it(tokens.begin());
	tTI						ie(tokens.end());
	bool					right(false);
	bool					first(true);

	while (it != ie && it->first != Lexer::EQUAL)
	{
		checkItem(it, ie, right, first);
		if (it->first != Lexer::OPERATOR)
			it++;
		first = false;
	}
	if (it == ie)
	{
		setError();
		return ;
	}
	it++;
	right = true;
	first = true;
	while (it != ie)
	{
		checkItem(it, ie, right, first);
		if (it->first != Lexer::OPERATOR)
			it++;
		first = false;
	}
}
