/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 13:20:02 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 15:18:26 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "serveur.h"

static int		ft_return_error(int sock)
{
	t_request	req;

	req.cmd = 0;
	write(sock, &req, sizeof(req));
	return (-1);
}

int				ft_putfile(int sock, char *file)
{
	t_request	req;
	int			fd;
	int			i;

	fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd == -1)
		return (ft_return_error(sock));
	req.cmd = PUT;
	while (req.cmd == PUT)
	{
		i = read(sock, &req, sizeof(req));
		if (i == -1)
			return (ft_return_error(sock));
		ft_putstr_fd(req.av, fd);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}
