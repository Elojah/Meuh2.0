/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_linear.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 20:09:54 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/27 20:13:36 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL_linear.h"

SDL_linear::SDL_linear(uint16_t width, uint16_t height)
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

SDL_linear::~SDL_linear(void)
{
	;
}
