/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TComment.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:22:56 by leeios            #+#    #+#             */
/*   Updated: 2016/03/03 20:26:28 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TComment.hpp"

#include <cstring>

#include "Parser.hpp"

TComment::TComment(void)
{
	;
}

TComment::~TComment(void)
{
	;
}

eResponse		TComment::detect(const std::string &str) const
{
	if (str.back() == '\0')
		return (eResponse::COMPLETE);
	if (str.at(0) == '#')
		return (eResponse::OK);
	return (eResponse::NONE);
}

void			TComment::getNextTokens(tok_indexes &mask) const
{
	Parser::initMask(mask);
}

IToken			*TComment::getNewInstance(const std::string &s) const
{
	TComment		*result;
	result = new TComment;
	result->setStr(s);
	return (result);
}
