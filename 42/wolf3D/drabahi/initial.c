/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 18:28:37 by drabahi           #+#    #+#             */
/*   Updated: 2014/01/19 23:13:22 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void	coord_init(t_env *e)
{
	int	i;
	int	j;

	if ((e->pos = mall_pos()) == NULL || (e->dir = mall_dir()) == NULL ||
			(e->plane = mall_plane()) == NULL)
	{
		free_all(e);
		exit(0);
	}
	i = 0;
	while (e->map[++i])
	{
		j = 0;
		while (e->map[i][++j])
		{
			if (ft_strcmp(e->map[i][j], "S") == 0)
			{
				e->pos->x = j + 0.5;
				e->pos->y = i + 0.5;
				return ;
			}
		}
	}
}

t_coord	*mall_pos()
{
	t_coord	*pos_new;

	if ((pos_new = (t_coord *)malloc(sizeof(*pos_new))) == NULL)
		return (NULL);
	return (pos_new);
}

t_coord	*mall_dir()
{
	t_coord	*dir_new;

	if ((dir_new = (t_coord *)malloc(sizeof(*dir_new))) == NULL)
		return (NULL);
	dir_new->x = -1;
	dir_new->y = 0;
	return (dir_new);
}

t_coord	*mall_plane()
{
	t_coord	*plane_new;

	if ((plane_new = (t_coord *)malloc(sizeof(*plane_new))) == NULL)
		return (NULL);
	plane_new->x = 0;
	plane_new->y = 0.5;
	return (plane_new);
}

void	free_all(t_env *e)
{
	ft_memdel((void **) &e->pos);
	ft_memdel((void **) &e->dir);
	ft_memdel((void **) &e->plane);
	ft_memdel((void **) &e->size_map);
	mlx_destroy_image(e->mlx, e->img);
	free_line_map(e->map);
}
