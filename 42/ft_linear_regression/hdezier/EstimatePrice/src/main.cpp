/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:35:24 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/28 19:06:09 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CsvLineParser.h"
#include "err.h"

#include <iostream>
#include <iomanip>
#include <fstream>

static int		print_err(e_err err)
{
	switch (err)
	{
		case (e_err::NO_ERR) :
			std::cout << "Execution OK" << std::endl;
			break ;
		case (e_err::BAD_ARG_NUMBER) :
			std::cout << "Usage: ./ft_linear_regression filename" << std::endl;
			break ;
		case (e_err::BAD_FORMAT_CSV_INT) :
			std::cout << "Coordinate can't be read" << std::endl;
			break ;
		case (e_err::BAD_CSV_INT_NUMBER) :
			std::cout << "Bad number of coordinates" << std::endl;
			break ;
		case (e_err::SDL_WINDOW) :
			std::cout << "SDL window error" << std::endl;
			break ;
	}
	return (0);
}

static const std::string	get_file_name_only(const std::string &filename)
{
	const auto	split_pos = filename.find_last_of("/");
	if (split_pos == std::string::npos)
		return (filename);
	return (filename.substr(split_pos));
}

static e_err	exec(const char *filename)
{
	const static uint8_t	n_dimension = 2;

	std::ifstream			file_stream(
		"../internal/" + get_file_name_only(filename)
		, std::ifstream::in);
	if (file_stream.fail())
		return (e_err::BAD_ARG_NUMBER);
	std::string				line;

	type_csv::csv_params<n_dimension>	csv_line;
	std::getline(file_stream, line);
	std::cerr << line << std::endl;
	const auto		check_err = CsvLineParser<n_dimension>::read_csv_line(line, csv_line);
	if (check_err != e_err::NO_ERR)
		return (check_err);

	double theta0 = csv_line.at(0);
	double theta1 = csv_line.at(1);
	line.clear();
	while (true)
	{
		std::cout << ">";
		std::cin >> line;
		if (line == "quit")
			break ;
		double x = 0;
		try
		{
			x = std::stod(line);
		}
		catch (...)
		{
			std::cout << "Bad value" << std::endl;
			continue ;
		}
		std::cout << std::setprecision(10) << theta0 + theta1 * x << std::endl;
	}

	return (e_err::NO_ERR);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (print_err(e_err::BAD_ARG_NUMBER));
	else
		return (print_err(exec(av[1])));
}
