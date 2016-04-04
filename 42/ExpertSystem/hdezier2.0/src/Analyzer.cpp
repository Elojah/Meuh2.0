/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Analyzer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:41:26 by leeios            #+#    #+#             */
/*   Updated: 2016/04/04 14:42:49 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Test A ->
A is true/false
check rule#1 valid
-> undefined values
-> calc with (rules - rule#1, same state)

*/

#include "Analyzer.hpp"

#include <fstream>
#include <set>

#include "Error.hpp"

Analyzer::Analyzer(void)
{
}

Analyzer::~Analyzer(void)
{
	for (auto rule : m_rules)
		delete (rule);
}

eErr	Analyzer::analyze_file(const std::string &filename)
{
	std::ifstream		ifs(filename);
	std::string			line;
	while (std::getline(ifs, line))
	{
		auto comment = line.find('#');
		if (comment != std::string::npos)
			line = line.substr(0, comment);
		if (line.empty())
			continue ;
		switch (line.at(0))
		{
			case ('#') : break ;
			case ('=') : _set_true(line.substr(1)); break ;
			case ('?') : _calculus(line.substr(1)); break ;
			default : _add_rule(line); break ;
		}
	}
	return (eErr::NONE);
}

eErr	Analyzer::_set_true(const std::string &line)
{
	for (const auto c : line)
	{
		if (IS_SYMBOL(c))
		{
			std::cout << "Value:" << c << " set as TRUE" << std::endl;
			m_initValues[c] = eValue::TRUE;
		}
		else if (c != ' ' && c != '\t')
		{
			err::raise_error(eErr::FATAL, "Unrecognized symbol in initialization");
			return (eErr::FATAL);
		}
	}
	return (eErr::NONE);
}

bool	Analyzer::_calcTest(const char c)
{
	for (const auto &rule : m_rules)
	{
		// if symbol doesn't appear in that rule
		if (rule->getSymbols().find(c) == std::string::npos)
			continue ;
		const std::string	&symbols = rule->getSymbols();
		auto				separator = symbols.find('=');
		// Should never happen
		if (separator == std::string::npos)
			continue ;
		auto				rightSide = symbols.substr(separator);
		if (rightSide.find(c) != std::string::npos)
		{
			if (rule->apply(m_initValues))
			{
				std::cout << "On rule:" << rule->serialize() << std::endl;
				return (true);
			}
		}
	}
	return (false);
}

eErr	Analyzer::_calculus(const std::string &line)
{
	_setInitSymbols();
	// Calc if initial values
	restart : for (const auto &val : m_initValues)
	{
		if (val.second != eValue::UNDEFINED)
			continue ;

		std::cout << "Testing value:" << val.first << std::endl;

		if (_calcTest(val.first))
			goto restart;
	}
	// else set them false
	for (auto &val : m_initValues)
	{
		if (val.second == eValue::UNDEFINED)
			val.second = eValue::FALSE;
	}
	// calc values
	restart_calc : for (const auto c : line)
	{
		if (IS_SYMBOL(c))
		{
			auto	val = m_initValues.find(c);
			if (val != m_initValues.end() && val->second != eValue::UNDEFINED)
				continue ;
			if (_calcTest(c))
				goto restart_calc;
		}
		else if (c != ' ' && c != '\t')
		{
			err::raise_error(eErr::FATAL, "Unrecognized symbol in initialization");
			return (eErr::FATAL);
		}
	}
	// Show results
	std::cout << "Results:" << std::endl;
	for (const auto c : line)
	{
		if (IS_SYMBOL(c))
			std::cout << c << " = " << Symbol::getName(m_initValues[c]) << std::endl;
	}
	return (eErr::NONE);
}

void	Analyzer::_setInitSymbols(void)
{
	std::set<char>	allSymbols;
	for (const auto &rule : m_rules)
	{
		auto	symbols = rule->getSymbols();
		for (const auto c : symbols)
		{
			if (c != '=')
				allSymbols.insert(c);
		}
	}
	for (const auto c : allSymbols)
	{
		auto val = m_initValues.find(c);
		if (val == m_initValues.end())
			m_initValues[c] = eValue::UNDEFINED;
	}
}

eErr	Analyzer::_add_rule(const std::string &line)
{
	Rule	*current_rule;

	current_rule = new Rule;
	if (current_rule->set(line.substr(0, line.find('#'))) == eErr::FATAL)
		return (eErr::FATAL);
	m_rules.push_back(current_rule);
	return (eErr::NONE);
}

void	Analyzer::printRules(void)
{
	std::cout << "N Rules:" << m_rules.size() << std::endl;
	for (const auto &rule : m_rules)
		std::cout << rule->serialize() << std::endl;
	std::cout << "Values:" << m_rules.size() << std::endl;
	for (const auto &val : m_initValues)
		std::cout << val.first << " = " << Symbol::getName(val.second) << std::endl;
	std::cout << "___" << std::endl;
}
