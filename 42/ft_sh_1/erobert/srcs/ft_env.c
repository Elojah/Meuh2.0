/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 10:27:25 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 12:57:47 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell1.h"

static char	**ft_addenv(const char *tmp, const char *value, char **env, int i)
{
	char	**tab;

	tab = malloc(sizeof(*tab) * (i + 2));
	tab[i + 1] = 0;
	i = 0;
	while (env[i])
	{
		tab[i] = env[i];
		i++;
	}
	tab[i] = ft_strjoin(tmp, value);
	free(env);
	return (tab);
}

static int	ft_setenv(const char *name, const char *value, char ***env)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin(name, "=");
	i = 0;
	while ((*env)[i] && ft_strncmp(tmp, (*env)[i], ft_strlen(tmp)))
		i++;
	if ((*env)[i])
	{
		free((*env)[i]);
		(*env)[i] = ft_strjoin(tmp, value);
	}
	else
		*env = ft_addenv(tmp, value, *env, i);
	free(tmp);
	return (1);
}

static int	ft_unsetenv(const char *name, char **env)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin(name, "=");
	i = 0;
	while (env[i] && ft_strncmp(tmp, env[i], ft_strlen(tmp)))
		i++;
	if (env[i])
	{
		free(env[i]);
		env[i] = "delete";
	}
	return (1);
}

int			ft_env(char **tab, char ***env)
{
	if (!ft_strcmp(tab[0], "env"))
	{
		ft_print_env(*env);
		return (1);
	}
	if (!ft_strcmp(tab[0], "setenv"))
		return (ft_setenv(tab[1], tab[2], env));
	if (!ft_strcmp(tab[0], "unsetenv"))
		return (ft_unsetenv(tab[1], *env));
	return (0);
}
