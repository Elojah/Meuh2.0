/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_linear.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 20:09:54 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/27 20:53:24 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL_linear.h"

SDL_linear::~SDL_linear(void)
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

e_err	SDL_linear::open_window(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	m_window = SDL_CreateWindow(
			"ft_linear_regression",                  // window title
			SDL_WINDOWPOS_UNDEFINED,           // initial x position
			SDL_WINDOWPOS_UNDEFINED,           // initial y position
			m_width,                               // width, in pixels
			m_height,                               // height, in pixels
			SDL_WINDOW_SHOWN                  // flags - see below
	);
	if (m_window == nullptr)
		return (e_err::SDL_WINDOW);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr)
		return (e_err::SDL_WINDOW);
	SDL_RenderClear(m_renderer);
	return (e_err::NO_ERR);
}

void	SDL_linear::draw_function(double x, double y)
{
	SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(m_renderer, 0, m_height - x, m_width, m_height - (x + y * m_width));
}

void	SDL_linear::draw_points(const LinearRegression2D::t_graph &graph)
{
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	for (const auto &point : graph)
		SDL_RenderDrawPoint(m_renderer, point.at(0),  m_height - point.at(1));
}

void	SDL_linear::loop(void)
{
	bool		end = false;
	SDL_Event	event;
	SDL_RenderPresent(m_renderer);
	while (!end)
	{
		SDL_WaitEvent(&event);
		if(event.window.event == SDL_WINDOWEVENT_CLOSE)
			end = true;
	}
}
