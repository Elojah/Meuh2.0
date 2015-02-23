/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 14:58:03 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 13:08:09 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		ft_putprompt(char **env)
{
	int		i;
	int		j;

	ft_putstr_fd("[", 1);
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("1138", 1);
	ft_putstr_fd(END, 1);
	i = 0;
	while (env[i] && ft_strncmp("PWD=", env[i], 4))
		i++;
	if (env[i])
	{
		j = ft_strlen(env[i] + 4);
		while (env[i][j] != '/')
			j--;
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd(env[i] + j + 1, 1);
		ft_putstr_fd("/", 1);
		ft_putstr_fd(END, 1);
	}
	ft_putstr_fd("] ", 1);
}
