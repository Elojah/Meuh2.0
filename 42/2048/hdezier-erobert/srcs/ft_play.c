/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:33:22 by hdezier           #+#    #+#             */
/*   Updated: 2015/02/28 18:28:03 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

static void		ft_move_horizontal(t_data *data, int inc)
{
	int			i;
	int			j;

	i = -1;
	while (++i < data->size)
	{
		j = inc > 0 ? 0 : data->size - 1;
		while (j < data->size && j >= 0)
		{
			if (data->grid[i][j] != N_0
				&& j - inc >= 0 && j - inc < data->size)
			{
				if (data->grid[i][j - inc] == N_0)
					data->grid[i][j - inc] = data->grid[i][j];
				else if (data->grid[i][j - inc] == data->grid[i][j])
					data->grid[i][j - inc]++;
				else
					continue ;
				data->grid[i][j] = 0;
				j -= inc;
			}
			else
				j += inc;
		}
	}
}

static void		ft_move_vertical(t_data *data, int inc)
{
	int			i;
	int			j;

	i = -1;
	while (++i < data->size)
	{
		j = inc > 0 ? 0 : data->size - 1;
		while (j < data->size && j >= 0)
		{
			if (data->grid[j][i] != N_0
				&& j - inc >= 0 && j - inc < data->size)
			{
				if (data->grid[j - inc][i] == N_0)
					data->grid[j - inc][i] = data->grid[j][i];
				else if (data->grid[j - inc][i] == data->grid[j][i])
					data->grid[j - inc][i]++;
				else
					continue ;
				data->grid[j][i] = 0;
				j -= inc;
			}
			else
				j += inc;
		}
	}
}

void	ft_play(t_data *data, char input)
{
	if (input == 'w')
		ft_move_vertical(data, 1);
	else if (input == 'a')
		ft_move_horizontal(data, 1);
	else if (input == 's')
		ft_move_vertical(data, -1);
	else if (input == 'd')
		ft_move_horizontal(data, -1);
}
