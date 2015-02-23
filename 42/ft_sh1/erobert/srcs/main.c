/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 17:38:45 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 13:12:39 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>
#include <curses.h>
#include <termios.h>
#include "ft_minishell1.h"

static void	ft_backspaces_to_spaces(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i++] == '\t')
			line[i - 1] = ' ';
	}
}

static void	ft_command_line(char **line, char ***env)
{
	t_cmd	cmd;
	char	**tab;

	while (*line)
	{
		tab = ft_strsplit(*line, ' ');
		if (*tab && !ft_strcmp(tab[0], "exit"))
		{
			ft_mode(0);
			exit(0);
		}
		else if (!ft_strcmp(tab[0], "cd"))
			ft_cd(tab, *env);
		else
			ft_exec(1, &cmd, *line, env);
		line++;
	}
}

static int	ft_init(void)
{
	char	*term;

	if ((term = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("Error: terminal\n", 2);
		return (-1);
	}
	if (tgetent(0, term) != 1)
	{
		ft_putstr_fd("Error: tgetent\n", 2);
		return (-1);
	}
	return (0);
}

static int	ft_read_line(int fd, char **line)
{
	char	*str;
	char	*tmp;
	char	buf[2];

	str = malloc(sizeof(*str));
	str[0] = '\0';
	buf[0] = '\0';
	buf[1] = '\0';
	while (*buf != '\n')
	{
		read(fd, buf, 1);
		write(1, buf, 1);
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	str[ft_strlen(str) - 1] = '\0';
	*line = str;
	return (1);
}

int			main(void)
{
	char	*line;
	char	**tab;
	char	**env;

	env = ft_cpyenv();
	if (ft_init())
		return (-1);
	ft_mode(1);
	ft_putprompt(env);
	while (ft_read_line(0, &line))
	{
		ft_backspaces_to_spaces(line);
		tab = ft_strsplit(line, ';');
		ft_command_line(tab, &env);
		ft_putprompt(env);
	}
	return (0);
}
