/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 20:50:28 by drabahi           #+#    #+#             */
/*   Updated: 2014/01/18 22:46:23 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void	left_key(t_env *e)
{
	t_move	*mo;

	mo = (t_move *)malloc(sizeof(t_move));
	mo->oldDirX = e->dir->x;
	mo->oldPlaneX = e->plane->x;
	e->dir->x = e->dir->x * cos(BIAS) - e->dir->y * sin(BIAS);
	e->dir->y = mo->oldDirX * sin(BIAS) + e->dir->y * cos(BIAS);
	e->plane->x = e->plane->x * cos(BIAS) - e->plane->y * sin(BIAS);
	e->plane->y = mo->oldPlaneX * sin(BIAS) + e->plane->y * cos(BIAS);
}

void	right_key(t_env *e)
{
	t_move	*mo;

	mo = (t_move *)malloc(sizeof(t_move));
	mo->oldDirX = e->dir->x;
	mo->oldPlaneX = e->plane->x;
	e->dir->x = e->dir->x * cos(-BIAS) - e->dir->y * sin(-BIAS);
	e->dir->y = mo->oldDirX * sin(-BIAS) + e->dir->y * cos(-BIAS);
	e->plane->x = e->plane->x * cos(-BIAS) - e->plane->y * sin(-BIAS);
	e->plane->y = mo->oldPlaneX * sin(-BIAS) + e->plane->y * cos(-BIAS);
}

void	up_key(t_env *e)
{
	t_move	*mo;

	mo = (t_move *)malloc(sizeof(t_move));
	mo->x = e->pos->x + (WALK * e->dir->x);
	mo->y = e->pos->y + (WALK * e->dir->y);
	if (mo->x >= 0 && mo->y >= 0 && mo->x <= e->size_map->x && mo->y <=
			e->size_map->y && !wall((e->map)[(int) mo->y][(int) mo->x]))
	{
		e->pos->x = mo->x;
		e->pos->y = mo->y;
	}
}

void	down_key(t_env *e)
{
	t_move	*mo;

	mo = (t_move *)malloc(sizeof(t_move));
	mo->x = e->pos->x - (WALK * e->dir->x);
	mo->y = e->pos->y - (WALK * e->dir->y);
	if (mo->x >= 0 && mo->y >= 0 && mo->x <= e->size_map->x && mo->y <=
			e->size_map->y && !wall((e->map)[(int) mo->y][(int) mo->x]))
	{
		e->pos->x = mo->x;
		e->pos->y = mo->y;
	}
}

void	run_key(t_env *e)
{
	float	x;
	float	y;
	int		i;

	x = e->pos->x + (2.0 * e->dir->x);
	y = e->pos->y + (2.0 * e->dir->y);
	if (x >= 0 && y >= 0 && e->size_map->x && y <= e->size_map->y
			&& !wall((e->map)[(int) y][(int) x]))
	{
		i = 0;
		while (i < 20)
		{
			x = e->pos->x + (0.1 * e->dir->x);
			y = e->pos->y + (0.1 * e->dir->y);
			if (x >= 0 && y >= 0 && x <= e->size_map->x && y <= e->size_map->y
					&& wall((e->map)[(int) y][(int) x]) < 2)
			{
				e->pos->x = x;
				e->pos->y = y;
			}
			draw_window(e);
			i++;
		}
	}
}
