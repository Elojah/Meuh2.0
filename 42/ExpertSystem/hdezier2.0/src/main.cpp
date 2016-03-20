/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:40:48 by leeios            #+#    #+#             */
/*   Updated: 2016/03/20 11:56:45 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Error.hpp"
#include "Analyzer.hpp"

const static std::string		printEValue(eValue e)
{
	static const char	*arrayEvalue[] =
	{
		"UNDEFINED",
		"TRUE",
		"FALSE",
		"ERROR"
	};
	return (arrayEvalue[(int)e]);
}
static void		exec(const std::string &filename)
{
	(void)filename;

	state_ctr			initStates =
	{
		{'A', eValue::FALSE},
		{'C', eValue::FALSE}
	};

	Expr<char, char>	test;
	test.setLeftOperand('A');
	test.setLeftOperand('C');
	test.setOperator('|');
	std::cout << printEValue(test.eval()) << std::endl;

	Expr<IExpr *, IExpr *>	testExpr;
	testExpr.setLeftOperand(&test);
	testExpr.setLeftOperand(&test);
	testExpr.setOperator('^');
	std::cout << printEValue(testExpr.eval()) << std::endl;

};

// static void		exec(const std::string &filename)
// {
// 	Analyzer	a;

// 	a.analyze_file(filename);
// }

int			main(int ac, char **av)
{
	if (ac != 2)
		err::raise_error(eErr::FATAL, "You must specify one filename");
	else
		exec(av[1]);
	return (0);
}
