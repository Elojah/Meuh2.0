/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Analyzer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:41:26 by leeios            #+#    #+#             */
/*   Updated: 2016/03/24 14:42:13 by leeios           ###   ########.fr       */
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

#include "Error.hpp"

Analyzer::Analyzer(void)
{
	for (char c = 'A'; c <= 'Z'; ++c)
		m_initValues[c] = eValue::UNDEFINED;
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
			m_initValues[c] = eValue::TRUE;
		else if (c == ' ' || c == '\t')
			continue ;
		else
		{
			err::raise_error(eErr::FATAL, "Unrecognized symbol in initialization");
			return (eErr::FATAL);
		}
	}
	return (eErr::NONE);
}

bool	Analyzer::_calcTest(const char c, state_ctr &initValues, const std::vector<Rule *> rules)
{
	auto value = initValues.find(c);
	if (value != initValues.end())
	{
		if (value->second != eValue::UNDEFINED)
			return (true);
		for (const auto &rule : rules)
		{
			// Modify initValues
			if (!rule->isValid(initValues, rules))
				return (false);
		}
		// TODO: Calculus HERE !!!
	}
	else
		err::raise_error(eErr::FATAL, "Symbol asked doesn't exist");
	return (false);
}

eErr	Analyzer::_calculus(const std::string &line)
{
	for (const auto c : line)
	{
		if (IS_SYMBOL(c))
		{
			state_ctr	testTrue(m_initValues);
			testTrue[c] = eValue::TRUE;
			auto res = _calcTest(c, testTrue, m_rules);
			if (res == true)
			{
				m_initValues = testTrue;
				return (eErr::NONE);
			}
			state_ctr	testFalse(m_initValues);
			testFalse[c] = eValue::FALSE;
			res = _calcTest(c, testFalse, m_rules);
			if (res == true)
			{
				m_initValues = testTrue;
				return (eErr::NONE);
			}
			m_initValues[c] = eValue::UNDEFINED;
			err::raise_error(eErr::FATAL, "No possible value");
			return (eErr::FATAL);
		}
		else if (c == ' ' || c == '\t')
			continue ;
		else
		{
			err::raise_error(eErr::FATAL, "Unrecognized symbol in calculation");
			return (eErr::FATAL);
		}
	}
	// // TEST
	// for (auto rule : m_rules)
	// {
	// 	std::cout << rule->serialize() << std::endl;
	// 	std::cout << rule->serializeEval(m_initValues) << std::endl;
	// }

	return (eErr::NONE);
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
}
