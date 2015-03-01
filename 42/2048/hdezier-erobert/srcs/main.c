/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:17:48 by erobert           #+#    #+#             */
/*   Updated: 2015/03/01 14:10:48 by erobert          ###   ########.fr       */
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
	d->tpls[i][TPL_SIZE - 1] = '\0';
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
	d->grid[2][2] = N_2;
}

static void	ft_init_data(t_data *d, int ac, char **av)
{
	if (ac == 2 && !ft_strcmp(av[1], "5"))
		d->size = 5;
	else
		d->size = 4;
	ft_init_grid(d);
	start_color();
	init_pair(N_0, COLOR_BLACK, COLOR_WHITE);
	init_pair(N_2, COLOR_BLACK, COLOR_CYAN);
	init_pair(N_4, COLOR_BLACK, COLOR_CYAN);
	init_pair(N_8, COLOR_BLACK, COLOR_CYAN);
	init_pair(N_16, COLOR_BLACK, COLOR_BLUE);
	init_pair(N_32, COLOR_BLACK, COLOR_BLUE);
	init_pair(N_64, COLOR_BLACK, COLOR_BLUE);
	init_pair(N_128, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(N_256, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(N_512, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(N_1024, COLOR_BLACK, COLOR_RED);
	init_pair(N_2048, COLOR_BLACK, COLOR_RED);
	init_pair(N_4096, COLOR_BLACK, COLOR_RED);
	init_pair(N_8192, COLOR_BLACK, COLOR_RED);
}

int			main(int ac, char **av)
{
	t_data	d;
	char	input;

	signal(SIGINT, &ft_signal);
	signal(SIGQUIT, &ft_signal);
	ft_get_tpls(&d);
	initscr();
	noecho();
	curs_set(0);
	ft_init_data(&d, ac, av);
	ft_display_grid(&d);
	input = getch();
	while (input != KEY_ESC)
	{
		ft_play(&d, input);
		clear();
		ft_display_grid(&d);
		refresh();
		input = getch();
	}
	endwin();
	return (0);
}
