/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:10:39 by erobert           #+#    #+#             */
/*   Updated: 2015/01/20 19:29:38 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

static int		expose_hook(t_data *d)
{
	ft_draw_map(d);
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img.ptr, 0, 0);
	mlx_destroy_image(d->mlx_ptr, d->img.ptr);
	d->img.ptr = mlx_new_image(d->mlx_ptr, d->size[0], d->size[1]);
	return (0);
}

static void		key_view(int key, t_data *d, int s)
{
	if (key == 65451)
		d->scale += s / 10;
	if (key == 65453)
		d->scale -= s / 10;
	if (key == 65362)
		d->pos[1] -= s;
	if (key == 65364)
		d->pos[1] += s;
	if (key == 65363)
		d->pos[0] += s;
	if (key == 65361)
		d->pos[0] -= s;
	if (key == 65367)
		d->angle_xy = (d->angle_xy + 1) % 72;
	if (key == 65535)
		d->angle_xy = (d->angle_xy - 1) % 72;
	if (key == 92)
		d->angle_yz = (d->angle_yz + 1) % 72;
	if (key == 93)
		d->angle_yz = (d->angle_yz - 1) % 72;
}

static int		key_hook(int key, t_data *d)
{
	static int	s = 10;

	if (key == 65307)
		exit(0);
	if (key > 65456 && key < 65466)
		s = 10 * (key - 65456);
	if (key == 65365)
		d->height++;
	if (key == 65366)
		d->height--;
	key_view(key, d, s);
	expose_hook(d);
	return (0);
}

static int		ft_init_mlx(t_data *d, t_img *i)
{
	d->size[0] = 1920;
	d->size[1] = 1080;
	d->pos[0] = 1920;
	d->pos[1] = 1080;
	d->angle_xy = 2;
	d->angle_yz = 9;
	d->scale = 20;
	d->height = 1;
	d->mlx_win = mlx_new_window(d->mlx_ptr, d->size[0], d->size[1], "fdf");
	if (d->mlx_win == 0)
		return (-1);
	i->ptr = mlx_new_image(d->mlx_ptr, d->size[0], d->size[1]);
	if (i->ptr)
		i->data = mlx_get_data_addr(i->ptr, &i->bpp, &i->line, &i->endian);
	else
		return (-1);
	return (0);
}

int				main(int ac, char **av)
{
	t_data		d;

	if (ac != 2)
		return (ft_error("fdf map", 0));
	if (ft_get_map(&d.map, av[1]))
		return (0);
	if (d.map.c < 1 || d.map.l < 1)
		return (ft_error("Map error", -1));
	if ((d.mlx_ptr = mlx_init()) == 0)
		return (ft_error("Win init error", -1));
	d.max = ft_max_height(&d.map);
	if (ft_init_mlx(&d, &d.img))
		return (ft_error("Img init error", -1));
	mlx_hook(d.mlx_win, 2, 3, key_hook, &d);
	mlx_expose_hook(d.mlx_win, expose_hook, &d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
