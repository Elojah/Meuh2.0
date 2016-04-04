/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Analyzer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:41:26 by leeios            #+#    #+#             */
/*   Updated: 2016/04/04 14:05:54 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYZER_HPP
# define ANALYZER_HPP

# include <vector>

# include "Rule.hpp"
# include "Expr.hpp"

# include "Error.hpp"

# define IS_SYMBOL(c) ((c) >= 'A' && (c) <= 'Z')

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
	void	_setInitSymbols(void);
	eErr	_add_rule(const std::string &line);
	bool	_calcTest(const char c);
};

#endif
