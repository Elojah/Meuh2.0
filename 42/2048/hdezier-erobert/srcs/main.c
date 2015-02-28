/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:17:48 by erobert           #+#    #+#             */
/*   Updated: 2015/02/28 17:03:02 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/2048.h"
#include <stdio.h>
static int	ft_get_tpl(t_data *d, char *name)
{
	int		fd;
//	int			buf[2];
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (1);
//	printf("%d\n", (int)read(fd, d->tpls[0], 1));
	if (!read(fd, d->tpls[N_0], 24))
//		return (1);
//	write(1, tpl, 24);
//	write(1, "HEY\n", 4);
	d->tpls[0][25] = '\0';
	if (close(fd) == -1)
		return (1);
	return (0);
}

static int	ft_get_tpls(t_data *d)
{
	if (ft_get_tpl(d, "tpls/128"))
		return (1);
	return (0);
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
	(void)ac;
	(void)av;
	initscr();
	raw();
	noecho();
	curs_set(0);
	input = getch();
//	int i = 0;
	while (input != KEY_ESC)
	{
		// ft_play(&d, input);
		ft_display_grid(&d);
		refresh();
		input = getch();
	}
	endwin();
	return (0);
}
