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

#include "Analyzer.hpp"

#include <fstream>

#include "Error.hpp"

Analyzer::Analyzer(void)
{
	;
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
		if (line.empty())
			continue ;
		switch (line.at(0))
		{
			case ('#') : break ;
			case ('=') : _set_true(line); break ;
			case ('?') : _calculus(line); break ;
			default : _add_rule(line); break ;
		}
	}
	return (eErr::NONE);
}

eErr	Analyzer::_set_true(const std::string &line)
{
	for (const auto c : line)
	{
		if (isalpha(c))
			m_initValues[c] = eValue::TRUE;
	}
	return (eErr::NONE);
}

eErr	Analyzer::_calculus(const std::string &line)
{
	(void)line;
	// for (const auto c : line)
	// {
	// 	if (isalpha(c))
	// 	{
	// 	}
	// }
	for (auto rule : m_rules)
	{
		std::cout << rule->serialize() << std::endl;
		std::cout << rule->serializeEval(m_initValues) << std::endl;
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
}
