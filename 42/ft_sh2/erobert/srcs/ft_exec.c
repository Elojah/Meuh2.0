/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:18:36 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 18:48:15 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "ft_minishell2.h"

void		ft_exec(int f, t_cmd *cmd, char *str, char ***env)
{
	char	**tab;
	pid_t	father;

	tab = ft_strsplit(str, ' ');
	if (!tab[0])
		return ;
	else if (ft_gotpipe(str))
		ft_pipe(str, env);
	else if (ft_gotredirection(cmd, str))
		ft_redirection(cmd, str, env);
	else if (ft_env(tab, env))
		;
	else if (ft_getcmd(cmd, str, *env))
	{
		if (!f)
			execve(cmd->path, cmd->av, *env);
		father = fork();
		if (father)
			wait(0);
		else
			execve(cmd->path, cmd->av, *env);
	}
}
