/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 22:54:49 by drabahi           #+#    #+#             */
/*   Updated: 2014/05/28 21:41:56 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int	color_line_x(t_env *e, float x, t_coord *pos_start, t_coord *pos_end)
{
	int		color;
	float	dist_perp;
	int		height_line;
	int		start;
	int		end;

	dist_perp = find_dist_perp(e, x, &color);
	height_line = abs((int) (WH / dist_perp));
	start = (WH - height_line) / 2;
	if (start < 0 || start > WH)
		start = 0;
	end = (height_line + WH) / 2;
	if (end >= WH || end < 0)
		end = WH - 1;
	pos_start->y = start;
	pos_end->y = end;
	return (color);
}

float	find_dist_perp(t_env *e, float x, int *color)
{
	t_cal	inf;
	float	camera;
	float	perp;

	camera = ((2 * x) / WW) - 1;
	pos_info(e, &inf, camera);
	find_side(e, &inf);
	if (inf.side == 0)
		perp = (inf.posi.x - e->pos->x + (1 - (int)inf.step.x) / 2)
			/ inf.ray_dir.x;
	else
		perp = (inf.posi.y - e->pos->y + (1 - (int)inf.step.y) / 2)
			/ inf.ray_dir.y;
	ft_choose_color(e->pos, &(inf.posi), color, inf.side);
	if (perp < 0)
		perp = -perp;
	return (perp);
}

void	ft_choose_color(t_coord *p, t_coord *w, int *color, int side)
{
	if (side == 0)
	{
		if (w->x < p->x)
			*color = 0x8ba446;
		else
			*color = 0x7f00ff;
	}
	else
	{
		if (w->y < p->y)
			*color = 0x1d7cf2;
		else
			*color = 0xFF9000;
	}
}

int	find_side(t_env *e, t_cal *info)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		if (info->sideDist.x < info->sideDist.y)
		{
			info->sideDist.x += info->deltaDist.x;
			info->posi.x += info->step.x;
			info->side = 0;
		}
		else
		{
			info->sideDist.y += info->deltaDist.y;
			info->posi.y += info->step.y;
			info->side = 1;
		}
		if ((info->posi.y < 0 || info->posi.x < 0 || info->posi.y >
					e->size_map->y || info->posi.x > e->size_map->x) ||
				wall((e->map)[(int)info->posi.y][(int)info->posi.x]))
			i = 1;
	}
	return (i);
}

void	find_start(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while ((e->map)[i])
	{
		j = 0;
		while ((e->map)[i][j])
		{
			if (ft_strcmp((e->map)[i][j], "0") == 0)
			{
				e->pos->x = j + 0.5;
				e->pos->y = i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
	free_all(e);
	exit(0);
}

