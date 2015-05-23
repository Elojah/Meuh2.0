/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 14:44:27 by erobert           #+#    #+#             */
/*   Updated: 2015/05/13 18:34:51 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "scop.h"

static void		ft_get_value(GLuint *index, char *line)
{
	int			tmp;

	tmp = ft_atoi(line) - 1;
	if (tmp < MAX_SIZE)
		*index = tmp;
	else
		*index = 0;
}

static int		ft_get_index(t_index *tmp, char *line)
{
	int			i;

	i = 0;
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (*line && *line)
			ft_get_value(tmp->ip + i++, line);
		while (*line && *line != ' ' && *line != '/')
			line++;
		if (*line && *line == '/')
		{
			ft_get_value(tmp->in + i - 1, ++line);
			while (*line && *line != ' ')
			{
				if (*line && *line == '/')
					ft_get_value(tmp->it + i - 1, ++line);
				line++;
			}
		}
	}
	return (i);
}

static void		ft_map_vertex(t_env *e, t_index *tmp, GLfloat c, int i)
{
	e->vertices[e->buffer_size] = tmp->vp[tmp->ip[i]];
	e->color_map[e->buffer_size] = tmp->vt[tmp->it[i]];
	e->normals[e->buffer_size] = tmp->vt[tmp->in[i]];
	e->vertices[e->buffer_size++].c = c;
}

static void		ft_load_vertices(t_env *e, t_index *tmp, char *line)
{
	GLfloat		c;
	int			i;

	if (e->buffer_size > MAX_SIZE - 6)
		return ;
	i = ft_get_index(tmp, line);
	c = (e->buffer_size % 10 + 5) / 50.;
	ft_map_vertex(e, tmp, c, 0);
	ft_map_vertex(e, tmp, c, 1);
	ft_map_vertex(e, tmp, c, 2);
	if (i == 4)
	{
		ft_map_vertex(e, tmp, c, 2);
		ft_map_vertex(e, tmp, c, 3);
		ft_map_vertex(e, tmp, c, 0);
	}
}

int				ft_load_obj(t_env *e, char *file)
{
	int			fd;
	char		*line;
	static int	i[3] = {0, 0, 0};
	t_index		tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (ft_get_line(fd, &line))
	{
		if (!line)
			return (close(fd));
		if (*line == 'v' && i[0] < MAX_SIZE)
			ft_get_vertex(tmp.vp + i[0]++, line + 1);
		else if (*line == 'v' && line[1] == 'n' && i[1] < MAX_SIZE)
			ft_get_vertex(tmp.vn + i[1]++, line + 2);
		else if (*line == 'v' && line[1] == 't' && i[2] < MAX_SIZE)
			ft_get_vertex(tmp.vt + i[2]++, line + 2);
		else if (*line == 'f' && line[1] == ' ')
			ft_load_vertices(e, &tmp, line + 1);
		free(line);
	}
	return (close(fd));
}
