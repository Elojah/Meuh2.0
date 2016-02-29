/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 03:31:10 by erobert           #+#    #+#             */
/*   Updated: 2015/06/11 18:50:01 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int	ft_check_players(t_env *e, char level)
{
	int		nb;
	int		i;

	nb = 0;
	i = -1;
	while (++i < e->mfds)
	{
		if (e->fds[i].type == PLAYER && e->fds[i].level == level)
			nb++;
	}
	if (nb < 6 && level > '5')
		return (-1);
	if (nb < 4 && level > '3')
		return (-1);
	if (nb < 2 && level > '1')
		return (-1);
	return (0);
}

int			ft_action_special(t_env *e, int sock, t_cmd cmd)
{
	if (cmd == INCANTATION)
	{
		if (ft_check_resource(&e->fds[sock], e->trantor))
			return (-1);
		if (ft_check_players(e, e->fds[sock].level))
			return (-1);
		ft_putstr_fd("niveau actuel : ", sock);
		ft_putendl_fd(&e->fds[sock].level, sock);
		return (0);
	}
	else if (cmd == FORK)
	{
		ft_putenw_fd(e, sock, e->gfx);
		return (0);
	}
	else if (cmd == CONNECT)
	{
		ft_putendl_fd(ft_itoa(e->client_nb[e->fds[sock].team_number]), sock);
		return (1);
	}
	return (0);
}
