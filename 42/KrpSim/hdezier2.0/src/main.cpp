/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 00:45:43 by leeios            #+#    #+#             */
/*   Updated: 2016/07/14 10:02:55 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "krpsim.h"

#include <fstream>
#include <iostream>
#include "Interpreter.h"
#include "JobShopManager.h"

static int		err_exit(const e_err err, uint32_t line)
{
	if (err != e_err::NONE)
		std::cerr << "\033[31mERROR\033[30m[\033[0mLINE:\033[34m" << (unsigned int)line << "\033[30m]\033[0m\t";
	switch (err)
	{
		case (e_err::NONE) : return (EXIT_SUCCESS);
		case (e_err::BAD_ARG_NUMBER) : std::cerr << "Usage: ./krpsim [filename]" << std::endl;
		break ;
		case (e_err::OPEN_FAILED) : std::cerr << "Can't open file" << std::endl;
		break ;
		case (e_err::E_ERR) : std::cerr << "Unknown error" << std::endl;
		break ;
		case (e_err::RESOURCE_NAME_NOT_FOUND) : std::cerr << "Can't identify resource name " << std::endl;
		break ;
		case (e_err::TASK_DEFINITION_SYNTAX_NEED) : std::cerr << "Can't identify needs for task" << std::endl;
		break ;
		case (e_err::TASK_DEFINITION_SYNTAX_PRODUCT) : std::cerr << "Can't identify products for task" << std::endl;
		break ;
		case (e_err::TASK_DEFINITION_SYNTAX_TIME) : std::cerr << "Can't identify time for task" << std::endl;
		break ;
		case (e_err::TASK_DUPLICAT) : std::cerr << "This task name already exist" << std::endl;
		break ;
		case (e_err::RESOURCE_DEFINITION) : std::cerr << "Syntax error on resource definition" << std::endl;
		break ;
		case (e_err::OPTIMIZE_NOT_DEFINED) : std::cerr << "Can't optimize this resource" << std::endl;
		break ;
		case (e_err::OPTIMIZE_SYNTAX_ERR) : std::cerr << "Syntax error on optimization definition" << std::endl;
		break ;
		case (e_err::DEBUG) : std::cerr << "DEBUG" << std::endl;
		break ;
		case (e_err::TODO) : std::cerr << "TODO" << std::endl;
		break ;
	}
	return (EXIT_FAILURE);
}

static int	exec(const char *filename)
{
	JobShopManager				jsm;
	Interpreter<decltype(jsm)>	reader(jsm);
	std::string					line;
	std::ifstream				ifs(filename);
	uint32_t					nLine(1);

	if (ifs.fail())
		return (err_exit(e_err::OPEN_FAILED, 0));
	while (std::getline(ifs, line))
	{
		const e_err err = reader.read_line(line, false);
		if (err != e_err::NONE)
			return (err_exit(err, nLine));
		++nLine;
	}
	return (err_exit(e_err::NONE, 0));
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (err_exit(e_err::BAD_ARG_NUMBER, 0));
	return (exec(av[1]));
}
