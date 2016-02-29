/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 12:29:31 by erobert           #+#    #+#             */
/*   Updated: 2014/06/26 12:44:14 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "serveur.h"

static void			ft_check_food(t_env *e, int sock)
{
	if (e->fds[sock].resource[FOOD] == 0)
	{
		ft_putendl_fd("mort", sock);
		ft_putstr_fd("pdi ", e->gfx);
		ft_putnbr_fd(sock, e->gfx);
		ft_putendl_fd("", e->gfx);
		ft_sock_close(e, sock);
		return ;
	}
	e->fds[sock].resource[FOOD]--;
	e->fds[sock].hp.tv_sec += 126 / e->time;
}

void				ft_check_death(t_env *e)
{
	int				i;
	struct timeval	tp;

	i = -1;
	while (++i < e->mfds)
	{
		if (e->fds[i].type == PLAYER)
		{
			gettimeofday(&tp, NULL);
			if (tp.tv_sec > e->fds[i].hp.tv_sec)
				ft_check_food(e, i);
			else if (tp.tv_sec == e->fds[i].hp.tv_sec)
			{
				if (tp.tv_usec >= e->fds[i].hp.tv_usec)
					ft_check_food(e, i);
			}
		}
	}
}
