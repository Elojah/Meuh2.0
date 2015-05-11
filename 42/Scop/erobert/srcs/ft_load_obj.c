/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 14:44:27 by erobert           #+#    #+#             */
/*   Updated: 2015/05/11 13:00:14 by erobert          ###   ########.fr       */
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
	while (*line && *line != ' ')
		line++;
	while (*line == ' ')
		line++;
	vbd->z = ft_atof(line) - 1;
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

static int		ft_load_vertices(t_env *e, t_vertex *vbd, GLuint *ibd, char *l)
{
	GLfloat		c;
	int			i;

	if (e->buffer_size > MAX_SIZE - 6)
		return (0);
	i = ft_get_index(ibd, l);
	c = (e->buffer_size % 10 + 5) / 50.;
	e->vertices[e->buffer_size] = vbd[ibd[0]];
	e->vertices[e->buffer_size++].c = c;
	e->vertices[e->buffer_size] = vbd[ibd[1]];
	e->vertices[e->buffer_size++].c = c;
	e->vertices[e->buffer_size] = vbd[ibd[2]];
	e->vertices[e->buffer_size++].c = c;
	if (i == 4)
	{
		e->vertices[e->buffer_size] = vbd[ibd[2]];
		e->vertices[e->buffer_size++].c = c;
		e->vertices[e->buffer_size] = vbd[ibd[3]];
		e->vertices[e->buffer_size++].c = c;
		e->vertices[e->buffer_size] = vbd[ibd[0]];
		e->vertices[e->buffer_size++].c = c;
	}
	return (i);
}

int				ft_load_obj(t_env *e, GLuint *ibd, char *file)
{
	int			fd;
	char		*line;
	int			i;
	t_vertex	vbd[MAX_SIZE];

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
		else if (*line == 'f' && line[1] == ' ')
			ibd += ft_load_vertices(e, vbd, ibd, line);
		free(line);
	}
	return (close(fd));
}
