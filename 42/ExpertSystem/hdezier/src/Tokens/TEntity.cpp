/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:24:40 by leeios            #+#    #+#             */
/*   Updated: 2016/03/03 21:06:18 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TEntity.hpp"

#include <cctype>

#include "Parser.hpp"

TEntity::TEntity(void)
{
	;
}

TEntity::~TEntity(void)
{
	;
}

eResponse		TEntity::detect(const std::string &str) const
{
	if (std::isalnum(str.back()))
		return (eResponse::OK);
	else if (std::isalnum(str.at(0)))
		return (eResponse::COMPLETE);
	else
		return (eResponse::NONE);
}

void			TEntity::getNextTokens(tok_indexes &mask) const
{
	Parser::initMask(mask);
}

IToken			*TEntity::getNewInstance(const std::string &s) const
{
	TEntity		*result;
	result = new TEntity;
	result->setStr(s);
	return (result);
}
