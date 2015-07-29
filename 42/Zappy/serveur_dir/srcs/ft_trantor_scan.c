/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trantor_scan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 14:19:04 by erobert           #+#    #+#             */
/*   Updated: 2015/06/09 15:03:13 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void	ft_right_scan(t_env *e, int *pos, int level, int sock)
{
	int		*resrc;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i++ < level)
	{
		tmp = (pos[0] + 1) % e->width;
		j = pos[1] - i - 1;
		while (j++ < pos[1] + i)
		{
			ft_putstr_fd(", ", sock);
			resrc = e->trantor[tmp][j % e->height].resource;
			ft_putstr_fd(ft_celltoa(resrc), sock);
		}
	}
}

static void	ft_up_scan(t_env *e, int *pos, int level, int sock)
{
	int		*resrc;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i++ < level)
	{
		tmp = (pos[1] + 1) % e->height;
		j = pos[0] - i - 1;
		while (j++ < pos[0] + i)
		{
			ft_putstr_fd(", ", sock);
			resrc = e->trantor[j % e->width][tmp].resource;
			ft_putstr_fd(ft_celltoa(resrc), sock);
		}
	}
}

static void	ft_left_scan(t_env *e, int *pos, int level, int sock)
{
	int		*resrc;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i++ < level)
	{
		tmp = (pos[0] == 0 ? e->width - 1 : pos[0] - 1);
		j = pos[1] - i - 1;
		while (j++ < pos[1] + i)
		{
			ft_putstr_fd(", ", sock);
			resrc = e->trantor[tmp][j % e->height].resource;
			ft_putstr_fd(ft_celltoa(resrc), sock);
		}
	}
}

static void	ft_down_scan(t_env *e, int *pos, int level, int sock)
{
	int		*resrc;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i++ < level)
	{
		tmp = (pos[1] == 0 ? e->height - 1 : pos[1] - 1);
		j = pos[0] - i - 1;
		while (j++ < pos[0] + i)
		{
			ft_putstr_fd(", ", sock);
			resrc = e->trantor[j % e->width][tmp].resource;
			ft_putstr_fd(ft_celltoa(resrc), sock);
		}
	}
}

void		ft_trantor_scan(t_env *e, int sock)
{
	int		*pos;
	int		*resrc;

	ft_putstr_fd("{", sock);
	pos = e->fds[sock].pos;
	resrc = e->trantor[pos[0]][pos[1]].resource;
	resrc[PLAY]--;
	ft_putstr_fd(ft_celltoa(resrc), sock);
	resrc[PLAY]++;
	if (e->fds[sock].dir == 1)
		ft_right_scan(e, pos, e->fds[sock].level - '0', sock);
	else if (e->fds[sock].dir == 0)
		ft_up_scan(e, pos, e->fds[sock].level - '0', sock);
	else if (e->fds[sock].dir == 3)
		ft_left_scan(e, pos, e->fds[sock].level - '0', sock);
	else
		ft_down_scan(e, pos, e->fds[sock].level - '0', sock);
	ft_putendl_fd("}", sock);
}
