/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:46:13 by erobert           #+#    #+#             */
/*   Updated: 2015/02/28 20:06:14 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	ft_display_cell(int line, int column, int h, char *str)
{
	int		tmp;

	tmp = h * (TPL_WIDTH + 1);
	mvwprintw(stdscr, line + h, column * TPL_WIDTH, str + tmp);
}

void		ft_display_grid(t_data *d)
{
	int		i;
	int		j;
	int		h;

	i = -1;
	while (++i < d->size)
	{
		h = -1;
		while (++h < TPL_HEIGHT)
		{
			j = -1;
			while (++j < d->size)
			{
				attron(COLOR_PAIR(d->grid[i][j]));
				ft_display_cell(i * TPL_HEIGHT, j, h, d->tpls[d->grid[i][j]]);
				attroff(COLOR_PAIR(d->grid[i][j]));
			}
		}
	}
}
