/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TPriorities.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:14:05 by leeios            #+#    #+#             */
/*   Updated: 2016/03/04 17:41:37 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TPriorities.hpp"

#include "Parser.hpp"

TPriorities::TPriorities(void)
{
	;
}

TPriorities::~TPriorities(void)
{
	;
}

eResponse		TPriorities::detect(const std::string &str) const
{
	if (_isPrioritySymbol(str.at(0)))
	{
		if (str.size() == 1)
			return (eResponse::OK);
		else
			return (eResponse::COMPLETE);
	}
	return (eResponse::NONE);
}

void			TPriorities::getNextTokens(tok_indexes &mask) const
{
	Parser::initMask(mask);
}

IToken			*TPriorities::getNewInstance(const std::string &s) const
{
	TPriorities		*result;
	result = new TPriorities;
	result->setStr(s);
	return (result);
}

bool			TPriorities::_isPrioritySymbol(const char c)
{
	return (c == ')'
		|| c == '('
		);
}
