/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:23:04 by erobert           #+#    #+#             */
/*   Updated: 2015/02/02 13:49:24 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_get_color(int *color)
{
	int				i;

	i = -1;
	while (++i < 256)
	{
		color[i] = (int)(i + 512 - 512 * exp(-i / 50.0) / 3.0);
		color[i] = color[i] << 16 | color[i] << 8 | color[i];
	}
	color[255] = 0;
}

static int			ft_get_fractal(char **av, t_data *d)
{
	d->fract.pos[0] = 0;
	d->fract.pos[1] = 0;
	ft_get_color(d->color);
	d->fract.p[0] = -.7;
	d->fract.p[1] = .27015;
	if (!ft_strcmp(av[1], "julia"))
		d->fract.type = JULIA;
	else if (!ft_strcmp(av[1], "mandelbrot"))
		d->fract.type = MANDELBROT;
	else if (!ft_strcmp(av[1], "carpet"))
	{
		d->fract.p[0] = 0;
		d->fract.p[1] = 0;
		d->fract.type = CARPET;
	}
	else if (!ft_strcmp(av[1], "sierpinski"))
		d->fract.type = SIERPINSKI;
	else
		return (-1);
	return (0);
}

static int			ft_get_size(char **av, t_data *d)
{
	d->size = ft_atoi(av[2]);
	if (d->size > 1138)
		return (ft_error("Size must be less than or equal to 1138", -1));
	return (ft_get_fractal(av, d));
}

int					ft_parser(int ac, char **av, t_data *d)
{
	int				res;

	res = -1;
	d->max_iter = 64;
	d->zoom = 1;
	d->size = 512;
	d->aut = 0;
	if (ac == 2)
		res = ft_get_fractal(av, d);
	if (ac == 3)
		res = ft_get_size(av, d);
	if (res)
	{
		ft_putstr_fd("Arg fractol: {julia, mandelbrot, carpet", 2);
		ft_putstr_fd(", sierpinski}", 2);
		return (ft_error(" [size]", -1));
	}
	return (0);
}
