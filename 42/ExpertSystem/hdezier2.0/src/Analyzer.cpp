/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Analyzer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:41:26 by leeios            #+#    #+#             */
/*   Updated: 2016/03/31 20:00:23 by hdezier          ###   ########.fr       */
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
		auto		ruleEvaluation = rule->isValid(m_initValues);
		std::cout << "Test on rule#" << rule->serialize() << std::endl;
		std::cout << "======>" << Symbol::getName(ruleEvaluation) << std::endl;
		if (ruleEvaluation == eValue::FALSE || ruleEvaluation == eValue::FALSE_TEST)
			return (false);
		else if (ruleEvaluation == eValue::TRUE || ruleEvaluation == eValue::TRUE_TEST)
			continue ;
	}
	return (true);
}

eErr	Analyzer::_calculus(const std::string &line)
{
	// Print result with line
	(void)line;
	_setInitSymbols();
	restart : for (const auto &val : m_initValues)
	{
		if (val.second != eValue::UNDEFINED)
			continue ;

		// Error testing
		for (const auto &i : m_initValues)
			std::cout << i.first << " = " << Symbol::getName(i.second) << std::endl;

		std::cout << "Testing value:" << val.first << std::endl;

		m_initValues[val.first] = eValue::TRUE_TEST;
		std::cout << "Is True ? " << val.first << std::endl;
		if (_calcTest(val.first))
		{
			std::cout << "Set value by deduction:" << val.first << " at TRUE" << std::endl;
			m_initValues[val.first] = eValue::TRUE;
			goto restart;
		}
		_resetTestValues();
		
		m_initValues[val.first] = eValue::FALSE_TEST;
		std::cout << "Is False ? " << val.first << std::endl;
		if (_calcTest(val.first))
		{
			std::cout << "Set value by deduction:" << val.first << " at FALSE" << std::endl;
			m_initValues[val.first] = eValue::FALSE;
			goto restart;
		}
		_resetTestValues();

		m_initValues[val.first] = eValue::UNDEFINED;
		std::cout << "Still UNDEFINED... " << val.first << std::endl;
	}
	for (auto &val : m_initValues)
	{
		if (val.second == eValue::TRUE_TEST)
			val.second = eValue::TRUE;
		else if (val.second == eValue::FALSE_TEST || val.second == eValue::UNDEFINED)
			val.second = eValue::FALSE;
	}
	return (eErr::NONE);
}

void	Analyzer::_resetTestValues(void)
{
	for (auto &val : m_initValues)
	{
		if (val.second == eValue::TRUE_TEST || val.second == eValue::FALSE_TEST)
			val.second = eValue::UNDEFINED;
	}
}

void	Analyzer::_setInitSymbols(void)
{
	std::set<char>	allSymbols;
	for (const auto &rule : m_rules)
	{
		auto	symbols = rule->getSymbols();
		for (const auto c : symbols)
			allSymbols.insert(c);
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
