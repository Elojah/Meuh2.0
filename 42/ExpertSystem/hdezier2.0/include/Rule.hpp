/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rule.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:45:24 by leeios            #+#    #+#             */
/*   Updated: 2016/03/20 17:19:38 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULE_HPP
# define RULE_HPP

#include "Expr.hpp"

class Rule
{
	enum class eLinkExpr
	{
		IMPLIES = 0,
		IF_ONLY_IF
	};

public:
	Rule(void);
	virtual ~Rule(void);
	virtual eErr	set(const std::string &line);
protected:
private:
	IExpr*		m_leftExpr;
	IExpr*		m_rightExpr;
	eLinkExpr	m_link;

	virtual eErr	_addSymbol(IExpr *expr, char c);
};

#endif
