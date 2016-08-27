/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:35:24 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/27 20:09:17 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"
#include "SDL.h"
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

static void		print_estimation_sdl(int input, int output)
{
	(void)input;
	(void)output;
	SDL_Init(SDL_INIT_VIDEO);
	auto	*window = SDL_CreateWindow(
			"ft_linear_regression",                  // window title
			SDL_WINDOWPOS_UNDEFINED,           // initial x position
			SDL_WINDOWPOS_UNDEFINED,           // initial y position
			640,                               // width, in pixels
			480,                               // height, in pixels
			SDL_WINDOW_SHOWN                  // flags - see below
	);
	if (window == nullptr)
		return ;
	auto	*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(renderer);
	bool		end = false;
	SDL_Event	event;
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, 0, 0, 400, 400);
	SDL_RenderPresent(renderer);
	while (!end)
	{
		SDL_WaitEvent(&event);
		if(event.window.event == SDL_WINDOWEVENT_CLOSE)
			end = true;
	}
	// Close and destroy the window
	SDL_DestroyWindow(window);
	// Clean up
	SDL_Quit();
}

static e_err	exec(const char *filename)
{
	const static uint8_t	n_dimension = 2;

	LinearRegression2D		linear_reg;

	std::ifstream			file_stream(filename, std::ifstream::in);
	std::string				line;

	while (std::getline(file_stream, line))
	{
		type_csv::csv_params<n_dimension>	csv_line;

		const auto		check_err = CsvLineParser<n_dimension>::read_csv_line(line, csv_line);
		if (check_err != e_err::NO_ERR)
		{
			print_err(check_err);
			continue ;
		}
		linear_reg.add_to_data(csv_line);
	}
	linear_reg.learn_from_data();
	// TEST
	for (uint32_t i = 0; i < 600; i += 30)
		print_estimation(i, linear_reg.current_estimation(i));
	// !TEST
	print_estimation_sdl(0, 0);
	return (e_err::NO_ERR);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (print_err(e_err::BAD_ARG_NUMBER));
	else
		return (print_err(exec(av[1])));
}
