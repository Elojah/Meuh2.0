/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_height.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:49:57 by erobert           #+#    #+#             */
/*   Updated: 2015/01/20 19:03:39 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_max_height(t_map *map)
{
	int	i;
	int	j;
	int	max;
	int	min;

	max = 0;
	min = 0;
	i = 0;
	while (i < map->l)
	{
		j = 0;
		while (j < map->c)
		{
			if (map->tab[i][j] > max)
				max = map->tab[i][j];
			if (map->tab[i][j] < min)
				min = map->tab[i][j];
			j++;
		}
		i++;
	}
	if (max * max > min * min)
		return (max);
	else
		return (-min);
}
