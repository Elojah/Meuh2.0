/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 14:00:32 by erobert           #+#    #+#             */
/*   Updated: 2015/01/20 17:27:21 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void	ft_lines(t_data *d, int i, int j)
{
	t_vect	a;
	t_vect	b;

	a.x = j * d->scale;
	a.y = i * d->scale;
	a.z = d->map.tab[i][j];
	b.x = j * d->scale + d->scale;
	b.y = i * d->scale;
	b.z = d->map.tab[i][j + 1];
	ft_projection_vect(&a, &b, d);
	ft_translate_vect(&a, d->pos[0] / 2, -d->pos[1] / 4);
	ft_translate_vect(&b, d->pos[0] / 2, -d->pos[1] / 4);
	ft_put_pixel_to_image(d, a.x, a.y, ft_color_deg(a.z, d));
	ft_put_pixel_to_image(d, b.x, b.y, ft_color_deg(b.z, d));
	ft_draw_line(&a, &b, d);
}

static void	ft_columns(t_data *d, int i, int j)
{
	t_vect	a;
	t_vect	b;

	a.x = i * d->scale;
	a.y = j * d->scale;
	a.z = d->map.tab[j][i];
	b.x = i * d->scale;
	b.y = j * d->scale + d->scale;
	b.z = d->map.tab[j + 1][i];
	ft_projection_vect(&a, &b, d);
	ft_translate_vect(&a, d->pos[0] / 2, -d->pos[1] / 4);
	ft_translate_vect(&b, d->pos[0] / 2, -d->pos[1] / 4);
	ft_draw_line(&a, &b, d);
}

void		ft_draw_map(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	while (++i < d->map.l)
	{
		j = -1;
		while (++j < d->map.c - 1)
			ft_lines(d, i, j);
	}
	i = -1;
	while (++i < d->map.c)
	{
		j = -1;
		while (++j < d->map.l - 1)
			ft_columns(d, i, j);
	}
}
