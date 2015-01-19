/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 19:02:02 by drabahi           #+#    #+#             */
/*   Updated: 2014/01/09 21:42:19 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdlib.h>

static int		line_len(char *tmp)
{
	int	len;

	len = 0;
	while (tmp[len] != '\n' && tmp[len] != '\0')
		len++;
	return (len);
}

static int		end_file(char *tmp, char **line, char *save_str)
{
	if (*tmp && *line)
	{
		*line = ft_strdup(tmp);
		if (save_str)
			ft_bzero(save_str, sizeof(save_str));
		return (1);
	}
	return (0);
}

void	line_save(char **line, char *tmp)
{
	*line = ft_strnew(line_len(tmp));
	*line = ft_strncpy((*line), tmp, line_len(tmp));
}

int		get_next_line(int const fd, char **line)
{
	static char	*save_str;
	char		*str;
	char		*tmp;
	int			ret;
	int			len;

	tmp = ((save_str) ? ft_strdup(save_str) : ft_strnew(BUFF_SIZE));
	while (tmp && (!ft_strchr(tmp, '\n')))
	{
		if ((str = ft_strnew(BUFF_SIZE)))
		{
			if ((ret = read(fd, str, BUFF_SIZE)) > 0)
				tmp = ft_strjoin(tmp, str);
			else if (ret == 0)
				return (end_file(tmp, line, save_str));
			else
				return (-1);
			free(str);
		}
	}
	line_save(line, tmp);
	len = line_len(tmp);
	save_str = ft_strsub(tmp, len + 1, (ft_strlen(tmp) - len));
	free(tmp);
	return (1);
}
