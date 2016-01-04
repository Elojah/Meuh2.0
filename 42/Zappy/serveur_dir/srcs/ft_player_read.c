/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 18:53:57 by erobert           #+#    #+#             */
/*   Updated: 2015/06/12 16:59:04 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include "serveur.h"

void		ft_player_read(t_env *e, int sock)
{
	char	**av;
	int		len;

	ft_bzero(e->fds[sock].buf_read, BUF_SIZE);
	len = recv(sock, e->fds[sock].buf_read, BUF_SIZE - 1, 0);
	if (len > 0)
	{
		e->fds[sock].buf_read[ft_linelen(e->fds[sock].buf_read)] = '\0';
		ft_putnbr(sock);
		ft_putstr("_");
		ft_putendl(e->fds[sock].buf_read);
		av = ft_strsplit(e->fds[sock].buf_read, ' ');
		ft_check_cmd(e, sock, av[0]);
		if (e->fds[sock].cmd == PUT || e->fds[sock].cmd == TAKE)
			ft_strcpy(e->fds[sock].av, av[1]);
	}
	else
		ft_sock_close(e, sock);
}
