/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:14:05 by erobert           #+#    #+#             */
/*   Updated: 2015/01/30 18:17:01 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_draw_fractol(t_data *d)
{
	int				x;
	int				y;
	int				i;

	x = -1;
	while (++x < d->size)
	{
		y = -1;
		while (++y < d->size)
		{
			if (d->fract.type == JULIA)
				i = ft_draw_julia(d, x, y);
			else if (d->fract.type == MANDELBROT)
				i = ft_draw_mandelbrot(d, x, y);
			else if (d->fract.type == CARPET)
				i = ft_draw_carpet(d, x, y);
			else
				i = ft_draw_sierpinski(d, x, y);
			ft_put_pixel_to_image(d, x, y, d->color[i % 256]);
		}
	}
}
