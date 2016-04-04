/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rule.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 10:08:13 by leeios            #+#    #+#             */
/*   Updated: 2016/04/04 14:30:12 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rule.hpp"

#include <algorithm>

const char												Rule::m_opSymbols[] = "+|^";
const std::map<Rule::eLinkExpr, std::string>			Rule::m_linkSymbols =
{
	{Rule::eLinkExpr::IMPLIES, "=>"},
	{Rule::eLinkExpr::IF_ONLY_IF, "<=>"}
};

Rule::Rule(void)
	: m_link(eLinkExpr::NONE)
	, m_leftExpr(nullptr)
	, m_rightExpr(nullptr)
{
}

Rule::~Rule(void)
{
	// if (m_leftExpr != nullptr)
	// 	delete (m_leftExpr);
	// if (m_rightExpr != nullptr)
	// 	delete (m_rightExpr);
}

std::string	Rule::serialize(void)
{
	std::string		link;
	auto hasLink = Rule::m_linkSymbols.find(m_link);
	if (hasLink != Rule::m_linkSymbols.end())
		link = hasLink->second;
	else
		link = "XXX";
	return (m_leftExpr->serialize() + link + m_rightExpr->serialize());
}

std::string	Rule::serializeEval(const state_ctr &initStates)
{
	std::string	result;
	switch (m_leftExpr->eval(initStates))
	{
		case(eValue::UNDEFINED) :
			result += "UNDEFINED";
			break ;
		case(eValue::TRUE) :
			result += "TRUE";
			break ;
		case(eValue::FALSE) :
			result += "FALSE";
			break ;
		case(eValue::ERROR) :
			result += "ERROR";
			break ;
	}
	std::string		link;
	auto hasLink = Rule::m_linkSymbols.find(m_link);
	if (hasLink != Rule::m_linkSymbols.end())
		link = hasLink->second;
	else
		link = "XXX";
	result += link;
	switch (m_rightExpr->eval(initStates))
	{
		case(eValue::UNDEFINED) :
			result += "UNDEFINED";
			break ;
		case(eValue::TRUE) :
			result += "TRUE";
			break ;
		case(eValue::FALSE) :
			result += "FALSE";
			break ;
		case(eValue::ERROR) :
			result += "ERROR";
			break ;
	}
	return(result);
}

bool	Rule::apply(state_ctr &initValues)
{
	auto	leftVal = _evalLeft(initValues);
	switch (leftVal)
	{
		case (eValue::UNDEFINED) :
			return (false);
		case (eValue::TRUE) :
			m_rightExpr->setAll(eValue::TRUE, initValues);
			return (true);
		case (eValue::FALSE) :
			m_rightExpr->setAll(eValue::FALSE, initValues);
			return (true);
		case (eValue::ERROR) :
			return (false);
	}
}

/*
** Set expressions
*/
eErr	Rule::set(const std::string &line)
{
	size_t		separator;
	size_t		linkSize;
	for (const auto &link : Rule::m_linkSymbols)
	{
		separator = line.find(link.second);
		if (separator != std::string::npos)
		{
			m_link = link.first;
			linkSize = link.second.size();
			goto sep_found;
		}
	}
	err::raise_error(eErr::FATAL, "No implication found");
	return (eErr::FATAL);

	sep_found:
	m_leftExpr = _setExpr(line.substr(0, separator));
	// Add separator to better side detection
	m_presentSymbols += '=';
	m_rightExpr = _setExpr(line.substr(separator + linkSize));

	// Remove duplicates
	std::sort(m_presentSymbols.begin(), m_presentSymbols.end());
	m_presentSymbols.erase(std::unique(m_presentSymbols.begin(), m_presentSymbols.end()), m_presentSymbols.end());

	return (eErr::NONE);
}

IExpr	*Rule::_setExprAsChar(const std::string &s)
{
	auto result = new Expr<char>;
	for (const char &c : s)
	{
		if (c == ' ' || c == '\t' || c == '\r')
			continue ;
		else if (c == '!')
		{
			result->setLeftNegative(true);
			continue ;
		}
		else if (!isalpha(c))
		{
			delete result;
			err::raise_error(eErr::FATAL, "Character can't be identified as symbol");
			return (nullptr);
		}
		result->setLeftOperand(c);
		m_presentSymbols += c;
		return (result);
	}
	return (nullptr);
}

IExpr	*Rule::_setExprParenthesis(const std::string &s, Expr<IExpr *> *result, size_t parenthesis)
{
	size_t	parenthesisEnd = s.find(')');
	if (parenthesisEnd == std::string::npos)
	{
		delete result;
		err::raise_error(eErr::FATAL, "Parenthesis without end");
		return (nullptr);
	}
	result->setLeftOperand(_setExpr(s.substr(parenthesis + 1, parenthesisEnd)));
	if (parenthesisEnd < s.size())
	{
		auto	rightSide = s.substr(parenthesisEnd + 1);
		auto symbol = rightSide.find_first_of(Rule::m_opSymbols);
		if (symbol != std::string::npos)
		{
			result->setOperator(rightSide.at(symbol));
			result->setRightOperand(_setExpr(rightSide.substr(symbol + 1)));
		}
	}
	return (result);
}

IExpr	*Rule::_setExprAsExpr(const std::string &s, size_t symbol)
{
	auto result = new Expr<IExpr *>;

	size_t	parenthesis = s.find('(');
	if (parenthesis != std::string::npos)
	{
		for (const char &c : s)
		{
			if (c == ' ' || c == '\t' || c == '\r')
				continue ;
			else if (c == '!')
			{
				result->setLeftNegative(true);
				continue ;
			}
			else if (c == '(')
				return (_setExprParenthesis(s, result, parenthesis));
			else
				break ;
		}
	}
	result->setOperator(s.at(symbol));
	result->setLeftOperand(_setExpr(s.substr(0, symbol)));
	result->setRightOperand(_setExpr(s.substr(symbol + 1)));
	return (result);
}

IExpr	*Rule::_setExpr(const std::string &s)
{
	size_t	symbol = s.find_first_of(Rule::m_opSymbols);
	if (symbol == std::string::npos)
		return (_setExprAsChar(s));
	else
		return (_setExprAsExpr(s, symbol));
}
