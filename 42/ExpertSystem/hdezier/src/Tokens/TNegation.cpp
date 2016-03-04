/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TNegation.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:56:58 by leeios            #+#    #+#             */
/*   Updated: 2016/03/04 17:59:05 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TNegation.hpp"

#include "Parser.hpp"

TNegation::TNegation(void)
{
	;
}

TNegation::~TNegation(void)
{
	;
}

eResponse		TNegation::detect(const std::string &str) const
{
	if (_isNegationSymbol(str.at(0)))
	{
		if (str.size() == 1)
			return (eResponse::OK);
		else
			return (eResponse::COMPLETE);
	}
	return (eResponse::NONE);
}

void			TNegation::getNextTokens(tok_indexes &mask) const
{
	Parser::initMask(mask);
}

IToken			*TNegation::getNewInstance(const std::string &s) const
{
	TNegation		*result;
	result = new TNegation;
	result->setStr(s);
	return (result);
}

bool			TNegation::_isNegationSymbol(const char c)
{
	return (c == '!');
}
