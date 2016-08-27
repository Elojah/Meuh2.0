/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:35:24 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/15 01:18:13 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"
#include "CsvLineParser.h"
#include "LinearRegression2D.h"

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
			std::cout << "Usage: ./ft_linear_regression filename" << std::endl;
			break ;
		case (e_err::BAD_FORMAT_CSV_INT) :
			std::cout << "Coordinate can't be read" << std::endl;
			break ;
		case (e_err::BAD_CSV_INT_NUMBER) :
			std::cout << "Bad number of coordinates" << std::endl;
			break ;
	}
	return (0);
}

static void		print_estimation(int input, int output)
{
	std::cout << input << ": " << output << std::endl;
}

#include "tuple_helper.h"
#include "GradientDescent.h"
static e_err	exec(const char *filename)
{
	(void)filename;
	typedef tuple_helper::types<uint32_t, float, char> feature_types;
	GradientDescent<feature_types>::iter(data, {0, 0}, 0.001);
	return (e_err::NO_ERR);
}
// static e_err	exec(const char *filename)
// {
// 	const static uint8_t	n_dimension = 2;

// 	LinearRegression2D		linear_reg;

// 	std::ifstream			file_stream(filename, std::ifstream::in);
// 	std::string				line;

// 	while (std::getline(file_stream, line))
// 	{
// 		type_csv::csv_params<n_dimension>	csv_line;

// 		const auto		check_err = CsvLineParser<n_dimension>::read_csv_line(line, csv_line);
// 		if (check_err != e_err::NO_ERR)
// 		{
// 			print_err(check_err);
// 			continue ;
// 		}
// 		linear_reg.add_to_data(csv_line);
// 	}
// 	linear_reg.learn_from_data();
// 	// TEST
// 	for (uint32_t i = 0; i < 600; i += 30)
// 		print_estimation(i, linear_reg.current_estimation(i));
// 	// !TEST
// 	return (e_err::NO_ERR);
// }

int		main(int ac, char **av)
{
	if (ac != 2)
		return (print_err(e_err::BAD_ARG_NUMBER));
	else
		return (print_err(exec(av[1])));
}
