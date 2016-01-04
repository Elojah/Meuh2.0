/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 15:16:51 by erobert           #+#    #+#             */
/*   Updated: 2014/06/07 16:41:37 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	ft_usage(char *str, int res)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" -n <team> -p <port> [-h <hostname>]", 2);
	ft_putendl_fd("  -n nom d'equipe", 2);
	ft_putendl_fd("  -p port", 2);
	ft_putendl_fd("  -h nom de la machine par defaut c'est le localhost", 2);
	return (res);
}

int			ft_print_result(char *s1, char *s2, int res)
{
	if (!s1)
		return (ft_usage(s2, res));
	ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	return (res);
}
