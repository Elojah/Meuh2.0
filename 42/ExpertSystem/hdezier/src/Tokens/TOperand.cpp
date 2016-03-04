/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:52:45 by leeios            #+#    #+#             */
/*   Updated: 2016/03/04 17:41:34 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TOperand.hpp"

#include <algorithm>

#include "Parser.hpp"

TOperand::TOperand(void)
{
	;
}

TOperand::~TOperand(void)
{
	;
}

eResponse		TOperand::detect(const std::string &str) const
{
	static const std::string	symbolEq("<=>");
	static const std::string	symbolIm("=>");
	// Must use int for std::min
	int							sizeStr = str.size();
	int							sizeToCompare = std::min(sizeStr, 3);
	if (symbolEq.compare(0, sizeToCompare, str.c_str(), sizeToCompare) == 0)
	{
		if (str.size() > 3)
			return (eResponse::COMPLETE);
		else
			return (eResponse::OK);
	}
	sizeToCompare = std::min(sizeStr, 2);
	if (symbolIm.compare(0, sizeToCompare, str.c_str(), sizeToCompare) == 0)
	{
		if (str.size() > 2)
			return (eResponse::COMPLETE);
		else
			return (eResponse::OK);
	}
	std::cerr << "NONE" << std::endl;
	return (eResponse::NONE);
}

void			TOperand::getNextTokens(tok_indexes &mask) const
{
	Parser::initMask(mask);
}

IToken			*TOperand::getNewInstance(const std::string &s) const
{
	TOperand		*result;
	result = new TOperand;
	result->setStr(s);
	return (result);
}
