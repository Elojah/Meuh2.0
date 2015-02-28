/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:33:22 by hdezier           #+#    #+#             */
/*   Updated: 2015/02/28 17:33:22 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/2048.h"

#include <stdio.h>

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
	printf("input = %c\n", input);
	if (input == 'w')
		ft_move(data, 1, 1);
	else if (input == 'a')
		ft_move(data, -1, 0);
	else if (input == 's')
		ft_move(data, -1, 1);
	else if (input == 'd')
		ft_move(data, 1, 0);
}

static void		display_map(t_data *data)
{
	int i, j;

	printf("MAP: \n");
	for (i = 0; i < data->size; i++) {
		for (j = 0; j < data->size; j++) {
			printf("%d\t", data->grid[i][j]);
		}
		printf("\n");
	}
}

int		main(void) {
	t_data		data;
	char		c;
	int i, j;

	data.size = 4;
	for (i = 0; i < data.size; i++) {
		for (j = 0; j < data.size; j++) {
			data.grid[i][j] = 0;
		}
	}
	data.grid[1][1] = 3;
	data.grid[2][1] = 3;
	data.grid[0][3] = 3;
	data.grid[2][2] = 3;
	while (1)
	{
		read(0, &c, 1);
		ft_play(&data, c);
		display_map(&data);
	}
}
