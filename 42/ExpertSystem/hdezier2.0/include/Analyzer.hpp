/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Analyzer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:41:26 by leeios            #+#    #+#             */
/*   Updated: 2016/03/24 14:05:24 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYZER_HPP
# define ANALYZER_HPP

# include <vector>

# include "Rule.hpp"
# include "Expr.hpp"

# include "Error.hpp"

class Analyzer
{
public:
	Analyzer(void);
	virtual ~Analyzer(void);
	virtual eErr	analyze_file(const std::string &filename);
	void			printRules(void);
protected:
private:
	std::vector<Rule *>		m_rules;
	state_ctr				m_initValues;

	eErr	_set_true(const std::string &line);
	eErr	_calculus(const std::string &line);
	eErr	_add_rule(const std::string &line);
};

#endif
