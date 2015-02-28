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

static void		ft_move(t_data *data, int inc, int dir)
{
	int			i;
	int			j;
	int			save_i;
	int			save_j;

	i = -1;
	while (++i < data->size)
	{
		j = inc > 0 ? 0 : data->size - 1;
		while (j < data->size && j >= 0)
		{

			save_i = i;
			save_j = j;
			if (dir)
			{
				i = save_j;
				j = save_i;
			}
			if (data->grid[i][j]
				&& !((inc > 0 && j == data->size - 1) || (inc < 0 && !j))
				&& !data->grid[i][j + inc])
			{
				data->grid[i][j + inc] = data->grid[i][j];
				data->grid[i][j] = 0;
			}
			i = save_i;
			j = save_j;

			j += inc;
		}
	}
}

void	ft_play(t_data *data, char input)
{
	if (input == 'w')
		ft_move(data, 1, 1);
	else if (input == 'a')
		ft_move(data, -1, 0);
	else if (input == 's')
		ft_move(data, -1, 1);
	else if (input == 'd')
		ft_move(data, 1, 0);
}