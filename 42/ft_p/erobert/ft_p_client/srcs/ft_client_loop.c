/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 15:13:05 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 15:59:01 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		ft_print_prompt(char **av)
{
	ft_putstr_fd("[", 2);
	ft_putstr_fd(BLUE, 2);
	ft_putstr_fd(av[1], 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(av[2], 2);
	ft_putstr_fd(END, 2);
	ft_putstr_fd("] ", 2);
	return (1);
}

void			ft_client_loop(int sock, char **av)
{
	char		*line;
	t_request	req;

	while (ft_print_prompt(av) && ft_getline(1, &line))
	{
		if (!ft_strcmp(line, "quit"))
		{
			req.cmd = QUIT;
			write(sock, &req, sizeof(req));
			ft_print_result(" connection abort", "", 1);
			return ;
		}
		else if (!ft_strncmp(line, "get ", 4))
			ft_getfile(sock, line + 4);
		else if (!ft_strncmp(line, "put ", 4))
			ft_putfile(sock, line + 4);
		else if (!ft_strcmp(line, "pwd"))
			ft_pwd(sock);
		else if (!ft_strncmp(line, "cd", 2))
			ft_cd(sock, line + 2);
		else if (!ft_strcmp(line, "ls"))
			ft_ls(sock);
		else
			ft_print_result(" inappropriate", "", -1);
	}
}
