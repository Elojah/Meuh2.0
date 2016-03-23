/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Analyzer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:41:26 by leeios            #+#    #+#             */
/*   Updated: 2016/03/20 13:06:09 by leeios           ###   ########.fr       */
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
	;
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
			case ('=') : _set_true(line); break ;
			case ('?') : _calculus(line); break ;
			default : _add_rule(line); break ;
		}
	}
	return (eErr::NONE);
}

eErr	Analyzer::_set_true(const std::string &line)
{
	(void)line;
	return (eErr::NONE);
}

eErr	Analyzer::_calculus(const std::string &line)
{
	(void)line;
	return (eErr::NONE);
}

eErr	Analyzer::_add_rule(const std::string &line)
{
	Rule	*current_rule;

	current_rule = new Rule;
	if (current_rule->set(line) == eErr::FATAL)
		return (eErr::FATAL);
	return (eErr::NONE);
}
