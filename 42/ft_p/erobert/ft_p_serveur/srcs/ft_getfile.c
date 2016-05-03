/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 17:07:57 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 13:00:27 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "serveur.h"

int				ft_getfile(int sock, char *file)
{
	t_request	req;
	int			fd;
	int			i;

	req.cmd = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(sock, &req, sizeof(req));
		return (-1);
	}
	req.cmd = GET;
	i = 1;
	while (i > 0)
	{
		i = read(fd, req.av, 1023);
		req.av[i] = '\0';
		write(sock, &req, sizeof(req));
	}
	if (close(fd) == -1)
		return (-1);
	req.cmd = 0;
	write(sock, &req, sizeof(req));
	return (0);
}
