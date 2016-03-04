/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:53:34 by leeios            #+#    #+#             */
/*   Updated: 2016/03/04 17:56:22 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TOperator.hpp"

#include "Parser.hpp"

TOperator::TOperator(void)
{
	;
}

TOperator::~TOperator(void)
{
	;
}

eResponse		TOperator::detect(const std::string &str) const
{
	if (_isOperatorSymbol(str.at(0)))
	{
		if (str.size() == 1)
			return (eResponse::OK);
		else
			return (eResponse::COMPLETE);
	}
	return (eResponse::NONE);
}

void			TOperator::getNextTokens(tok_indexes &mask) const
{
	Parser::initMask(mask);
}

IToken			*TOperator::getNewInstance(const std::string &s) const
{
	TOperator		*result;
	result = new TOperator;
	result->setStr(s);
	return (result);
}

bool			TOperator::_isOperatorSymbol(const char c)
{
	return (c == '+'
		|| c == '|'
		|| c == '^'
		);
}
