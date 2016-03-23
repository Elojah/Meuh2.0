/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rule.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 10:08:13 by leeios            #+#    #+#             */
/*   Updated: 2016/03/20 13:01:18 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rule.hpp"

Rule::Rule(void)
{
	(void)m_rightExpr;
	(void)m_link;
}

Rule::~Rule(void)
{
	;
}

eErr	Rule::set(const std::string &line)
{
	IExpr	*currentExpr = m_leftExpr;
	(void)currentExpr;

	for (const auto c : line)
	{
		if (isalpha(c))
		(void)c;
	}
	return (eErr::NONE);
}

eErr	Rule::_addSymbol(IExpr *expr, char c)
{
	(void)expr;
	(void)c;
	return (eErr::NONE);
}
