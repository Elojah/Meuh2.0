/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 12:26:02 by erobert           #+#    #+#             */
/*   Updated: 2015/05/07 14:01:40 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "scop.h"

static void		ft_get_vertex(t_vertex *vbd, char *line)
{
	while (*line == ' ')
		line++;
	vbd->x = ft_atof(line);
	while (*line && *line != ' ')
		line++;
	while (*line == ' ')
		line++;
	vbd->y = ft_atof(line);
	while (*line  && *line != ' ')
		line++;
	while (*line == ' ')
		line++;
	vbd->z = ft_atof(line);
}

static int		ft_get_index(GLuint *ibd, char *line)
{
	int			i;

	i = 0;
	while (*line)
	{
		while (*line && *line != ' ')
			line++;
		while (*line == ' ')
			line++;
		ibd[i++] = ft_atoi(line) - 1;
	}
	return (i - 1);
}
#include <stdio.h>
int				ft_get_obj(t_env *e, t_vertex *vbd, GLuint *ibd, char *file)
{
	int			fd;
	char		*line;
	int			i;
	int			j;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	e->buffer_size = 0;
	while (ft_get_line(fd, &line))
	{
		if (!line)
			return (close(fd));
		if (*line == 'v' && line[1] == ' ')
			ft_get_vertex(vbd + i++, line + 1);
		else if (*line == 'f' && line[1] == ' ')
		{
			j = ft_get_index(ibd, line);
			printf("%d %d %d", ibd[0], ibd[1], ibd[2]);
			e->vertices[e->buffer_size++] = vbd[ibd[0]];
			e->vertices[e->buffer_size++] = vbd[ibd[1]];
			e->vertices[e->buffer_size++] = vbd[ibd[2]];
			if (j == 4)
			{
				printf(" %d %d %d", ibd[2], ibd[3], ibd[0]);
				e->vertices[e->buffer_size++] = vbd[ibd[2]];
				e->vertices[e->buffer_size++] = vbd[ibd[3]];
				e->vertices[e->buffer_size++] = vbd[ibd[0]];
			}
			printf(" %lu\n", e->buffer_size);
			ibd += j;
		}
		free(line);
	}
	return (close(fd));
}
