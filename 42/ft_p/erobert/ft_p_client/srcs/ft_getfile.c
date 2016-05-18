/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 17:07:57 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 15:21:42 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "client.h"

int				ft_getfile(int sock, char *file)
{
	t_request	req;
	int			fd;

	req.cmd = GET;
	ft_strcpy(req.av, file);
	write(sock, &req, sizeof(req));
	if (read(sock, &req, sizeof(req)) == -1 || !req.cmd)
		return (ft_print_result(" no such file or permission: ", file, -1));
	fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd == -1)
		return (ft_print_result(" create: ", file, -1));
	while (req.cmd == GET)
	{
		ft_putstr_fd(req.av, fd);
		if (read(sock, &req, sizeof(req)) == -1)
			return (ft_print_result(" read comlink", "", -1));
	}
	if (close(fd) == -1)
		return (ft_print_result(" close: ", file, -1));
	return (ft_print_result(" get file: ", file, 1));
}
