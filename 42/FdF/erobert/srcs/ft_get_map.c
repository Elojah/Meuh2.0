/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:08:01 by erobert           #+#    #+#             */
/*   Updated: 2015/01/20 19:30:32 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "fdf.h"

static int	ft_nb_line(int const fd)
{
	char	buf[256];
	int		i;
	int		j;
	int		k;

	k = 0;
	i = read(fd, buf, 255);
	while (i)
	{
		buf[i] = '\0';
		j = 0;
		while (buf[j])
		{
			if (buf[j] == '\n')
				k++;
			j++;
		}
		i = read(fd, buf, 255);
	}
	return (k);
}

int			ft_get_map(t_map *map, char *av)
{
	char	*line;
	int		*tab;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (ft_error("Open error", -1));
	map->l = ft_nb_line(fd);
	close(fd);
	map->tab = malloc(sizeof(*(map->tab)) * map->l);
	if (!map->tab)
		return (ft_error("Malloc error", -1));
	fd = open(av, O_RDONLY);
	ft_get_line(fd, &line);
	map->c = ft_get_tab(line, &tab);
	map->l = 0;
	map->tab[map->l] = tab;
	while (ft_get_line(fd, &line))
	{
		ft_get_tab(line, &map->tab[map->l]);
		if (!map->tab[map->l++])
			return (ft_error("Malloc error", -1));
	}
	return (0);
}
