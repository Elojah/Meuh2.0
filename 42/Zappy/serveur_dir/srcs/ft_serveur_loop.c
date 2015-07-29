/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serveur_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 15:12:20 by erobert           #+#    #+#             */
/*   Updated: 2015/06/12 17:02:03 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
#include <sys/time.h>
#include "serveur.h"

static void				ft_fds_init(t_env *e)
{
	int					i;

	e->nfds = 0;
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	i = -1;
	while (++i < e->mfds)
	{
		if (e->fds[i].type)
		{
			FD_SET(i, &e->fd_read);
			if (ft_strlen(e->fds[i].buf_write))
				FD_SET(i, &e->fd_write);
			e->nfds = (e->nfds < i ? i : e->nfds);
		}
	}
}

static void				ft_fds_check(t_env *e)
{
	int					i;

	i = -1;
	while (++i < e->mfds && e->rfds > 0)
	{
		if (FD_ISSET(i, &e->fd_read))
			e->fds[i].fct_read(e, i);
		if (FD_ISSET(i, &e->fd_write))			
			e->fds[i].fct_write(e, i);
		if (FD_ISSET(i, &e->fd_read) || FD_ISSET(i, &e->fd_write))
			e->rfds--;
	}
}

static void				ft_cmd_do(t_env *e, int sock)
{
	int					res[3];

	res[0] = ft_action_move(e, sock, e->fds[sock].cmd);
	res[1] = ft_action_object(e, sock, e->fds[sock].cmd, e->fds[sock].av);
	res[2] = ft_action_special(e, sock, e->fds[sock].cmd);
	if (res[0] > 0 || res[1] > 0 || res[2] > 0)
		ft_putstr_fd("ok\n", sock);
	if (res[0] < 0 || res[1] < 0 || res[2] < 0)
		ft_putstr_fd("ko\n", sock);
	e->fds[sock].cmd = E_CMD; /* lst cmd = lst next */
}

static void				ft_cmd_check(t_env *e)
{
	int					i;
	struct timeval		tp;

	i = -1;
	while (++i < e->mfds)
	{
		if (e->fds[i].type == PLAYER && e->fds[i].cmd != E_CMD)
		{
			gettimeofday(&tp, NULL);
			if (tp.tv_sec > e->fds[i].time.tv_sec)
				ft_cmd_do(e, i);
			else if (tp.tv_sec == e->fds[i].time.tv_sec)
			{
				if (tp.tv_usec >= e->fds[i].time.tv_usec)
					ft_cmd_do(e, i);
			}
		}
	}
}

void					ft_serveur_loop(t_env *e, int sock)
{
	struct timeval		tv;

	tv.tv_sec = 0;
	tv.tv_usec = 1;
	e->fds[sock].type = SERVER;
	e->fds[sock].fct_read = ft_serveur_accept;
	e->fds[sock].pos[0] = -1;
	e->fds[sock].pos[1] = -1;
	e->gfx = sock;
	while (1138)
	{
		ft_fds_init(e);
		e->rfds = select(e->nfds + 1, &e->fd_read, &e->fd_write, NULL, &tv);
		ft_fds_check(e);
		ft_cmd_check(e);
		ft_check_death(e);
	}
}
