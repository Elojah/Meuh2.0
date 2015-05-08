/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 14:44:27 by erobert           #+#    #+#             */
/*   Updated: 2015/05/07 18:54:42 by erobert          ###   ########.fr       */
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
	int			j;

	i = 0;
	while (*line)
	{
		while (*line && *line != ' ')
			line++;
		while (*line == ' ')
			line++;
		j = ft_atoi(line) - 1;
		if (j < MAX_SIZE)
			ibd[i++] = j;
		else
			ibd[i++] = 0;
	}
	return (i - 1);
}

int				ft_load_obj(t_env *e, t_vertex *vbd, GLuint *ibd, char *file)
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
		if (*line == 'v' && line[1] == ' ' && i < MAX_SIZE)
			ft_get_vertex(vbd + i++, line + 1);
		else if (*line == 'f' && line[1] == ' ' && e->buffer_size < MAX_SIZE - 6)
		{
			j = ft_get_index(ibd, line);
			e->vertices[e->buffer_size++] = vbd[ibd[0]];
			e->vertices[e->buffer_size++] = vbd[ibd[1]];
			e->vertices[e->buffer_size++] = vbd[ibd[2]];
			if (j == 4)
			{
				e->vertices[e->buffer_size++] = vbd[ibd[2]];
				e->vertices[e->buffer_size++] = vbd[ibd[3]];
				e->vertices[e->buffer_size++] = vbd[ibd[0]];
			}
			ibd += j;
		}
		free(line);
	}
	return (close(fd));
}
