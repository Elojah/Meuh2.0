/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_linear.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 20:10:03 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/28 19:39:31 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_LINEAR_H
# define SDL_LINEAR_H

#include "SDL.h"
#include "err.h"
# include <stdint.h>
# include <vector>

class SDL_linear
{
public:

	typedef std::pair<double, double>		t_coordinates;
	typedef std::vector<t_coordinates>		t_graph;

	inline SDL_linear(uint16_t width, uint16_t height)
		: m_width(width)
		, m_height(height) {};
	~SDL_linear(void);
	e_err	open_window(void);
	void	loop(void);
	void	draw_function(double x, double y);
	void	draw_points(const t_graph &graph);

private:
	SDL_Window		*m_window;
	SDL_Renderer	*m_renderer;
	const uint16_t	m_width;
	const uint16_t	m_height;
};

#endif
