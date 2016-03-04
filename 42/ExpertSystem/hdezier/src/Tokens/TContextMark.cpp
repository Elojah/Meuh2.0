/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TContextMark.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:53:26 by leeios            #+#    #+#             */
/*   Updated: 2016/03/04 17:55:15 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TContextMark.hpp"

#include "Parser.hpp"

TContextMark::TContextMark(void)
{
	;
}

TContextMark::~TContextMark(void)
{
	;
}

eResponse		TContextMark::detect(const std::string &str) const
{
	if (_isCtxMarkSymbol(str.at(0)))
	{
		if (str.size() == 1)
			return (eResponse::OK);
		else if (str.compare("=>") != 0)
			return (eResponse::COMPLETE);
	}
	return (eResponse::NONE);
}

void			TContextMark::getNextTokens(tok_indexes &mask) const
{
	Parser::initMask(mask);
}

IToken			*TContextMark::getNewInstance(const std::string &s) const
{
	TContextMark		*result;
	result = new TContextMark;
	result->setStr(s);
	return (result);
}

bool			TContextMark::_isCtxMarkSymbol(const char c)
{
	return (c == '='
		|| c == '?'
		);
}
