/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 13:40:23 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 12:59:38 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include "ft_minishell1.h"

static void	ft_twoin(t_cmd *cmd, int *pfd)
{
	char	buf[1024];
	char	*str;
	int		i;

	str = malloc(sizeof(*str) * 1);
	str[0] = '\0';
	while (1)
	{
		write(2, "> ", 2);
		i = read(0, buf, 1023);
		buf[i] = '\0';
		if (ft_strcmp(buf, cmd->file))
			str = ft_strjoin(str, buf);
		else
		{
			ft_putstr_fd(str, pfd[1]);
			return ;
		}
	}
}

static void	ft_redirin(t_cmd *cmd)
{
	int		pfd[2];

	if (cmd->two[0])
	{
		if (pipe(pfd) == -1)
			return ;
		ft_twoin(cmd, pfd);
		dup2(pfd[0], 0);
		close(pfd[0]);
		close(pfd[1]);
	}
	else
	{
		dup2(cmd->fd[0], 0);
		close(cmd->fd[0]);
	}
}

void		ft_redirection(t_cmd *cmd, char *line, char ***env)
{
	pid_t	father;

	father = fork();
	if (father > 0)
		wait(0);
	else if (!father)
	{
		if (cmd->fd[0])
			ft_redirin(cmd);
		if (cmd->fd[1])
		{
			dup2(cmd->fd[1], 1);
			close(cmd->fd[1]);
		}
		ft_exec(0, cmd, line, env);
		exit(0);
	}
}
