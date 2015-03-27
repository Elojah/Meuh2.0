// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 17:13:57 by erobert           #+#    #+#             //
//   Updated: 2015/03/25 18:18:22 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Lexer.hpp"

Lexer::Lexer(void) {}
Lexer::~Lexer(void) {}
#include <iostream>
std::list<Lexer::tToken> const	&Lexer::tokens(void) const
{
	return (_tokens);
}

void							Lexer::getEqual(void)
{
	tToken						t;

	t.first = EQUAL;
	t.second.push_back('=');
	_tokens.push_back(t);
}
void							Lexer::getPower(void)
{
	tToken						t;

	t.first = POWER;
	t.second.push_back('^');
	_tokens.push_back(t);
}
void							Lexer::getOperator(char c)
{
	tToken						t;

	t.first = OPERATOR;
	t.second.push_back(c);
	_tokens.push_back(t);
}
void							Lexer::getVariable(void)
{
	tToken						t;

	t.first = VARIABLE;
	t.second.push_back('X');
	_tokens.push_back(t);
}
void							Lexer::getValue(std::stringstream &ss, char c)
{
	std::string					str;
	tToken						t;
	bool						point(false);

	while (isdigit(c) || (c == '.' && !point))
	{
		if (c == '.')
			point = true;
		str.push_back(c);
		if (!ss.get(c))
		{
			t.first = VALUE;
			t.second = str;
			_tokens.push_back(t);
			return ;
		}
	}
	t.first = VALUE;
	t.second = str;
	_tokens.push_back(t);
	checkChar(c);
}
void							Lexer::checkChar(char c)
{
	tToken						none;

	none.first = NONE;
	none.second = "!";
	if (c != ' ')
	{
		if (c == '=')
			getEqual();
		else if (c == '^')
			getPower();
		else if (c == 'X')
			getVariable();
		else if (c == '+' || c == '-' || c == '*' || c == '/')
			getOperator(c);
		else
			_tokens.push_back(none);
	}
}
void							Lexer::tokenize(std::string const &s)
{
	std::stringstream			ss(s);
	char						c;
	tToken						t;

	while (ss.get(c))
	{
		if (isdigit(c) || c == '.')
			getValue(ss, c);
		else
			checkChar(c);
	}
}
