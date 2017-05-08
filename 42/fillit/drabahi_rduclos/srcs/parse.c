/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:18:55 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:29:38 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		check_links(char tetris[4][5], int x, int y, int *nblink)
{
	if (x > 0 && tetris[y][x - 1] == '#')
		(*nblink)++;
	if (x < 3 && tetris[y][x + 1] == '#')
		(*nblink)++;
	if (y > 0 && tetris[y - 1][x] == '#')
		(*nblink)++;
	if (y < 3 && tetris[y + 1][x] == '#')
		(*nblink)++;
}

int			check_tetri(char tetris[4][5], int x, int y, int *link)
{
	int				nblink;
	static int		nbhach;

	nblink = 0;
	if (tetris[y][x] == '#')
	{
		nbhach++;
		check_links(tetris, x, y, &nblink);
		if (nblink == 0)
			return (-1);
		link[0] += nblink;
	}
	if (x == 3 && y == 3)
	{
		if (nbhach != 4)
			return (-1);
		nbhach = 0;
	}
	if (x == 3)
		check_tetri(tetris, 0, y + 1, link);
	else if (y < 4)
		check_tetri(tetris, x + 1, y, link);
	return (1);
}

int			find_shape(t_env *env, char tetris[4][5])
{
	int		link;

	link = 0;
	check_tetri(tetris, 0, 0, &link);
	if (link != 6 && link != 8)
		return (-1);
	return (save_tetri(env, tetris));
}

int			check_shape(t_env *env, char *line, int nbline)
{
	static int		nblt;
	static int		nbrc;
	static char		tetris[4][5];

	if (nblt == 0 && line[0] == '\0')
	{
		if (nbrc != 0 || nbline == 1)
			return (-1);
		nbrc = 1;
	}
	else
	{
		if ((nbline != 1 && nblt == 0 && nbrc != 1) || verify_char(line) == -1
			|| ft_strlen(line) != 4 || (nbrc == 1 && nblt != 0))
			return (-1);
		nbrc = 0;
		ft_strncpy(tetris[nblt], line, 5);
		if (nblt == 3)
		{
			nblt = 0;
			return (find_shape(env, tetris));
		}
		nblt++;
	}
	return (1);
}

int			parse(t_env *env, char **av)
{
	int		fd;
	int		ret;
	int		nbline;
	char	*line;
	int		ret2;

	line = NULL;
	nbline = 0;
	ret2 = -1;
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			ret2 = 1;
			nbline++;
			if (ret == -1 || check_shape(env, line, nbline) == -1)
				return (-1);
		}
		close(fd);
	}
	else
		return (-1);
	if ((nbline + 1) % 5 != 0)
		return (-1);
	return (ret2);
}
