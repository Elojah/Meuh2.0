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
#include <stdlib.h>

static int		check_score(t_data *data)
{
	int			i;
	int			j;
	int			score;
	int			lost;

	score = 0;
	lost = i = -1;
	while (++i < data->size)
	{
		j = - 1;
		while (++j < data->size)
		{
			if (data->grid[i][j] > score)
				score = data->grid[i][j];
			if (lost < 0 && (data->grid[i][j] == N_0
				|| (i && data->grid[i - 1][j] == data->grid[i][j])
				|| (j && data->grid[i][j - 1] == data->grid[i][j])))
				lost = 1;
		}
	}
	return (score * lost);
}

static void		pop_new(t_data *data)
{
	int			i;
	int			j;
	int			n;
	int			random;
	int			tmp[25][2];

	n = i = -1;
	while (++i < data->size)
	{
		j = - 1;
		while (++j < data->size)
		{
			if (data->grid[i][j] == N_0)
			{
				tmp[++n][0] = i;
				tmp[n][1] = j;
			}
		}
	}
	if (n == -1)//lost
		return ;
	random = rand() % (n + 1);
	data->grid[tmp[random][0]][tmp[random][1]] = (rand() % 10) > 7 ? 1 : 2;
}

static int		ft_move_case(t_data *data, int index[2], int inc[2], int prev[2])
{
	int			next_index[2];

	next_index[0] = index[0] - inc[0];
	next_index[1] = index[1] - inc[1];
	if (data->grid[index[0]][index[1]] != N_0
		&& next_index[0] >= 0 && next_index[0] < data->size
		&& next_index[1] >= 0 && next_index[1] < data->size)
	{
		if (data->grid[next_index[0]][next_index[1]] == N_0)
		{
			data->grid[next_index[0]][next_index[1]] = data->grid[index[0]][index[1]];
			data->grid[index[0]][index[1]] = N_0;
			return (-1);
		}
		else if (data->grid[next_index[0]][next_index[1]] == data->grid[index[0]][index[1]]
			&& (next_index[0] != prev[0] || next_index[1] != prev[1]))
		{
			data->grid[next_index[0]][next_index[1]]++;
			data->grid[index[0]][index[1]] = N_0;
			prev[0] = next_index[0];
			prev[1] = next_index[1];
			return (1);
		}
	}
	return (1);
}

static void		ft_move(t_data *data, int index, int inc[2], int dir)
{
	int					i;
	int					j;
	int					move_dir;
	int					prev[2];
	int					save_inc;

	i = -1;
	save_inc = ((index == 0) ? 1 : -1);
	while (++i < data->size)
	{
		j = index;
		prev[0] = -1;
		prev[1] = -1;
		while (j < data->size && j >= 0)
		{
			if (dir)
				j += (save_inc * (move_dir = ft_move_case(data, (int[2]){i, j}, inc, prev)));
			else
				j += (save_inc * (move_dir = ft_move_case(data, (int[2]){j, i}, inc, prev)));
		}
	}
}

int			ft_play(t_data *data, char input)
{
	if (input == 'w')
		ft_move(data, 0, (int[2]){1, 0}, 0);
	else if (input == 'a')
		ft_move(data, 0, (int[2]){0, 1}, 1);
	else if (input == 's')
		ft_move(data, data->size - 1, (int[2]){-1, 0}, 0);
	else if (input == 'd')
		ft_move(data, data->size - 1, (int[2]){0, -1}, 1);
	else
		return (0);
	pop_new(data);
	return (check_score(data));
}
