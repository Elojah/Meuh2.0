/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:35:24 by hdezier           #+#    #+#             */
/*   Updated: 2016/09/05 20:14:51 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"
#include "CsvLineParser.h"
#include "SDL_linear.h"

#include <iostream>
#include <fstream>

static int		print_err(e_err err)
{
	switch (err)
	{
		case (e_err::NO_ERR) :
			std::cout << "Execution OK" << std::endl;
			break ;
		case (e_err::BAD_ARG_NUMBER) :
			std::cout << "Usage: ./draw_data filename" << std::endl;
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
	if (split_pos == std::string::npos || split_pos == filename.size() - 1)
		return (filename);
	return (filename.substr(split_pos + 1));
}

static e_err	exec(const char *filename)
{
	const static uint8_t	n_dimension = 2;

	std::ifstream			file_stream(filename, std::ifstream::in);
	std::string				line;

	SDL_linear::t_graph		points;
	while (std::getline(file_stream, line))
	{
		type_csv::csv_params<n_dimension>	csv_line;

		const auto		check_err = CsvLineParser<n_dimension>::read_csv_line(line, csv_line);
		if (check_err != e_err::NO_ERR)
		{
			print_err(check_err);
			continue ;
		}
		points.push_back(std::make_pair(csv_line.at(0), csv_line.at(1)));
	}

	std::ifstream			data_stream;
	data_stream.open("../internal/" + get_file_name_only(filename), std::ifstream::in);
	if (data_stream.fail())
		data_stream.open("internal/" + get_file_name_only(filename), std::ifstream::in);
	std::getline(data_stream, line);
	type_csv::csv_params<n_dimension>	csv_line;
	const auto		check_err = CsvLineParser<n_dimension>::read_csv_line(line, csv_line);
	if (check_err != e_err::NO_ERR)
		return (check_err);

	SDL_linear		draw(640, 400);
	draw.open_window();
	draw.draw_points(points);
	double theta0 = csv_line.at(0);
	double theta1 = csv_line.at(1);
	draw.draw_function(theta0, theta1);
	draw.loop();

	return (e_err::NO_ERR);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (print_err(e_err::BAD_ARG_NUMBER));
	else
		return (print_err(exec(av[1])));
}
