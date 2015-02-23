/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 12:43:49 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 12:59:15 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include "ft_minishell1.h"

static void	ft_father(int *pfd_1, char **tab, char ***env)
{
	pid_t	father;
	int		pfd_2[2];
	t_cmd	cmd;

	close(pfd_1[1]);
	dup2(pfd_1[0], 0);
	close(pfd_1[0]);
	if (!tab[1])
	{
		ft_exec(0, &cmd, *tab, env);
		exit(0);
	}
	if (pipe(pfd_2) == -1)
		return ;
	father = fork();
	if (!father)
	{
		close(pfd_2[0]);
		dup2(pfd_2[1], 1);
		close(pfd_2[1]);
		ft_exec(0, &cmd, *tab, env);
		exit(0);
	}
	else
		ft_father(pfd_2, tab + 1, env);
}

void		ft_pipe(char *str, char ***env)
{
	char	**tab;
	pid_t	father;
	int		pfd[2];
	t_cmd	cmd;

	tab = ft_strsplit(str, '|');
	father = fork();
	if (father)
		wait(0);
	else
	{
		if (pipe(pfd) == -1)
			return ;
		father = fork();
		if (!father)
		{
			close(pfd[0]);
			dup2(pfd[1], 1);
			close(pfd[1]);
			ft_exec(0, &cmd, *tab, env);
			exit(0);
		}
		else
			ft_father(pfd, tab + 1, env);
	}
}
