/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:11:22 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 12:59:30 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], "delete"))
			ft_putendl_fd(env[i], 1);
		i++;
	}
}
