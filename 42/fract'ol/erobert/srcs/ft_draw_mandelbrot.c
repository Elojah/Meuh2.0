/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:23:05 by erobert           #+#    #+#             */
/*   Updated: 2015/01/30 17:37:34 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_draw_mandelbrot(t_data *d, int x, int y)
{
	double		tmp[3];
	double		z[2];
	double		z2[2];
	int			i;

	tmp[2] = 2.0 / d->size / d->zoom;
	tmp[0] = -1.0 + x * tmp[2] + 2.0 * d->fract.pos[0] - 1 / d->zoom;
	tmp[1] = y * tmp[2] + 2.0 * d->fract.pos[1] - 1 / d->zoom;
	z[0] = 0;
	z[1] = 0;
	z2[0] = 0;
	z2[1] = 0;
	i = -1;
	while (++i < d->max_iter && (z2[0] + z2[1]) < 4)
	{
		z[1] = 2 * z[0] * z[1] + tmp[1];
		z[0] = z2[0] - z2[1] + tmp[0];
		z2[0] = z[0] * z[0];
		z2[1] = z[1] * z[1];
	}
	return (i);
}
