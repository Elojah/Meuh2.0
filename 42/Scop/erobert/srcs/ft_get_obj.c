/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 12:26:02 by erobert           #+#    #+#             */
/*   Updated: 2015/05/04 15:17:15 by erobert          ###   ########.fr       */
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
		ibd[i++] = ft_atoi(line);
	}
	return (i - 1);
}

int				ft_get_obj(t_vertex *vbd, GLuint *ibd, char *file)
{
	int			fd;
	char		*line;
	int			i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	while (ft_get_line(fd, &line))
	{
		if (!line)
			return (close(fd));
		if (*line == 'v' && line[1] == ' ')
			ft_get_vertex(vbd + i++, line + 1);
		else if (*line == 'f' && line[1] == ' ')
			ibd += ft_get_index(ibd, line);
		free(line);
	}
	return (close(fd));
}
