/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 22:23:44 by drabahi           #+#    #+#             */
/*   Updated: 2014/01/19 19:34:02 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_rec(t_env *e, t_coord *pos_start, t_coord *pos_end, int color)
{
	float			x;
	float			y;
	int				val;
	unsigned int	color1;
	char			*color2;

	y = pos_start->y;
	color1 = mlx_get_color_value(e->mlx, color);
	color2 = (char *)&color1;
	while (y <= pos_end->y)
	{
		x = pos_start->x;
		while (x <= pos_end->x)
		{
			val = (y * e->n_line) + (x * (e->bpp / 8));
			e->data[val] = color2[0];
			e->data[val + 1] = color2[1];
			e->data[val + 2] = color2[2];
			e->data[val + 3] = color2[3];
			x++;
		}
		y++;
	}
}

void	draw_line_x(t_env *e, float x)
{
	t_coord	pos_start;
	t_coord	pos_end;
	t_coord	pos_top;
	t_coord	pos_bot;
	int		color;

	pos_start.x = x;
	pos_end.x = x;
	pos_top.x = x;
	pos_top.y = 0;
	pos_bot.x = x;
	pos_bot.y = WH;
	color = color_line_x(e, x, &pos_start, &pos_end);
	draw_rec(e, &pos_top, &pos_start, 0xccccff);
	draw_rec(e, &pos_end, &pos_bot, 0x808080);
	draw_rec(e, &pos_start, &pos_end, color);
}

void	draw_window(t_env *e)
{
	float	i;

	i = 0;
	while (i < WW)
	{
		draw_line_x(e, i);
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
