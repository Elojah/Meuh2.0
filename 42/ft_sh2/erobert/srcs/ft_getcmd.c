/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:46:55 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 18:48:24 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell2.h"

static void	ft_command_error(char *str)
{
	ft_putstr_fd("1138: command not found or permission denied: ", 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(END, 2);
}

static char	**ft_path(char **env)
{
	char	**path;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp("PATH=", env[i], 5))
		i++;
	if (!env[i])
		return (0);
	path = ft_strsplit(env[i] + 5, ':');
	return (path);
}

static char	*ft_iscommand(char *str, char **env)
{
	char	**path;
	char	*tmp;

	path = ft_path(env);
	str = ft_strjoin("/", str);
	while (path && *path)
	{
		tmp = ft_strjoin(*path, str);
		if (access(tmp, F_OK) != -1 && access(tmp, X_OK) != -1)
			return (tmp);
		free(tmp);
		path++;
	}
	if (access(str + 1, F_OK) != -1 && access(str + 1, X_OK) != -1)
		return (str + 1);
	ft_command_error(str + 1);
	free(str);
	return (0);
}

int			ft_getcmd(t_cmd *cmd, char *str, char **env)
{
	cmd->av = ft_strsplit(str, ' ');
	cmd->path = ft_iscommand(cmd->av[0], env);
	if (!cmd->path)
		return (0);
	return (1);
}
