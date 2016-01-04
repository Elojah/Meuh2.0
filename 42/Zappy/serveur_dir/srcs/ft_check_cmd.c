/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabid-on <rabid-on@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:52:31 by rabid-on          #+#    #+#             */
/*   Updated: 2015/06/12 16:54:25 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "serveur.h"

static int			ft_time_cmd(t_env *e, int sock, struct timeval *tp)
{
	if (e->fds[sock].cmd == INVENTORY)
		e->fds[sock].time.tv_sec = tp->tv_sec + 1 / e->time;
	else if (e->fds[sock].cmd == INCANTATION)
	{
		ft_putendl_fd("elevation en cours", sock);
		e->fds[sock].time.tv_sec = tp->tv_sec + 300 / e->time;
	}
	else if (e->fds[sock].cmd == FORK)
		e->fds[sock].time.tv_sec = tp->tv_sec + 42 / e->time;
	else if (e->fds[sock].cmd == CONNECT)
		e->fds[sock].time.tv_sec = tp->tv_sec;
	else
		e->fds[sock].time.tv_sec = tp->tv_sec + 7 / e->time;
	e->fds[sock].time.tv_usec = tp->tv_usec;
	return (0);
}

int					ft_check_cmd(t_env *e, int sock, char *str)
{
	int				i;
	struct timeval	tp;
	static char		cmd[12][12] = {"avance", "droite", "gauche",

	"voir", "inventaire", "prend",
	"pose", "expulse", "broadcast",
	"incantation", "fork",
	"connect_nr"};
	i = -1;
	gettimeofday(&tp, NULL);
	while (++i < E_CMD)
	{
		if (ft_linecmp(str, cmd[i]) == 0)
		{
			e->fds[sock].cmd = i;
			return (ft_time_cmd(e, sock, &tp));
		}
	}
	return (-1);
}
