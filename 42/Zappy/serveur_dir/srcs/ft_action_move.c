/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 03:27:23 by erobert           #+#    #+#             */
/*   Updated: 2014/06/23 12:31:33 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int	ft_action_advance(t_env *e, int sock, int *pos, int dir)
{
	e->trantor[pos[0]][pos[1]].resource[PLAY]--;
	if (dir == 0)
		pos[1] = (pos[1] + 1) % e->height;
	else if (dir == 1)
		pos[0] = (pos[0] + 1) % e->width;
	else if (dir == 2)
		pos[1] = (pos[1] == 0 ? e->height - 1 : pos[1] - 1);
	else
		pos[0] = (pos[0] == 0 ? e->width - 1 : pos[0] - 1);
	e->trantor[pos[0]][pos[1]].resource[PLAY]++;
	ft_putppo_fd(e, sock, e->gfx);
	return (1);
}

static int	ft_action_expulse(t_env *e, int sock)
{
	t_fd	*fd;
	int		pos[2];
	int		ok;
	int		i;

	pos[0] = e->fds[sock].pos[0];
	pos[1] = e->fds[sock].pos[1];
	ok = 0;
	i = -1;
	while (++i < e->mfds)
	{
		fd = &e->fds[i];
		if (i != sock && fd->pos[0] == pos[0] && fd->pos[1] == pos[1])
		{
			if (i == PLAYER && (ok = 1))
				ft_action_advance(e, sock, e->fds[sock].pos, e->fds[sock].dir);
		}
	}
	if (ok)
		return (1);
	return (-1);
}

int			ft_action_move(t_env *e, int sock, t_cmd cmd)
{
	if (cmd == ADVANCE)
		return (ft_action_advance(e, sock, e->fds[sock].pos, e->fds[sock].dir));
	if (cmd == RIGHT)
	{
		e->fds[sock].dir = (e->fds[sock].dir + 1) % 4;
		ft_putppo_fd(e, sock, e->gfx);
		return (1);
	}
	if (cmd == LEFT)
	{
		e->fds[sock].dir = (e->fds[sock].dir == 0 ? 3 : e->fds[sock].dir - 1);
		ft_putppo_fd(e, sock, e->gfx);
		return (1);
	}
	if (cmd == EXPEL)
	{
		ft_putstr_fd("pex ", e->gfx);
		ft_putnbr_fd(sock, e->gfx);
		ft_putendl_fd("", e->gfx);
		return (ft_action_expulse(e, sock));
	}
	return (0);
}
