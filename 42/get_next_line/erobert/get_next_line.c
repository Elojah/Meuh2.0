/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:47:17 by erobert           #+#    #+#             */
/*   Updated: 2016/02/26 15:12:55 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static size_t		ft_linelen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static int			ft_reset(t_save *save, int const fd, char **line)
{
	if (save->str)
		free(save->str);
	save->str = NULL;
	save->fd = fd;
	if (line)
		*line = NULL;
	return (-1);
}

static int			ft_endline(char **str, char **line)
{
	char			*tmp;

	if (**str == '\0')
	{
		free(*str);
		*str = NULL;
		*line = NULL;
		return (0);
	}
	if (ft_linelen(*str) == ft_strlen(*str))
	{
		*line = ft_strdup(*str);
		tmp = *str;
		*str = ft_strdup(*str + ft_strlen(*str));
		free(tmp);
		return (1);
	}
	(*str)[ft_linelen(*str)] = '\0';
	*line = ft_strdup(*str);
	tmp = *str;
	*str = ft_strdup(*str + ft_linelen(*str) + 1);
	free(tmp);
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_save	save = {-1, NULL};
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				i;

	if (!line)
		return (ft_reset(&save, fd, line));
	if (save.fd != fd)
		ft_reset(&save, fd, line);
	i = read(fd, buf, BUFF_SIZE);
	if (i == -1)
		return (ft_reset(&save, fd, line));
	buf[i] = '\0';
	if (save.str)
	{
		tmp = save.str;
		save.str = ft_strjoin(save.str, buf);
		free(tmp);
	}
	else
		save.str = ft_strdup(buf);
	if (i && ft_linelen(save.str) == ft_strlen(save.str))
		return (get_next_line(fd, line));
	else
		return (ft_endline(&save.str, line));
}
