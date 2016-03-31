/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Analyzer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:41:26 by leeios            #+#    #+#             */
/*   Updated: 2016/03/29 15:29:08 by hdezier          ###   ########.fr       */
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
		else if (c != ' ' && c != '\t')
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
		for (const auto &rule : rules)
		{
			std::string		valuesRequired;
			eValue			val = rule->isValid(initValues, valuesRequired);
			switch (val)
			{
			case (eValue::FALSE) : return (false);
			case (eValue::TRUE) : break ;
			case (eValue::UNDEFINED) :
				std::cout << "Rule:" + rule->serialize() << std::endl;
				std::cout << "need:" + valuesRequired << std::endl;
				break ;
			default : break ;
			}
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
			std::cout << "Search value:" << c << std::endl;
			if (m_initValues[c] != eValue::UNDEFINED)
			{
				m_initValues[c] = eValue::FALSE;
				continue ;
			}
			state_ctr	testTrue(m_initValues);
			testTrue[c] = eValue::TRUE;
			auto res = _calcTest(c, testTrue, m_rules);
			if (res == true)
			{
				m_initValues = testTrue;
				continue ;
			}
			state_ctr	testFalse(m_initValues);
			testFalse[c] = eValue::FALSE;
			res = _calcTest(c, testFalse, m_rules);
			if (res == true)
			{
				m_initValues = testTrue;
				continue ;
			}
			m_initValues[c] = eValue::UNDEFINED;
			err::raise_error(eErr::FATAL, "No possible value");
		}
		else if (c != ' ' && c != '\t')
		{
			err::raise_error(eErr::FATAL, "Unrecognized symbol in calculation");
			return (eErr::FATAL);
		}
	}
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
	std::cout << "Values:" << m_rules.size() << std::endl;
	for (const auto &val : m_initValues)
		std::cout << val.first << " = " << (int)val.second << std::endl;
}
