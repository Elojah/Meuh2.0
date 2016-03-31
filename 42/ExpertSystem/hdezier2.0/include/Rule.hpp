/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rule.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:45:24 by leeios            #+#    #+#             */
/*   Updated: 2016/03/31 18:38:05 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULE_HPP
# define RULE_HPP

#include <vector>

#include "Expr.hpp"

class Rule
{
public:

	enum class eLinkExpr
	{
		NONE = 0,
		IMPLIES,
		IF_ONLY_IF
	};

	Rule(void);
	virtual ~Rule(void);
	virtual eErr	set(const std::string &line);
	std::string		serialize(void);
	std::string		serializeEval(const state_ctr &initStates);
	eValue			isValid(state_ctr &initStates) const;

	inline const std::string	&getSymbols(void) const {return (m_presentSymbols);};

protected:
private:
	eLinkExpr	m_link;
	IExpr*		m_leftExpr;
	IExpr*		m_rightExpr;


	std::string													m_presentSymbols;
	static const char											m_opSymbols[];
	static const std::map<Rule::eLinkExpr, std::string>			m_linkSymbols;

	IExpr			*_setExprAsExpr(const std::string &s, size_t symbol);
	IExpr			*_setExprParenthesis(const std::string &s, Expr<IExpr *> *result, size_t parenthesis);
	IExpr			*_setExprAsChar(const std::string &s);
	IExpr			*_setExpr(const std::string &s);
};

#endif
