/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_shader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 14:45:09 by erobert           #+#    #+#             */
/*   Updated: 2015/05/07 19:10:00 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "scop.h"

int			ft_load_shader(t_env *e)
{
	int		fd[2];
	int		i;

	fd[0] = open("data/f_shader.glsl", O_RDONLY);
	if (fd[0] == -1)
		return (-1);
	i = read(fd[0], e->f_shader, READ_SIZE);
	if (i == READ_SIZE)
		return (ft_error("f_shader too big", -1) || close(fd[0]));
	fd[1] = open("data/v_shader.glsl", O_RDONLY);
	if (fd[1] == -1)
	{
		close(fd[0]);
		return (-1);
	}
	e->f_shader[i] = '\0';
	i = read(fd[1], e->v_shader, READ_SIZE);
	if (i == READ_SIZE)
	{
		close(fd[0]);
		close(fd[1]);
		return (ft_error("v_shader too big", -1));
	}
	e->v_shader[i] = '\0';
	return (close(fd[0]) || close(fd[1]));
}
