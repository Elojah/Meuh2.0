/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 13:13:56 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 15:21:50 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "client.h"

int				ft_putfile(int sock, char *file)
{
	t_request	req;
	int			fd;
	int			i;

	fd = open(file, O_RDONLY, 0664);
	if (fd == -1)
		return (ft_print_result(" no such file or permission: ", file, -1));
	req.cmd = PUT;
	ft_strcpy(req.av, file);
	write(sock, &req, sizeof(req));
	i = 1;
	while (i > 0)
	{
		i = read(fd, req.av, 1023);
		if (i == -1)
			return (ft_print_result(" read: ", file, -1));
		req.av[i] = '\0';
		write(sock, &req, sizeof(req));
	}
	if (close(fd) == -1)
		return (ft_print_result(" close: ", file, -1));
	req.cmd = 0;
	write(sock, &req, sizeof(req));
	return (ft_print_result(" put file: ", file, 1));
}
