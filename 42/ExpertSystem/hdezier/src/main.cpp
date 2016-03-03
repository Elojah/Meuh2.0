/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:16:14 by leeios            #+#    #+#             */
/*   Updated: 2016/03/03 19:07:13 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Error.hpp"
#include "Parser.hpp"
#include <fstream>

static void		exec(char *filename)
{
	Parser		parser;
	parser.exec(filename);
	parser.printResult();
}

int			main(int ac, char **av)
{
	if (ac != 2)
		Error::raise_error(eErr::NOT_ENOUGH_ARGS, "You must specify one filename");
	else
		exec(av[1]);
	return (0);
}
