/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:46:13 by erobert           #+#    #+#             */
/*   Updated: 2015/02/28 16:58:55 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/2048.h"

void		ft_display_grid(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	while (++i < d->size)
	{
		j = -1;
		while (++j < d->size)
			mvwprintw(stdscr, i * TPL_HEIGHT, j * TPL_WIDTH, d->tpls[N_0]);
		j = -1;
		while (++j < d->size)
			mvwprintw(stdscr, i * TPL_HEIGHT + 1, j * TPL_WIDTH, d->tpls[N_0] + 8);
		j = -1;
		while (++j < d->size)
			mvwprintw(stdscr, i * TPL_HEIGHT + 2, j * TPL_WIDTH, d->tpls[N_0] + 16);
	}
}
