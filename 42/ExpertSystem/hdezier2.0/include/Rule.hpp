/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rule.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:45:24 by leeios            #+#    #+#             */
/*   Updated: 2016/03/26 17:38:18 by leeios           ###   ########.fr       */
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
	bool			isValid(state_ctr &initStates, const std::vector<Rule *> rules) const;
protected:
private:
	eLinkExpr	m_link;
	IExpr*		m_leftExpr;
	IExpr*		m_rightExpr;

	static const char											m_opSymbols[];
	static const std::map<Rule::eLinkExpr, std::string>			m_linkSymbols;

	static IExpr		*_setExprAsExpr(const std::string &s, size_t symbol);
	static IExpr		*_setExprParenthesis(const std::string &s, Expr<IExpr *> *result, size_t parenthesis);
	static IExpr		*_setExprAsChar(const std::string &s);
	static IExpr		*_setExpr(const std::string &s);
};

#endif
