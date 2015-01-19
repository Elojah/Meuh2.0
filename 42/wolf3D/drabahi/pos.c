/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 23:28:29 by drabahi           #+#    #+#             */
/*   Updated: 2014/01/19 19:25:31 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pos_info(t_env *e, t_cal *inf, float cam)
{
	pos_init(&(inf->posi), e->pos);
	i_ray_dir(&(inf->ray_dir), e, cam);
	i_dist_delta(&(inf->deltaDist), &(inf->ray_dir));
	if (inf->ray_dir.x < 0)
	{
		inf->step.x = -1;
		inf->sideDist.x = (e->pos->x - inf->posi.x) * inf->deltaDist.x;
	}
	else
	{
		inf->step.x = 1;
		inf->sideDist.x = (inf->posi.x + 1.0 - e->pos->x) * inf->deltaDist.x;
	}
	if (inf->ray_dir.y < 0)
	{
		inf->step.y = -1;
		inf->sideDist.y = (e->pos->y - inf->posi.y) * inf->deltaDist.y;
	}
	else
	{
		inf->step.y = 1;
		inf->sideDist.y = (inf->posi.y + 1.0 - e->pos->y) * inf->deltaDist.y;
	}
}

void	pos_init(t_coord *posi, t_coord *pos)
{
	posi->x = (int)pos->x;
	posi->y = (int)pos->y;
}

void	i_ray_dir(t_coord *ray_dir, t_env *e, float cam)
{
	ray_dir->x = e->dir->x + (cam * e->plane->x);
	ray_dir->y = e->dir->y + (cam * e->plane->y);
}

void	i_dist_delta(t_coord *delta, t_coord *ray_dir)
{
	delta->x = sqrt(1 + (ray_dir->y * ray_dir->y) / (ray_dir->x * ray_dir->x));
	delta->y = sqrt(1 + (ray_dir->x * ray_dir->x) / (ray_dir->y * ray_dir->y));
}

int		wall(const char *coord)
{
	if (ft_isnb(coord) && coord[0] != '0')
		return (1);
	return (0);
}
