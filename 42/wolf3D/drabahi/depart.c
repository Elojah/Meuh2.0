/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depart.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 16:35:28 by drabahi           #+#    #+#             */
/*   Updated: 2014/01/18 22:35:04 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <unistd.h>

void	posi_init(t_env *e, char *file)
{
	if ((e->size_map = (t_coord *) malloc(sizeof(*(e->size_map)))) == NULL)
		exit(0);
	e->size_map->y = line_map(file);
	e->size_map->x = 0;
}

int	line_map(char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if((fd = open(file, O_RDONLY)) == -1)
		return (no_map());
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	if (close(fd) == -1)
		return (no_map());
	return (i);
}

int	col_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	free_line_map(char ***line)
{
	int	i;

	i = 0;
	while ((*line)[i])
	{
		ft_strdel(&((*line)[i]));
		i++;
	}
	free(*line);
	*line = NULL;
}
