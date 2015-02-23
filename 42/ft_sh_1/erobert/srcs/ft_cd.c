/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 12:08:05 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 12:56:55 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell1.h"

static void	ft_change_path(char **env)
{
	char	buf[1024];
	int		i;
	int		j;

	i = 0;
	while (env[i] && ft_strncmp("OLDPWD=", env[i], 7))
		i++;
	j = 0;
	while (env[j] && ft_strncmp("PWD=", env[j], 4))
		j++;
	if (env[i] && env[j])
	{
		free(env[i]);
		env[i] = ft_strjoin("OLDPWD=", env[j] + 4);
	}
	if (env[j])
	{
		buf[1023] = '\0';
		getcwd(buf, 1023);
		free(env[j]);
		env[j] = ft_strjoin("PWD=", buf);
	}
}

static void	ft_case(char **tab, char **env, int i)
{
	if (!tab[1])
	{
		i = 0;
		while (env[i] && ft_strncmp("HOME=", env[i], 5))
			i++;
		if (env[i])
			tab[1] = env[i] + 5;
	}
	if (tab[1][0] == '~')
	{
		i = 0;
		while (env[i] && ft_strncmp("HOME=", env[i], 5))
			i++;
		if (env[i])
			tab[1] = ft_strjoin(env[i] + 5, ft_strjoin("/", tab[1] + 1));
	}
	if (tab[1][0] == '-' && !tab[1][1])
	{
		i = 0;
		while (env[i] && ft_strncmp("OLDPWD=", env[i], 7))
			i++;
		if (env[i])
			tab[1] = env[i] + 7;
		ft_putendl_fd(tab[1], 1);
	}
}

void		ft_cd(char **tab, char **env)
{
	ft_case(tab, env, 0);
	if (chdir(tab[1]) == -1)
	{
		ft_putstr_fd("cd: no such directory or permission denied: ", 2);
		ft_putstr_fd(YELLOW, 2);
		ft_putstr_fd(tab[1], 2);
		ft_putendl_fd(END, 2);
	}
	else
		ft_change_path(env);
}
