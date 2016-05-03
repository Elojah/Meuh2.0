/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 15:17:21 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 18:14:56 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		ft_lexer(char *av)
{
	int			i;

	i = -1;
	while (av[++i + 1])
	{
		if (av[i] == '/' && av[i + 1])
			return (-1);
	}
	if (av[i] == '/')
		return (0);
	return (-1);
}

int				ft_cd(int sock, char *av)
{
	t_request	req;

	req.cmd = CD;
	if (!*av)
	{
		ft_strcpy(req.av, "/");
		write(sock, &req, sizeof(req));
	}
	else
	{
		if (ft_lexer(av))
			return (ft_print_result(" wrong format: cd [dir]/", "", -1));
		ft_strcpy(req.av, ++av);
		write(sock, &req, sizeof(req));
	}
	if (read(sock, &req, sizeof(req)) == -1)
		return (ft_print_result(" read comlink", "", -1));
	if (!req.cmd)
		return (ft_print_result(" no such folder or is a file: ", req.av, -1));
	return (ft_print_result(" cd: ", req.av, 1));
}
