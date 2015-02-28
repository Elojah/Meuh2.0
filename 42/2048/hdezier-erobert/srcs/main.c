/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:17:48 by erobert           #+#    #+#             */
/*   Updated: 2015/02/28 18:26:29 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "2048.h"

static int	ft_get_tpl(t_data *d, int i, char *name)
{
	int		fd;
	char	*tmp;

	tmp = ft_strjoin(TPL_FOLDER, name);
	if (!tmp)
		return (1);
	fd = open(tmp, O_RDONLY);
	free(tmp);
	free(name);
	if (fd == -1)
		return (1);
	if (!read(fd, d->tpls[i], 24))
		return (1);
	d->tpls[i][TPL_SIZE] = '\0';
	if (close(fd) == -1)
		return (1);
	return (0);
}

static int	ft_get_tpls(t_data *d)
{
	int		i;

	ft_get_tpl(d, 0, ft_itoa(0));
	i = 0;
	while (++i < NB)
	{
		if (ft_get_tpl(d, i, ft_itoa(1 << i)))
			return (1);
	}
	return (0);
}

static void	ft_init_grid(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	while (++i < d->size)
	{
		j = -1;
		while (++j < d->size)
			d->grid[i][j] = N_0;
	}
}

int			main(int ac, char **av)
{
	t_data	d;
	char	input;

	ft_get_tpls(&d);
	if (ac == 2 && !ft_strcmp(av[1], "5"))
		d.size = 5;
	else
		d.size = 4;
	initscr();
	raw();
	noecho();
	curs_set(0);
	input = getch();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	ft_init_grid(&d);
	d.grid[0][0] = N_2048;
	while (input != KEY_ESC)
	{
		ft_play(&d, input);
		ft_display_grid(&d);
		refresh();
		input = getch();
	}
	endwin();
	return (0);
}
