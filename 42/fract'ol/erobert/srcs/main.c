/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:10:39 by erobert           #+#    #+#             */
/*   Updated: 2015/01/30 20:08:23 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fractol.h"

static int		expose_hook(t_data *d)
{
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img.ptr, 0, 0);
	return (0);
}

static int		ft_mouse_motion(int x, int y, t_data *d)
{
	if (d->aut)
	{
		if (x < d->size / 2)
			d->fract.p[0] += .001;
		else
			d->fract.p[0] -= .001;
		if (y < d->size / 2)
			d->fract.p[1] += .001;
		else
			d->fract.p[1] -= .001;
		ft_draw_fractol(d);
		expose_hook(d);
	}
	return (0);
}

static int		ft_mouse_hook(int button, int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	if (button > 0 && button < 4)
		ft_change_color(d->color, button);
	if (d->aut && button > 3)
		ft_change_color(d->color, d->aut);
	if (button == 4)
	{
		d->max_iter += 1;
		d->zoom += 0.1;
	}
	if (button == 5 && d->zoom > 0.5)
	{
		d->max_iter -= 1;
		d->zoom -= 0.1;
	}
	ft_draw_fractol(d);
	expose_hook(d);
	return (0);
}

static int		ft_key_hook(int key, t_data *d)
{
	if (key == 65307)
		exit(1);
	else if (key == 'a')
		d->aut = (d->aut + 1) % 4;
	else if (key == 'n')
		d->fract.type = (d->fract.type + 1) % NUM_TYPE;
	else if (key == 65365)
		d->max_iter += 8;
	else if (key == 65366)
		d->max_iter -= 8;
	else if (key == 65362)
		d->fract.pos[1] -= 0.1;
	else if (key == 65364)
		d->fract.pos[1] += 0.1;
	else if (key == 65361)
		d->fract.pos[0] -= 0.1;
	else if (key == 65363)
		d->fract.pos[0] += 0.1;
	ft_draw_fractol(d);
	expose_hook(d);
	return (0);
}

int				main(int ac, char **av)
{
	t_data		d;
	t_img		*i;

	if (ft_parser(ac, av, &d))
		return (0);
	d.mlx_ptr = mlx_init();
	if (!d.mlx_ptr)
		return (ft_error("Mlx init error", -1));
	d.mlx_win = mlx_new_window(d.mlx_ptr, d.size, d.size, "frat'ol");
	if (d.mlx_win == 0)
		return (ft_error("Win init error", -1));
	d.img.ptr = mlx_new_image(d.mlx_ptr, d.size, d.size);
	if (!d.img.ptr)
		return (ft_error("Img init error", -1));
	i = &d.img;
	i->data = mlx_get_data_addr(i->ptr, &i->bpp, &i->line, &i->endian);
	ft_draw_fractol(&d);
	mlx_mouse_hook(d.mlx_win, ft_mouse_hook, &d);
	mlx_key_hook(d.mlx_win, ft_key_hook, &d);
	mlx_hook(d.mlx_win, 6, (1L << 6), ft_mouse_motion, &d);
	mlx_expose_hook(d.mlx_win, expose_hook, &d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
