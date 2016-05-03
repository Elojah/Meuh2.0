/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 13:49:04 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 16:42:53 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int				ft_ls(int sock)
{
	t_request	req;

	req.cmd = LS;
	write(sock, &req, sizeof(req));
	if (read(sock, &req, sizeof(req)) == -1)
		return (ft_print_result(" read comlink", "", -1));
	while (req.cmd == LS)
	{
		ft_putendl_fd(req.av, 1);
		if (read(sock, &req, sizeof(req)) == -1)
			return (ft_print_result(" read comlink", "", -1));
	}
	ft_print_result(" ls", "", 1);
	return (0);
}
