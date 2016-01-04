/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 03:29:03 by erobert           #+#    #+#             */
/*   Updated: 2014/06/26 17:09:52 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static int	ft_isobject(char *str)
{
	if (ft_linecmp("nourriture", str) == 0)
		return (FOOD);
	if (ft_linecmp("deraumere", str) == 0)
		return (DERA);
	if (ft_linecmp("sibur", str) == 0)
		return (SIBU);
	if (ft_linecmp("mendiane", str) == 0)
		return (MEND);
	if (ft_linecmp("phiras", str) == 0)
		return (PHIR);
	if (ft_linecmp("thystame", str) == 0)
		return (THYS);
	return (-1);
}

static int	ft_action_take(t_env *e, int sock, char *av)
{
	int		object;
	t_fd	*fd;

	object = ft_isobject(av);
	if (object == -1)
		return (-1);
	fd = &e->fds[sock];
	if (e->trantor[fd->pos[0]][fd->pos[1]].resource[object] < 1)
		return (-1);
	e->trantor[fd->pos[0]][fd->pos[1]].resource[object]--;
	if (object == FOOD)
		e->trantor[rand() % e->width][rand() % e->height].resource[object]--;
	fd->resource[object]++;
	ft_putstr_fd("pgt ", e->gfx);
	ft_putnbr_fd(sock, e->gfx);
	ft_putstr_fd(" ", e->gfx);
	ft_putnbr_fd(object, e->gfx);
	ft_putendl_fd("", e->gfx);
	ft_putpin_fd(e, sock, e->gfx);
	ft_putbct_fd(e, fd->pos[0], fd->pos[1], e->gfx);
	return (1);
}

static int	ft_action_put(t_env *e, int sock, char *av)
{
	int		object;
	t_fd	*fd;

	object = ft_isobject(av);
	if (object == -1)
		return (-1);
	fd = &e->fds[sock];
	if (fd->resource[object] < 1)
		return (-1);
	fd->resource[object]--;
	e->trantor[fd->pos[0]][fd->pos[1]].resource[object]++;
	ft_putstr_fd("pdr ", e->gfx);
	ft_putnbr_fd(sock, e->gfx);
	ft_putstr_fd(" ", e->gfx);
	ft_putnbr_fd(object, e->gfx);
	ft_putendl_fd("", e->gfx);
	ft_putpin_fd(e, sock, e->gfx);
	ft_putbct_fd(e, fd->pos[0], fd->pos[1], e->gfx);
	return (1);
}

int			ft_action_object(t_env *e, int sock, t_cmd cmd, char *av)
{
	if (cmd == SCAN)
		ft_trantor_scan(e, sock);
	else if (cmd == INVENTORY)
		ft_putendl_fd(ft_invtoa(e->fds[sock].resource), sock);
	else if (cmd == TAKE)
		return (ft_action_take(e, sock, av));
	else if (cmd == PUT)
		return (ft_action_put(e, sock, av));
	return (0);
}
